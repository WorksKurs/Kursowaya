#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void Menu () {
    char code, garbage;
    system ("clear");
    printf ("\n\n%56s", "Игра 'Жизнь'\n\n\n");
    printf ("%30s %s", " ", "1. Начать игру\n");
    printf ("%30s %s", " ", "2. Выход\n");
    scanf ("%c", &code);
    scanf ("%c", &garbage);
    switch (code) {
        case 49: MenuGame (); break;
        case 50: break;
    }
}

void MenuGame () {
    char code, garbage;
    system ("clear");
    printf ("\n\n%56s", "Игра 'Жизнь'\n\n\n");
    printf ("%30s %s", " ", "1. Стандартное поле\n");
    printf ("%30s %s", " ", "2. Задать поле\n");
    printf ("%30s %s", " ", "3. Назад\n");
    scanf ("%c", &code);
    scanf ("%c", &garbage);
    switch (code) {
        case 49: MenuStandart (); break;
        case 50: MenuInput (); break;
        case 51: Menu ();
    }
}

void MenuStandart () {
    char code, garbage;
    system ("clear");
    printf ("\n\n%56s", "Игра 'Жизнь'\n\n\n");
    printf ("%30s %s", " ", "1. Поле 5х5\n");
    printf ("%30s %s", " ", "2. Поле 10х10\n");
    printf ("%30s %s", " ", "3. Поле 15х15\n");
    printf ("%30s %s", " ", "4. Поле 20х20\n");
    printf ("%30s %s", " ", "5. Назад\n");
    scanf ("%c", &code);
    scanf ("%c", &garbage);
    switch (code) {
        case 49: Game (5, 5); break;
        case 50: Game (10, 10); break;
        case 51: Game (15, 15); break;
        case 52: Game (20, 20); break;
        case 53: MenuGame ();
    }
}

void MenuInput () {
    char garbage;
    int sizex=1, sizey=1;
    system ("clear");
    printf ("\n\n%56s", "Игра 'Жизнь'\n\n\n");
    printf ("%30s %s", " ", "0. Назад\n");
    printf ("%30s %s", " ", "Введите высоту поля(5-25): ");
    while (sizey<5 || sizey>25) {
        scanf ("%d", &sizey);
        if (sizey==0) break;
        if (sizey<5 || sizey>25) printf ("%30s %s", " ", "Неверный размер! Введите заново: ");
    }
    if (sizey!=0) printf ("\n%30s %s", " ", "Введите ширину поля(5-25): ");
    while ((sizex<5 || sizex>25) && sizey!=0) {
        scanf ("%d", &sizex);
        if (sizex==0) break;
        if (sizex<5 || sizex>25) printf ("%30s %s", " ", "Неверный размер! Введите заново: ");
    }
    scanf ("%c", &garbage);
    if (sizey!=0 && sizex!=0) Game (sizex, sizey);
    else MenuGame ();
}
