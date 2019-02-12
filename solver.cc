//
// Created by Rohit Khattar on 2019-02-08.
//

#include <iostream>
#include <math.h>
#include <fstream>


int main(){

    float epsilon, temp=0.0;
    int itrCount, rows , columns;

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

    float** temp_array = new float*[rows];
    for(int i = 0; i < rows; i++)
        temp_array[i] = new float[columns];

    //Init float Array

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            std::cin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
            main_array[j][k] = temp;
        }
    }

    bool found = false, stable_flag = true;

    while (!found){


        //Check current i if It's stable

        for (int j=1;j<rows-1;j++){
            for(int k=1;k<columns-1;k++){
                float array_avg = (main_array[j-1][k] + main_array[j][k-1] + main_array[j][k+1] + main_array[j+1][k])/ 4;
                float array_diff =  fabs (array_avg - main_array[j][k]);
                if( array_diff >= epsilon ){
                    //Bad one found. Not stable
                    stable_flag = false;
                    break;
                }
            }
        }

        if(stable_flag){
            break;
        }
        else {

            itrCount = itrCount + 1;

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


            //Reset stable flag
            stable_flag = true;

        }
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

    for(int i = 0; i < rows; i++)
        delete [] temp_array[i];
    delete [] temp_array;


    return 0;
}