//
// Created by Rohit Khattar on 2019-02-08.
//

#include <iostream>
#include <math.h>
#include <fstream>
#include "include/functions.h"

int main(){

    float epsilon, temp=0.0;
    int itrCount, rows , columns;

//    std::ifstream in("/Users/student/Desktop/class/IT515/initPhase/myinitial.in");
//    std::cin.rdbuf(in.rdbuf());


    std::cin.read(reinterpret_cast<char *>(&itrCount), sizeof(itrCount));
    std::cin.read(reinterpret_cast<char *>(&epsilon), sizeof(epsilon));
    std::cin.read(reinterpret_cast<char *>(&rows), sizeof(rows));
    std::cin.read(reinterpret_cast<char *>(&columns), sizeof(columns));

    //Check input params

    if(rows <= 0 || columns <=0){
        std::cerr << "Invalid Size for initial matrix!\n";
        return 1;
    }

    if(epsilon <= 0){
        std::cerr << "Invalid Epsilon!\n";
        return 1;
    }

    //Create arrays

    float** main_array = new float*[rows];
    for(int i = 0; i < rows; i++)
        main_array[i] = new float[columns];

    //Init float Array

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            std::cin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
            main_array[j][k] = temp;
        }
    }

    bool found = false, stable_flag = true;

    while (!isGridStable(main_array, rows, columns, epsilon)){

        itrCount = itrCount + 1;
        getNextStep(main_array, rows, columns);

    }


    //Write out to the file

    std::cout.write(reinterpret_cast<char const *>(&itrCount), sizeof itrCount);
    std::cout.write(reinterpret_cast<char const *>(&epsilon), sizeof epsilon);
    std::cout.write(reinterpret_cast<char const *>(&rows), sizeof rows);
    std::cout.write(reinterpret_cast<char const *>(&columns), sizeof columns);

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            temp = main_array[j][k];
            std::cout.write(reinterpret_cast<char const *>(&temp), sizeof(float));
        }
    }


    //Clean Up memory

    for(int i = 0; i < rows; i++)
        delete [] main_array[i];
    delete [] main_array;


    return 0;
}