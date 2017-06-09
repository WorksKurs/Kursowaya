#include <stdio.h>
#include <stdlib.h>

void Menu () {
    char code;
    system ("clear");
    printf ("\n\n%56s", "Игра 'Жизнь'\n\n\n");
    printf ("%30s %s", " ", "1. Начать игру\n");
    printf ("%30s %s", " ", "2. Выход\n");
    scanf ("%c", &code);
    switch (code) {
        case 49: printf ("WIN");
        case 50: break;
    }
}
