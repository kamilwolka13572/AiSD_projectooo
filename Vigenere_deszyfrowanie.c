#include "Vigenere_deszyfrowanie.h"

#include<stdio.h>

#include <math.h>

void Vigenere_deszyfrowanie()
{
    FILE *in, *out;
    int i=0, licznik=0;
    int tablica_ASCII[10000]= {};      //Ta tablica przechowuje litery odpowiadajace haslu.
    char znak=0;                       //Znak odczytywany z podanego pliku do szyfrowania.
    char haslo[10000]={};              //Tablica sluzy do przechowania hasla podanego przez uzytkownika.
    char plik_odszyfrowany[10000]={};  //Nazwa pliku, w ktorym zapisany jest odszyfrowany plik.
    char plik_zaszyfrowany[10000]={};  //Nazwa pliku, w ktorym bedzie zaszyfrowany tekst.
    for (i=0; i<10000; i++)            //Ta petla umozliwia wypelnienie tablicy pustymi znakami
        haslo[i]=42;

    printf("Podaj nazwe pliku, ktorego tresc ma zostac odszyfrowana (z rozszerzeniem!): " );
    scanf("%s", plik_zaszyfrowany);
    printf("Podaj nazwe pliku wynikowego (z rozszerzeniem!): ");
    scanf("%s", plik_odszyfrowany);
    printf("Podaj haslo (tylko duze litery, bez spacji  bez znakow specjalnych\n HASLO MUSI BYC TAKIE SAMO JAK PODCZAS SZYFROWANIA PLIKU!!!): ");
    scanf("%s", haslo);

    int pozycja=0;
    for (i=0; i<10000; i++)
        if (haslo[pozycja]!=42)
        {
            tablica_ASCII[i]=haslo[pozycja];      //Pod znaki z tablicy jest podstawiane haslo, zgodnie z zasada szyfrowania vigener'a.
            pozycja++;
        }
        else
        {
            pozycja=0;                           //Haslo wczytywane od poczatku, gdy jest za krotkie, by 'podstawic sie' pod tekst.
            i--;
            tablica_ASCII[i]=haslo[pozycja];
            pozycja++;
        }

    for (i=0; i<10000; i++)                       //Operacja, dzieki ktorej wiadomo o ile 'zmienic' (teskst do szyfrowania).
        tablica_ASCII[i]-=65;


    licznik=0;

    if((in=fopen(plik_zaszyfrowany,"r"))!=NULL)       //Otwieranie pliku do odszyfrowania.
    {
        if((out=fopen(plik_odszyfrowany,"w"))!=NULL) //Tworzenie pliku z odszyfrowanym tesktem.
        {
            while((znak=getc(in))!=EOF)              //Kazda litera jest pobierana, az program nie natrafi na znak konca pliku.
            {                                        //Znaki sa rozdzielane na male, badz wielkie litery.
                if ((znak>=65)&&(znak<=90))
                {
                    znak-=65;
                    znak-=tablica_ASCII[licznik];     //Operacja powodujaca przesuniecie zgodnie z teskstem i haslem (deszyfrowanie).
                    if(licznik==10000)
                        licznik=0;
                    else
                        licznik++;
                    if (znak<0)
                        znak=26-fabs(znak);          //Tutaj i ponizej sa operacje szyfrowania dzialajaca zgodnie z zasada szyfru Vigener'a. Funckja fabs sluzy zamiany wartosci ujemnych na dodatnie (wartosc bezwzgledna)
                    znak+=65;
                    putc(znak,out);
                }
                else if ((znak>=97)&&(znak<=122))
                {
                    znak-=97;
                    znak-=tablica_ASCII[licznik];    //Tutaj i ponizej sa operacje szyfrowania dzialajaca zgodnie z zasada szyfru Vigener'a.
                    if(licznik==10000)
                        licznik=0;
                    else
                        licznik++;
                    if (znak<0)
                        znak=26-fabs(znak);            //Tutaj i ponizej sa operacje szyfrowania dzialajaca zgodnie z zasada szyfru Vigener'a.
                    znak+=97;
                    putc(znak,out);
                }
            }

            fclose(out);
        }
        fclose(in);
    }
    printf("Deszyfrowanie zostalo zakonczone");
    return;
}
