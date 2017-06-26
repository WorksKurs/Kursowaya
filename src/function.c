#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int randoms (int N) { return rand()%N; }

char ComparisonOfGenerations (char mass[], char pass1[], char pass2[], int sizex, int sizey) {
    char i, j, difference1=0, difference2=0;
    for (i=1; i<sizey-1 && (difference1==0 || difference2==0); i++)
        for (j=1; j<sizex-1 && (difference1==0 || difference2==0); j++) {
            if (pass2[i*sizex+j]!=mass[i*sizex+j]) difference2++;
            if (pass1[i*sizex+j]!=mass[i*sizex+j]) difference1++;
        }
    if (difference1==0 || difference2==0) return 0;
    else return 1;
}

void FillNull (char mass[], int sizex, int sizey) {
    int i, j;
    for (i=0; i<sizey; i++) {
        for (j=0; j<sizex; j++) {
            mass[i*sizex+j]=0;
        }
    }
}

void FillOne (char mass[], int sizex, int sizey) {
    int i, j;
    for (i=0; i<sizey; i++) {
        for (j=0; j<sizex; j++) {
            mass[i*sizex+j]=1;
        }
    }
}

void FillRand (char mass[], int sizex, int sizey) {
    int i, j;
    srand(time(NULL));
    for (i=1; i<sizey-1; i++) {
        for (j=1; j<sizex-1; j++) {
            mass[i*sizex+j]=randoms(2);
        }
    }
}

void Display (char mass[], int sizex, int sizey, int *alive) {
    char i, j;
    for (i=1; i<sizey-1; i++) {
        for (j=1; j<sizex-1; j++) {
            if (mass[i*sizex+j]==1) {
                (*alive)++;
                printf ("|+|");
            }
            else printf ("| |");
        }
        printf ("\n");
    }
}

void FirstGeneration (char mass[], int sizex, int sizey, int *alive) {
    char k=0, code, garbage;
    while (k==0) {
        FillRand (mass, sizex, sizey);
        Display (mass, sizex, sizey, alive);
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
}

void DelayTime (int *time) {
    while (*time<0) {
        printf ("\n\n%15s %s", " ", "Введите время задержки между поколениями (в секундах):\n");
        scanf ("%d", time);
    }
}
void Neighbors (char mass[], char step[], int sizex, int sizey) {
    char i, j, neighbors;
    for (i=1; i<sizey-1; i++) {
        for (j=1; j<sizex-1; j++) {
            neighbors=0;
            neighbors+=mass[(i-1)*sizex+j-1]+mass[(i-1)*sizex+j]+mass[(i-1)*sizex+j+1];
            neighbors+=mass[i*sizex+j-1]+mass[i*sizex+j+1];
            neighbors+=mass[(i+1)*sizex+j-1]+mass[(i+1)*sizex+j]+mass[(i+1)*sizex+j+1];
            step[i*sizex+j]=neighbors;
        }
    }
}

void NewGeneration (char mass[], char step[], char pass1[], char pass2[], int sizex, int sizey) {
    char i, j;
    for (i=1; i<sizey-1; i++)
        for (j=1; j<sizex-1; j++) {
            pass2[i*sizex+j]=pass1[i*sizex+j];
            pass1[i*sizex+j]=mass[i*sizex+j];
            if (mass[i*sizex+j]==0 && step[i*sizex+j]==3) mass[i*sizex+j]=1;
            if (mass[i*sizex+j]==1 && step[i*sizex+j]!=2 && step[i*sizex+j]!=3) mass[i*sizex+j]=0;
        }
}

void Game (int sizex, int sizey) {
    system ("clear");
    char difference=1;
    int alive=1, gen=0, time=-1;
    sizex+=2;
    sizey+=2;
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    FillNull (mass, sizex, sizey);
    FillNull (step, sizex, sizey);
    FillNull (pass1, sizex, sizey);
    FillNull (pass2, sizex, sizey);
    FirstGeneration (mass, sizex, sizey, &alive);
    DelayTime (&time);
    system ("clear");
    while (alive!=0 && difference!=0) {
        difference=0;
        alive=0;
        gen++;
        difference=ComparisonOfGenerations (mass, pass1, pass2, sizex, sizey);
        Display (mass, sizex, sizey, &alive);
        Neighbors (mass, step, sizex, sizey);
        NewGeneration (mass, step, pass1, pass2, sizex, sizey);
        sleep (time);
        printf ("\n");
    }
    if (alive==0) printf ("Все клетки погибли. Жизнь существовала %d поколения(ий).\n", gen-1);
    if (difference==0) printf ("Жизнь зациклена и бесконечна! Это произошло на %d поколении.\n", gen);
}
