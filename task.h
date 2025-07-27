#include <stdbool.h>

typedef struct{
    char *title;
    int *completion;
    bool status;
}task;

#define complete true
#define pending  false

void printtask(task a);