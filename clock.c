#include<stdio.h>
#include <time.h>
#include <windows.h>

void clsn(void){
    system("cls");
}

int main(void){
    while(1){
        time_t rwtime;
        struct tm *timeinfo;
        time(&rwtime);
        timeinfo = localtime(&rwtime);
        clsn();
        printf("Current Time: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        Sleep(1000);
    }
    return 0;
}
