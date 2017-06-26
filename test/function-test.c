#include <ctest.h>
#include <function.h>
#include <function.c>

const int sizex=5+2, sizey=5+2;
int alive;

CTEST(Neighbors, all_live) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=8, result;
    FillNull (mass, sizex, sizey);
    FillOne (mass, sizex, sizey);
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, all_dead) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, diagonals_live) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=4, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=mass[4*sizex+4]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, cross_live) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=4, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+3]=mass[3*sizex+2]=mass[3*sizex+4]=mass[4*sizex+3]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, vertical_live) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=2, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+3]=mass[4*sizex+3]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, vertical_dead) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=6, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=mass[4*sizex+4]=1;
    mass[3*sizex+2]=mass[3*sizex+4]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, horizontal_live) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=2, result;
    FillNull (mass, sizex, sizey);
    mass[3*sizex+2]=mass[3*sizex+4]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Neighbors, horizontal_dead) {
    char mass[sizex*sizey], step[sizex*sizey];
    char expected=6, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=mass[4*sizex+4]=1;
    mass[2*sizex+3]=mass[4*sizex+3]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    Neighbors (mass, step, sizex, sizey);
    result=step[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationDead, all_live) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    FillOne (mass, sizex, sizey);
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationDead, all_dead) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationDead, diagonals_live) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=mass[4*sizex+4]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationDead, diagonals_live_without_one) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=1, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationDead, cross_live) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+3]=mass[3*sizex+2]=mass[3*sizex+4]=mass[4*sizex+3]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationDead, cross_live_without_one) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=1, result;
    FillNull (mass, sizex, sizey);
    mass[2*sizex+3]=mass[3*sizex+2]=mass[3*sizex+4]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationLive, vertical_live) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=1, result;
    FillNull (mass, sizex, sizey);
    mass[3*sizex+3]=1;
    mass[2*sizex+3]=mass[4*sizex+3]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationLive, vertical_dead) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    mass[3*sizex+3]=1;
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=mass[4*sizex+4]=1;
    mass[3*sizex+2]=mass[3*sizex+4]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationLive, horizontal_live) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=1, result;
    FillNull (mass, sizex, sizey);
    mass[3*sizex+3]=1;
    mass[3*sizex+2]=mass[3*sizex+4]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(NewGenerationLive, horizontal_dead) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    mass[3*sizex+3]=1;
    mass[2*sizex+2]=mass[2*sizex+4]=mass[4*sizex+2]=mass[4*sizex+4]=1;
    mass[2*sizex+3]=mass[4*sizex+3]=1;
    Neighbors (mass, step, sizex, sizey);
    NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Life_Three_Steps, a_random_position_1) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=0, result;
    FillNull (mass, sizex, sizey);
    mass[1*sizex+2]=mass[1*sizex+3]=mass[1*sizex+4]=mass[1*sizex+5]=1;
    mass[2*sizex+1]=mass[2*sizex+3]=mass[2*sizex+4]=1;
    mass[3*sizex+2]=mass[3*sizex+4]=1;
    mass[4*sizex+3]=mass[4*sizex+4]=mass[4*sizex+5]=1;
    mass[5*sizex+1]=mass[5*sizex+4]=mass[5*sizex+5]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    for (result=0; result<3; result++) {
        Neighbors (mass, step, sizex, sizey);
        NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    }
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

CTEST(Life_Three_Steps, a_random_position_2) {
    char mass[sizex*sizey], step[sizex*sizey], pass1[sizex*sizey], pass2[sizex*sizey];
    char expected=1, result;
    FillNull (mass, sizex, sizey);
    mass[1*sizex+1]=mass[1*sizex+3]=1;
    mass[2*sizex+1]=mass[2*sizex+2]=mass[2*sizex+3]=mass[2*sizex+5]=1;
    mass[3*sizex+3]=1;
    mass[4*sizex+2]=mass[4*sizex+3]=mass[4*sizex+5]=1;
    mass[5*sizex+1]=mass[5*sizex+2]=mass[5*sizex+4]=mass[5*sizex+5]=1;
    printf ("\n");
    Display (mass, sizex, sizey, &alive);
    for (result=0; result<3; result++) {
        Neighbors (mass, step, sizex, sizey);
        NewGeneration (mass, step, pass1, pass2, sizex, sizey);
    }
    result=mass[3*sizex+3];
    ASSERT_EQUAL(expected, result);
}

