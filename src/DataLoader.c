//
// Created by Yilong Guo on 2019-06-19.
//

#include "DataLoader.h"

#include <stdio.h>

double TrainImages[TRAIN_SIZE][INPUT_SIZE];
int TrainLabels[TRAIN_SIZE];
double TestImages[TEST_SIZE][INPUT_SIZE];
int TestLabels[TEST_SIZE];
int tester = 0;

extern void LoadMNIST() {
    FILE *fptr1, *fptr2;

    if ((fptr1 = fopen(TRAIN_DATA_LOC, "r")) == NULL) {
        fprintf(stderr, "Error loading MNIST data file, please check the path spec. \n");
        return;
    }

    int i, j;
    for (i = 0; i < TRAIN_SIZE; ++i) {
        fscanf(fptr1, "%d", &TrainLabels[i]);

        for (j = 0; j < INPUT_SIZE; ++j) {
            fscanf(fptr1, "%lf", &TrainImages[i][j]);
        }
    }

    fclose(fptr1);

    if ((fptr2 = fopen(TEST_DATA_LOC, "r")) == NULL) {
        fprintf(stderr, "Error loading MNIST data file, please check the path spec. \n");
        return;
    }

    for (i = 0; i < TEST_SIZE; ++i) {
        fscanf(fptr2, "%d", &TestLabels[i]);

        for (j = 0; j < INPUT_SIZE; ++j) {
            fscanf(fptr2, "%lf", &TestImages[i][j]);
        }
    }

    fclose(fptr2);
}

extern void ShowMNIST() {
    fprintf(stdout, "$tester = %d\n", ++tester);
    
    int x, y;
    for (x = 0; x < 11; ++x) {
        for (y = 0; y < 11; ++y) {
            fprintf(stdout, "%lf ", TrainImages[tester][x*11 + y]);
        }

        fprintf(stdout, "\n");
    }
}
