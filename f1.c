#include <stdio.h>
#include "task.h"
typedef struct 
{
    int x;
    int y;
}p;

p add(p x,p y){
    p z;
    z.x = x.x+y.x;
    z.y = x.y + y.y;
    return z;
}

void inputtask(void){
    
}

int main(void){
    task x;
    FILE *fp;

    fp = fopen("F.txt","w");
    if(fp == NULL){
        return 1;
    }

    fclose(fp);
    return 0;
}