//
// Created by Rohit Khattar on 2019-02-12.
//

#ifndef INITPHASE_FUNCTIONS_H
#define INITPHASE_FUNCTIONS_H

bool isGridStable(float **main_array, int rows, int columns, float epsilon);
void getNextStep(float **main_array, int rows, int columns);

void writeToFile(float **main_array, int rows, int columns, float epsilon, int itrCount);

//1 or more tests that can identify if a grid is stable or unstable.
//1 or more tests that check if the next iteration of the grid was calculated correctly.
//1 or more tests that handle reading/writing the input/output.




#endif //INITPHASE_FUNCTIONS_H
