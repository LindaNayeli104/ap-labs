
void mergesort(void *lineptr[], int left, int right, int (*comp)(void *, void *)) {
	if (left < right) {
        int middlePoint = left + (right - left) / 2;
        mergesort(lineptr, left, middlePoint, comp);
        mergesort(lineptr, middlePoint + 1, right, comp);
        merge(lineptr, left, middlePoint, right, comp);
    }
}


void merge(void *arr[], int left, int middlePoint, int right, int (*comp)(void *, void *))
{
    int i,j,k;
    int part1 = middlePoint - left + 1;
    int part2 = right - middlePoint;
  
    void * leftArray[part1], *rightArray[part2];
 
    for (i = 0; i < part1; i++)
        leftArray[i] = arr[left + i];
    for (j = 0; j < part2; j++)
        rightArray[j] = arr[middlePoint + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < part1  && j < part2) {
        if ((comp)(leftArray[i], rightArray[j]) < 0) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
  
    while (i < part1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }
  
    while (j < part2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}