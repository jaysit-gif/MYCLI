#include <stdbool.h>

typedef struct{
    char *title;
    int *completion;
    bool status;
}task;

void printtask(task a);