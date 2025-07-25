#include "task.h"
#include <stdio.h>
void printarray(int *arr,int n){
    for(int i = 0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
void printtask(task a){
    puts(a.title);
    printarray(a.completion,3);
    printf("\n%d",a.status);
}