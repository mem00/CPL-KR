#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN 1
#define OUT 0


int main(){
    FILE *fp;
    char filename[100];
    int c, wc, nc, nl, state, space;
    char word[100];

    char *newline;

    wc = nc = nl = space = 0;

    state = OUT;
  
    printf("Enter filename please: ");
    fgets(filename, 100, stdin);
    // printf("%s", filename);

    newline = strchr(filename, '\n');
    if (newline) // ? is a newline present?
        *newline = '\0';

    printf("**%s**\n", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) { perror(filename); exit(1); };


     while((c=getc(fp)) != EOF){
        if(c == '\n'){
            nl++;
        }
     
        if(c == ' ' || c == '\n' || c == '\t' ){
            state = OUT;
            if(!space){
                printf(" ");
            }
            space = 1;       
        }
        else if(state == OUT){
            state = IN;
            space = 0;
            wc++;
        }

        if(!space){
            nc++;
            printf("%c", c);
        }
    }
 
    printf("\nCharacters: %d\nWords: %d\nLines: %d\n", nc, wc, nl);
    getchar();
    return 0;
}


