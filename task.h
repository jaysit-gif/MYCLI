#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char *title;
    int *completion;
    bool status;
}task;

#define complete true
#define pending  false

void printtask(task a);
char *inputline(void);
int *inputdate(int *arr);
bool completed(int a);
task inputtask(void);