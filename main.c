    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>

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
        scanf("%s",myword);

        FILE* dosya;
        dosya=fopen("words.txt","r");
        if(dosya==NULL) {
            printf("File could not be opened\n");
        }else {
            //dosyanın sonuna kadar oku
            while(fscanf(dosya, "%s", fileword) == 1) {
                //Girilen kelime dosyadakiyle aynı mı ?
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
            }
            fclose(dosya);
            //Hiç bir kelime olmuyorsa yani benzerlik oranı sıfırsa no matching yazdır
            if (max==0.0) {
                printf("no matching");
                return 0;
            }
            printf("did you mean? %s (%.2f)",x.bestword,max);
        }
        return 0;
    }


    float BenzerlikOranı(char word[],char myword[]) {
        int sinir;
        if (strlen(word)<strlen(myword)) {
            sinir=strlen(word);
        }else {
            sinir=strlen(myword);
        }
        float eslesenharf=0;
        for(int i=0;i<sinir;i++) {
            /*c de büyük küçük harfi farkı vardır
             o yüzden hepsini küçük harfe çevirmeliyiz*/
            if (tolower(myword[i])==tolower(word[i])) {
                eslesenharf++;
            }
        }
        return eslesenharf/strlen(word);
    }
