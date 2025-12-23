#include <stdio.h>

int main() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    char kelime[50];
    int sayac = 0;

    while (fscanf(fp, "%s", kelime) == 1) {
        sayac++;
    }

    fclose(fp);

    printf("Toplam kelime sayisi: %d\n", sayac);
    return 0;
}
