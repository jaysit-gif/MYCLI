#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


char *inputline(void){
    size_t buffer = 24;
    char *s = malloc(buffer);
    if(!buffer){
        perror("MEMORY ALLOCATION FAILED");
        return NULL;
    }

    char *line = NULL;
    size_t total_len = 0;
    while(fgets(s,buffer,stdin)){
        size_t len = strlen(s);
        total_len += len;

        if(!line){
            line = malloc(buffer + 1);
        }else{
            line = realloc(line,total_len+1);
        }
        if(!line){
            perror("MEMORY ALLOCATION FAILED");
            free(s);
            return NULL;
        }

        strcpy(line + total_len -len,s);

        if(s[len - 1]== '\n'){
            break;
        }

        buffer *= 2;
        s = realloc(s,buffer);
        if(!s){
            perror("MEMORY ALLOCATION FAILED");
            free(line);
            return NULL;
        }
    }
    free(s);
    return line;
}

int *inputdate(int *arr){
    for(int i = 0;i<3;i++){
        scanf("%d",&arr[i]);
    }
    return arr;
}

bool completed(int a){
    if(a = 1){
        return complete;
    }else if(a = 0){
        return pending;
    }
}