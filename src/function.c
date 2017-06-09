#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int randoms (int N) { return rand()%N; }

void FillNull (int mass[], int sizex, int sizey) {
    int i, j;
    for (i=0; i<sizex; i++) {
        for (j=0; j<sizey; j++) {
            mass[i*sizex+j]=0;
        }
    }
}

void FillRand (int mass[], int sizex, int sizey) {
    int i, j;
    srand(time(NULL));
    for (i=1; i<sizex-1; i++) {
        for (j=1; j<sizey-1; j++) {
            mass[i*sizex+j]=randoms(2);
        }
    }
}

void Game (int sizex, int sizey) {
    system ("clear");
    int i, j;
    sizex+=2;
    sizey+=2;
    int mass[sizex*sizey];
    FillNull (mass, sizex, sizey);
    FillRand (mass, sizex, sizey);
    sleep (1);
    for (i=1; i<sizey-1; i++) {
        for (j=1; j<sizex-1; j++) {
            if (mass[i*sizex+j]==0) printf ("|+|");
            else printf ("| |");
        }
        printf ("\n");
    }
}
