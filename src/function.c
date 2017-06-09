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
    int gen=0, i, j, neighbors, alive=1;
    sizex+=2;
    sizey+=2;
    int mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    FillNull (mass, sizex, sizey);
    FillNull (step, sizex, sizey);
    FillNull (pass1, sizex, sizey);
    FillNull (pass2, sizex, sizey);
    FillRand (mass, sizex, sizey);
    while (alive!=0) {
        alive=0;
        gen++;
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
                neighbors+=mass[(i-1)*sizey+j-1]+mass[(i-1)*sizey+j]+mass[(i-1)*sizey+j+1];
                neighbors+=mass[i*sizey+j-1]+mass[i*sizey+j+1];
                neighbors+=mass[(i+1)*sizey+j-1]+mass[(i+1)*sizey+j]+mass[(i+1)*sizey+j+1];
                step[i*sizey+j]=neighbors;
            }
        }
        for (i=1; i<sizey-1; i++) {
            for (j=1; j<sizex-1; j++) {
                if (mass[i*sizex+j]==0 && step[i*sizex+j]==3) mass[i*sizex+j]=1;
                if (mass[i*sizex+j]==1 && step[i*sizex+j]!=2 && step[i*sizex+j]!=3) mass[i*sizex+j]=0;
            }
        }
        sleep (0);
        printf ("\n");
    }
    printf ("Все клетки погибли. Жизнь существовала %d поколения(ий).\n", gen-1);
}
