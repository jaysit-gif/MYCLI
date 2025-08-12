#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char *title;
    size_t *completion;
    bool status;
}task;

#define complete true
#define pending  false

void printtask(task a);
char *inputline(void);
size_t *inputdate(size_t *arr);
bool completed(int a);
task inputtask(void);
void readtask(void);
void input(task t);