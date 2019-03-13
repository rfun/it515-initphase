//
// Created by Rohit Khattar on 2019-02-12.
//

#include <iostream>
#include "functions.h"
#include "math.h"


bool isGridStable(float **main_array, int rows, int columns, float epsilon) {
    bool stable = true;

    #pragma omp parallel for
    for (int j=1;j<rows-1;j++){
        for(int k=1;k<columns-1;k++){
            float array_avg = (main_array[j-1][k] + main_array[j][k-1] + main_array[j][k+1] + main_array[j+1][k])/ 4;
            float array_diff =  fabs (array_avg - main_array[j][k]);
            if( array_diff >= epsilon ){
                //Bad one found. Not stable
                stable = false;
                break;
            }
        }
    }

    return stable;
}

void getNextStep(float **main_array, int rows, int columns){

    float** temp_array = new float*[rows];
    for(int i = 0; i < rows; i++)
        temp_array[i] = new float[columns];

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            temp_array[j][k] = main_array[j][k];
        }
    }


    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            if(j >= 1 && j<rows-1 && k>=1 && k < columns-1){
                float array_avg = (temp_array[j-1][k] + temp_array[j][k-1] + temp_array[j][k+1] + temp_array[j+1][k])/ 4;
                main_array[j][k] = array_avg;
            } else {
                main_array[j][k] = temp_array[j][k];
            }
        }
    }

    for(int i = 0; i < rows; i++)
        delete [] temp_array[i];
    delete [] temp_array;
}

void writeToFile(float **main_array, int rows, int columns, float epsilon, int itrCount){

    float temp;

    std::cout.write(reinterpret_cast<char const *>(&itrCount), sizeof (int));
    std::cout.write(reinterpret_cast<char const *>(&epsilon), sizeof (float));
    std::cout.write(reinterpret_cast<char const *>(&rows), sizeof (int));
    std::cout.write(reinterpret_cast<char const *>(&columns), sizeof (int));

    //Init float Array

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            temp = main_array[j][k];
            std::cout.write(reinterpret_cast<char const *>(&temp), sizeof(float));
        }
    }


}
