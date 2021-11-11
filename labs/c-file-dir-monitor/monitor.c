#define _XOPEN_SOURCE 500

#include <errno.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ftw.h>
#include <stdint.h>

int inotifyFd, wd, j;
char* filesFolders[200];
int *fileFoldersWd[200];
int fileFolder=0;
int ff=0;
char *currentSubDir;



void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}


static void displayInotifyEvent(struct inotify_event *i){ 
    bool isFile = true;

    if(strcmp(i->name, "") == 0){
        return;
    }

    if(i->mask & IN_MOVED_TO){

    }
    else if(i->mask & IN_ISDIR && strcmp(i->name, "") != 0){
        isFile = false;
        printf("- [Directory - ");
    }
    else if(isFile && strcmp(i->name, "") != 0){
        /* printf("wd = %i", wd);
        printf("wd = %s", i ->name); */
        printf("- [File - ");
    }


    if (i->mask & IN_CREATE)        printf("Create] - ");
    if (i->mask & IN_DELETE)        printf("Removal] - ");
    if (i->mask & IN_DELETE_SELF)   printf("IN_DELETE_SELF ");
    if (i->mask & IN_MOVED_FROM)    printf("Rename] - ");

    
    if (i->mask & IN_MOVED_TO && i -> wd > 1) {
        //printf("Entra 6 \n");
        printf(" -> ");

        int ff = 0;
        while(fileFoldersWd[ff] != i->wd){
            ff++;
        }

        printf("%s/%s\n", filesFolders[ff], i->name);
        
    }else if (i->mask & IN_MOVED_TO){
        //printf("Entra 6 \n");
        printf(" -> %s\n", i->name);
        
    }else if ( i->mask & IN_MOVED_FROM && i -> wd > 1){
        int ff = 0;
        while(fileFoldersWd[ff] != i->wd){
            ff++;
        }
        printf("%s/%s ", filesFolders[ff], i->name);
        
    }else if ( i->mask & IN_MOVED_FROM){
        //printf("Entra 7 \n");
        printf("%s", i->name);
        
    }else if (i->len > 0  && i -> wd > 1){
        int ff = 0;
        while(fileFoldersWd[ff] != i->wd){
            ff++;
        }
        printf("%s/%s\n", filesFolders[ff], i->name);
    }else{
        printf("%s\n", i->name);
    }     
}

//---------------------------------------------------------------------------------------------------- NFTW

static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf){
    
    if(ftwbuf->level == 0 | ftwbuf->level == 1){ 
        filesFolders[fileFolder] = malloc(strlen(fpath)+1);
        strcpy(filesFolders[fileFolder], fpath);
        fileFolder++;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------- Main

#define BUF_LEN (10 * (sizeof(struct inotify_event) + 32 + 1))

int
main(int argc, char *argv[]){
    int prevWD = 0;
    char buf[BUF_LEN] __attribute__ ((aligned(8)));
    ssize_t numRead;
    char *p;
    struct inotify_event *event;

    if (argc < 2 || strcmp(argv[1], "--help") == 0){
        printf("Por favor, ingrese el pathname a monitorear  \n");
	    return 1;
    }

//------------------------------------------------------- Generate array 
    
    int flags = 0;

    if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags) == -1) {
        perror("nftw");
        exit(EXIT_FAILURE);
    }

//-------------------------------------------------------

    inotifyFd = inotify_init();                
    if (inotifyFd == -1){
        printf("inotify_init");
    }
        
    while(filesFolders[ff]){
        wd = inotify_add_watch(inotifyFd, filesFolders[ff], IN_CREATE | IN_DELETE | IN_MOVED_FROM | IN_MOVED_TO);
        fileFoldersWd[ff] = wd;
        prevWD = wd;
        if (wd == -1){
            //printf("inotify_add_watch");
        }
        ff++;
    }
    
    printf("Starting File/Directory Monitor on %s \n", argv[1]);
    printf("----------------------------------------------------------------------------------------------------------------\n");
    

    for (;;) {  
        numRead = read(inotifyFd, buf, BUF_LEN);
       
        if (numRead == 0){
            printf("read() from inotify fd returned 0!");
        }    

        if (numRead == -1){
            printf("read");
        }

        for (p = buf; p < buf + numRead; ) {
            event = (struct inotify_event *) p;
            displayInotifyEvent(event);

            p += sizeof(struct inotify_event) + event->len;
        }


        if (nftw((argc < 2) ? "." : argv[1], display_info, 20, flags) == -1) {
            perror("nftw");
            exit(EXIT_FAILURE);
        }

        ff = 0;
        while(filesFolders[ff]){
            wd = inotify_add_watch(inotifyFd, filesFolders[ff], IN_CREATE | IN_DELETE | IN_MOVED_FROM | IN_MOVED_TO);           /* Si es directorio lo agrego al wd  fpath en lugar de argv[j]*/
            fileFoldersWd[ff] = (int*) malloc(sizeof(int)*20);
            fileFoldersWd[ff] = wd;

            if (wd == -1){
                //printf("inotify_add_watch 2");
            }
            ff++;
        }  

        
        prevWD = wd;
    }

    exit(EXIT_SUCCESS);
}