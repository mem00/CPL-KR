#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

    FILE *fp;
    int ws, ch, nc;

    int lengths[10];

    for(int i = 0; i < 10; i++){
        lengths[i] = 0;
    }

    ws = ch = nc = 0;

    char *newline;

    char filename[100];

    printf("Please enter file name: ");

    fgets(filename, 100, stdin);

    newline = strchr(filename, '\n');

    if(newline)
        *newline = '\0';

    fp = fopen(filename, "r");

    if(fp == NULL) {perror(filename); exit(1);};


    int tracker = 0;
    
    while((ch = getc(fp)) != EOF){
        
        if(ch == ' ' || ch == '\n' || ch == '\t') {
            if(!ws){
                lengths[tracker] = nc; 
                nc = 0;
                tracker++;
            }
            ws = 1;
        }
        else{
            nc++;
            ws = 0;
        }
    }

    int allzero = 1;

    do{
        allzero = 1;
        for(int i = 0; i < 10; i++){
            if(lengths[i]){
                allzero = 0;
                printf("* ");
                lengths[i]--;
            }   
        }
        printf("\n");
    }while(!allzero);

    getchar();
    return 0;
}