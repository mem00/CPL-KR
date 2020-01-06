#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME_MAX_LENGTH 100
#define NUM_CHARS 26

int main(){
    FILE *fp;
    
    int c;
    
    char filename[FILE_NAME_MAX_LENGTH];

    int chars[NUM_CHARS];

    for(int i = 0; i < NUM_CHARS; i++)
        chars[i] = 0;


    char *newline;

    printf("Please enter a filename: ");

    fgets(filename, FILE_NAME_MAX_LENGTH, stdin);

    newline = strchr(filename, '\n');

    if(newline)
        *newline = '\0';

    fp = fopen(filename, "r");

    if(fp == NULL){perror(filename); exit(1);}

    while((c=getc(fp))!= EOF){
        if(c >= 'a' && c<='z'){
            chars[c - 'a']++;     
        }
    }

    for(int i = 0; i < NUM_CHARS; i++){
        printf("%c: %d\n", (i+'a'), chars[i]);

    }


    getchar();
    return 0;

}