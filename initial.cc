//
// Created by Rohit Khattar on 2019-01-22.
//


#include <iostream>
#include "include/functions.h"

int main() {


    float epsilon = 0.1;
    int itrCount = 0, rows = 1024, columns = 1024;

    //Init float Array

    float** temp_array = new float*[rows];
    for(int i = 0; i < rows; i++)
        temp_array[i] = new float[columns];


    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            if(j==0 || k == 0 || j == (rows-1) || k ==(columns-1)){
                temp_array[j][k]=0.0;
            } else {
                temp_array[j][k]=50.0;
            }
        }
    }

    writeToFile(temp_array, rows, columns, epsilon, itrCount);

    for(int i = 0; i < rows; i++)
        delete [] temp_array[i];
    delete [] temp_array;


    return 0;

}