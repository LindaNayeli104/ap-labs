#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define REPORT_FILE "report.txt"

struct categoria {
    char* key;
    char* values[2500];
};

void analizeLog(char *logFile, char *report) {
    
    printf("Generating Report from: [%s] log file\n", logFile);

    //----------------------------------------------------------------------------------------
    FILE *inputFile  = fopen(logFile, "r");
        if (inputFile == NULL){   
            printf("Error! Could not open file\n"); 
            exit(-1);
        }

        struct categoria categorias [300];

        char linea[2000];

        categorias[0].key = (char*) malloc(sizeof("General:"));
        strcpy(categorias[0].key, "General:");

        int j=1;
        //----------------------------------------------------------------------------------- Inicia while
        while(!feof(inputFile)){
           
            fgets(linea, 2000, inputFile);
            if(strcmp(linea, "") != 0){

                char regPt1[2000];
                char categoriaNom[2000];
                char regPt2[2000];
                char temp[2000];

                strcpy(regPt1, "");
                strcpy(categoriaNom, "");
                strcpy(regPt2, "");
                strcpy(temp, "");
                
                int i = 0;
                while(i < strlen(linea) && linea[i] != ']'){
                    strncat(regPt1, &linea[i], 1);
                    i++;
                }
                
                if(i == strlen(linea)){
                    strcpy(categoriaNom, "General:");
                }else{
                    strncat(regPt1, &linea[i], 1);
                    bool isGeneral = true;

                    i++;
                    while(i < strlen(linea)-2){
                        if(linea[i] == ':' && linea[i+1] == ' '){
                            strncat(temp, &linea[i], 1);
                            i++;
                            isGeneral = false;                
                            break;
                        }
                        strncat(temp, &linea[i], 1);
                        i++;
                    }

                    if(isGeneral){
                        strcpy(categoriaNom, "General:");
                        strncat(temp, &linea[i], 1);
                        i++;
                        strcpy(regPt2, temp);
                    }else{
                        strcpy(categoriaNom, temp);
                        while(i < strlen(linea)){
                            strncat(regPt2, &linea[i], 1);   
                            i++;
                        }
                    }
                }

                char regCompleto[4000];
                strcpy(regCompleto, "");
                                              
                strncat(regCompleto, regPt1, strlen(regPt1)); 
                strncat(regCompleto, regPt2, strlen(regPt2)+1); 
              
                bool isNew = true;
               
                int m = 0;
                while(categorias[m].key != '\0' ){
                    if(strcmp(categorias[m].key, categoriaNom) == 0){
                        int k=0;
                        while(categorias[m].values[k] != '\0'){               
                            k++;
                        }
                        
                        categorias[m].values[k] = (char*) malloc(sizeof(regCompleto));
                        strcpy(categorias[m].values[k], regCompleto); 
                        
                        isNew = false;
                    }
                    m++;
                }
                
                if(isNew){

                    categorias[j].key = (char*) malloc(sizeof(categoriaNom));
                    strcpy(categorias[j].key, categoriaNom); 
            
                    categorias[j].values[0] = (char*) malloc(sizeof(regCompleto));
                    strcpy(categorias[j].values[0], regCompleto); 
              
                    j++;
                }
                strcpy(regPt1, "");
                strcpy(categoriaNom, "");
                strcpy(regPt2, "");
                strcpy(temp, "");
                strcpy(regCompleto, "");
            }
        }
        //----------------------------------------------------------------------------------- Termina while

    FILE *salida = fopen(REPORT_FILE, "w+");
      
    for(int a = 0; a < 2300; a++){
        if(categorias[a].key != '\0'){
            fprintf(salida, "%s \n",  categorias[a].key);
            for(int b = 0; b < 2296; b++){
                if(categorias[a].values[b] != '\0'){
                    fprintf(salida, "%s\n ",  categorias[a].values[b]);
                }else{
                    break;
                }
            }
        }else{
            break;
        }
    }

    fclose(salida);
    printf("categorias: %d", j);
    printf("Report is generated at: %s\n", report);
}

int main(int argc, char **argv) {

    if (argc < 2) {
	printf("Usage:./dmesg-analizer logfile.txt\n");
    printf("Por favor, ingrese el nombre del archivo de los logs \n");
	return 1;
    }

    analizeLog(argv[1], REPORT_FILE);

    return 0;
}