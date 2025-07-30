#include <stdio.h>
#include "task.h"

int main(void){
    task Task;
    FILE *f;
    Task = inputtask();
    f = fopen("DATA.txt","w");
    if(f == NULL){
        perror("FILE MEMORY ALLOCATION FAILED");
        return 1;
    }
    fprintf(f,"%s",Task.title);
    fprintf(f,"%d-%d-%d",Task.completion[0],Task.completion[1],Task.completion[2]);
    return 0;
}
