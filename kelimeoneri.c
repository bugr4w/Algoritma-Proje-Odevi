#include <ctype.h>
#include <stdio.h>
#include <string.h>

float benzerlik_orani(char *girilen,char *sozluk) {
    int benzerlik=0;
    int uz_girilen=strlen(girilen);
    int uz_sozluk=strlen(sozluk);

    int sinir;
    if (uz_girilen<uz_sozluk) {
        sinir=uz_girilen;
    } else {
        sinir=uz_sozluk;
    }
    for (int i=0;i<sinir;i++) {
        if (tolower(girilen[i])==tolower(sozluk[i])) {
            benzerlik++;
        }
    }
    return (float)benzerlik/uz_sozluk;
}

int main() {
    FILE *dosya;
    char girilenkelime[67];
    char sozlukkelime[67];
    char benzeyenkelime[67];
    float gecicioran=0.0;
    float eniyioran=0.0;

    printf("Bir kelime giriniz: ");
    scanf("%s", girilenkelime);

    dosya=fopen("words.txt","r");
    if (dosya==NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }
    while (fscanf(dosya,"%s",sozlukkelime)!=EOF) {
        gecicioran=benzerlik_orani(girilenkelime,sozlukkelime);
        if (gecicioran>eniyioran) {
            eniyioran=gecicioran;
            int j=0;
            while (sozlukkelime[j]!='\0') {
                benzeyenkelime[j]=sozlukkelime[j];
                j++;
            }
            benzeyenkelime[j]='\0';
        }
    }
    fclose(dosya);
    if (eniyioran>0.0) {
        printf("En benzer kelime: %s\n", benzeyenkelime);
        printf("Benzerlik orani: %.2f\n", eniyioran);
    } else {
        printf("Benzer kelime bulunamadi.\n");
    }
    return 0;
}