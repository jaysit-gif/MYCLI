#include <stdio.h>
#include "task.h"

int main(void){
    task Task;
    char *p = "MATH";
    Task.title = p;
    int a[3] = {11,12,2024};
    Task.completion = a;
    Task.status = true;
    printf("%d",sizeof(task));
    return 0;
}
