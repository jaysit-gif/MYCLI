#include <stdio.h>
#include "task.h"

int main(void){
    task Task;
    char *p = "MATH";
    Task.title = p;
    int a[3] = {11,12,2024};
    Task.completion = a;
    Task.status = true;
    printf("%d\n",sizeof(task));
    printf("%d\n",sizeof(Task));
    return 0;
}
