#include <stdio.h>
#include <string.h>
include <ctype.h>

float BenzerlikOranı(char word[],char myword[]);
struct bestwords {
    char bestword[50];
    float benzerlik;
};
int main(void) {
    struct bestwords x;
    char myword[50],fileword[50];
    float max=0.0;

    printf("search:");
    gets(myword);

    FILE* dosya;
    dosya=fopen("words.txt","r");
    if(dosya==NULL) {
        printf("File dosya.txt could not be opened\n");
    }else {
    }
    while(fscanf(dosya, "%s", fileword) == 1) {
        if (strcmp(myword,fileword)==0) {
            printf("The best word is %s\n",fileword);
            return 0;
        }else{
            x.benzerlik=BenzerlikOranı(fileword,myword);
            if(x.benzerlik>max) {
                max=x.benzerlik;
                strcpy(x.bestword,fileword);
            }

        }
    }if (max==0.0) {
        printf("no matching");
        return 0;
    }
    printf("did you mean?%s (%.2f)",x.bestword,max);
    return 0;
}


float BenzerlikOranı(char word[],char myword[]) {
    float eslesenharf=0;
    for(int i=0;i<strlen(myword);i++) {
        if (tolower(myword[i])==word[i]) {
            eslesenharf++;
        }
    }
    return eslesenharf/strlen(word);
}

