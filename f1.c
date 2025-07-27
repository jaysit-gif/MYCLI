#include <stdio.h>
#include "task.h"
#include <stdlib.h>
#include <string.h>


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

int main(void){
    task x;
    FILE *fp;
    printf("ENTER: ");
    x.title = inputline();
    fp = fopen("F.txt","w");
    if(fp == NULL){
        return 1;
    }
    fprintf(fp,"%s",x.title);
    fclose(fp);
    return 0;
}