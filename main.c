#include <stdio.h>
#include <stdlib.h>

#include "Vigenere_szyfrowanie.h"
#include "Vigenere_deszyfrowanie.h"

int main()
{
    int wybor=0, opcja=0;
    printf("Chcesz zaszyfrowac czy odszyfrowac? \n[1].Zaszyfrowac\n[2].Odszyfrowac\n");
    scanf("%d", &opcja);
    if(opcja==1){
    printf("Wybierz szyfr ktorego chcesz uzyc: \n[1].Cezara\n[2].Vigenere'a\n");
    scanf("%d", &wybor);
    if (wybor==1){
        printf("cezar");
    }
    if (wybor==2){
        Vigenere();
    }
    }
    if(opcja==2){
        printf("Wybierz szyfr ktorym chcesz odszyfrowac: \n[1].Cezara\n[2].Vigenere'a\n");
        scanf("%d", &wybor);
    if (wybor==1){
        printf("cezar");
    }
    if (wybor==2){
        Vigenere_deszyfrowanie();
    }
    }

}

