//
// Created by Rohit Khattar on 2019-01-22.
//


#include <iostream>

int main() {


    float epsilon = 0.1, temp = 0.0;
    int itrCount = 0, rows = 1024, columns = 1024;



    std::cout.write(reinterpret_cast<char const *>(&itrCount), sizeof itrCount);
    std::cout.write(reinterpret_cast<char const *>(&epsilon), sizeof epsilon);
    std::cout.write(reinterpret_cast<char const *>(&rows), sizeof rows);
    std::cout.write(reinterpret_cast<char const *>(&columns), sizeof columns);


    //Init float Array

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            if(j==0 || k == 0 || j == 1023 || k ==1023){
                temp=0.0;
            } else {
                temp=50.0;
            }
            std::cout.write(reinterpret_cast<char const *>(&temp), sizeof(float));
        }
    }



    return 0;

}