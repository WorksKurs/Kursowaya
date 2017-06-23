#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int randoms (int N) { return rand()%N; }

void FillNull (int mass[], int sizex, int sizey) {
    int i, j;
    for (i=0; i<sizey; i++) {
        for (j=0; j<sizex; j++) {
            mass[i*sizex+j]=0;
        }
    }
}

void FillRand (int mass[], int sizex, int sizey) {
    int i, j;
    srand(time(NULL));
    for (i=1; i<sizey-1; i++) {
        for (j=1; j<sizex-1; j++) {
            mass[i*sizex+j]=randoms(2);
        }
    }
}

void Game (int sizex, int sizey) {
    system ("clear");
    int gen=0, i, j, k=0, neighbors, alive=1, difference1=1, difference2=1, time=0;
    char code, garbage;
    sizex+=2;
    sizey+=2;
    int mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    FillNull (mass, sizex, sizey);
    FillNull (step, sizex, sizey);
    FillNull (pass1, sizex, sizey);
    FillNull (pass2, sizex, sizey);
    while (k==0) {
        FillRand (mass, sizex, sizey);
        for (i=1; i<sizey-1; i++) {
            for (j=1; j<sizex-1; j++) {
                if (mass[i*sizex+j]==1) {
                    alive++;
                    printf ("|+|");
                }
                else printf ("| |");
            }
            printf ("\n");
        }
        printf ("\n\n%30s %s", " ", "Изменить первое поколение?\n");
        printf ("%30s %s", " ", "1. Да\n");
        printf ("%30s %s", " ", "2. Нет\n");
        scanf ("%c", &code);
        scanf ("%c", &garbage);
        switch (code) {
            case 49: break;
            case 50: k=1; break;
        }
        system ("clear");
    }
    printf ("\n\n%15s %s", " ", "Введите время задержки между поколениями (в секундах):\n");
    scanf ("%d", &time);
    system ("clear");
    while (alive!=0 && difference1!=0 && difference2!=0) {
        difference1=0;
        difference2=0;
        alive=0;
        gen++;
        for (i=1; i<sizey-1 && (difference1==0 || difference2==0); i++)
            for (j=1; j<sizex-1 && (difference1==0 || difference2==0); j++) {
                if (pass2[i*sizex+j]!=mass[i*sizex+j]) difference2++;
                if (pass1[i*sizex+j]!=mass[i*sizex+j]) difference1++;
            }
        for (i=1; i<sizey-1; i++) {
            for (j=1; j<sizex-1; j++) {
                if (mass[i*sizex+j]==1) {
                    alive++;
                    printf ("|+|");
                }
                else printf ("| |");
            }
            printf ("\n");
        }
        for (i=1; i<sizey-1; i++) {
            for (j=1; j<sizex-1; j++) {
                neighbors=0;
                neighbors+=mass[(i-1)*sizex+j-1]+mass[(i-1)*sizex+j]+mass[(i-1)*sizex+j+1];
                neighbors+=mass[i*sizex+j-1]+mass[i*sizex+j+1];
                neighbors+=mass[(i+1)*sizex+j-1]+mass[(i+1)*sizex+j]+mass[(i+1)*sizex+j+1];
                step[i*sizex+j]=neighbors;
            }
        }
        for (i=1; i<sizey-1; i++)
            for (j=1; j<sizex-1; j++) {
                pass2[i*sizex+j]=pass1[i*sizex+j];
                pass1[i*sizex+j]=mass[i*sizex+j];
                if (mass[i*sizex+j]==0 && step[i*sizex+j]==3) mass[i*sizex+j]=1;
                if (mass[i*sizex+j]==1 && step[i*sizex+j]!=2 && step[i*sizex+j]!=3) mass[i*sizex+j]=0;
            }
        sleep (time);
        printf ("\n");
    }
    if (alive==0)printf ("Все клетки погибли. Жизнь существовала %d поколения(ий).\n", gen-1);
    if (difference1==0 || difference2==0) printf ("Жизнь зациклена и бесконечна! Это произошло на %d поколении.\n", gen);
}
