#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printarray(size_t *arr,int n){
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

size_t *inputdate(size_t *arr){
    for(int i = 0;i<3;i++){
        scanf("%zu",&arr[i]);
    }
    if(arr[0] < 1 || arr[0] > 31 || arr[1] < 1 || arr[1] > 12 || arr[2] < 1970 || arr[2] > 2100){
        fprintf(stderr,"INVALID DATE\n\n");
        exit(1);
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

task inputtask(void){
    task t;
    t.completion = malloc(3*sizeof(size_t));
    if(!t.completion){
        perror("MEMORY ALLOCATION OF DATE FAILED");
        exit(1);
    }
    printf("TASK TITLE: ");
    t.title = inputline();
    printf("TASK COMPLETION DATE(DD/MM/YYYY): ");
    inputdate(t.completion);
    t.status = pending;
    return t;
}

void readtask(void){
    FILE *f;
    char s[256];
    f = fopen("DATA.txt","r");
    while(fgets(s,sizeof(s),f) != NULL){
        printf("%s",s);
    } 
}

void input(task t){
    FILE *fp;
    fp = fopen("DATA.txt","a+");
    if(fp == NULL){
        perror("File memory allocation Failed");
    }
    fprintf(fp,"%s",t.title);
    fprintf(fp,"%d-%d-%d\n",t.completion[0],t.completion[1],t.completion[2]);
    fprintf(fp,"%s\n\n",t.status==pending ? "PENDING":"COMPLETED");
}