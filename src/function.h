#ifndef GameLife
#define GameLife

void Menu ();
void MenuGame ();
void MenuStandart ();
void MenuInput ();
void Game (int sizex, int sizey);
void FillNull (char a[], int sizex, int sizey);
void FillRand (char a[], int sizex, int sizey);
void Display (char mass[], int sizex, int sizey, int *alive);
void FirstGeneration (char mass[], int sizex, int sizey, int *alive);
void DelayTime (int *time);
void Neighbors (char mass[], char step[], int sizex, int sizey);
void NewGeneration (char mass[], char step[], char pass1[], char pass2[], int sizex, int sizey);

char ComparisonOfGenerations (char mass[], char pass1[], char pass2[], int sizex, int sizey);
#endif
