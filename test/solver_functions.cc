#include "../include/functions.h"
#include "catch/catch.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

TEST_CASE("Check if a grid is stable", "[test_solver]") {

    //Read stable grid from file. Grid was a result of a solver run

    std::ifstream in("../stable.out");
    std::cin.rdbuf(in.rdbuf());

    float epsilon, temp=0.0;
    int itrCount, rows , columns;

    std::cin.read(reinterpret_cast<char *>(&itrCount), sizeof(itrCount));
    std::cin.read(reinterpret_cast<char *>(&epsilon), sizeof(epsilon));
    std::cin.read(reinterpret_cast<char *>(&rows), sizeof(rows));
    std::cin.read(reinterpret_cast<char *>(&columns), sizeof(columns));


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

    REQUIRE(isGridStable(main_array,rows,columns,epsilon));
}

TEST_CASE("Check if next iteration was calculated accurately", "[test_solver]") {

    int rows = 4, columns = 4;

    float** main_array = new float*[rows];
    for(int i = 0; i < rows; i++)
        main_array[i] = new float[columns];

    for (int j=0;j<rows;j++){
        for(int k=0;k<columns;k++){
            if(j==0 || k == 0 || j == (rows-1) || k ==(columns-1)){
                main_array[j][k]=0.0;
            } else {
                main_array[j][k] = 50.0;
            }
        }
    }

    getNextStep(main_array,rows,columns);

    REQUIRE(main_array[1][1] == 25.0);
    REQUIRE(main_array[1][2] == 25.0);
    REQUIRE(main_array[2][1] == 25.0);
    REQUIRE(main_array[3][3] == 0.0);

}

TEST_CASE("Check if write to file works", "[test_solver]") {

    std::stringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());


    float epsilon = 1.2;
    int itrCount = 11, rows = 3, columns = 3;

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

    std::cout.rdbuf(p_cout_streambuf); // restore

    //Read from oss and see if we have the right data
    std::streambuf* p_cin_streambuf = std::cin.rdbuf();
    std::cin.rdbuf(oss.rdbuf());

    float read_epsilon, temp;
    int read_itrCount, read_rows, read_columns;

    std::cin.read(reinterpret_cast<char *>(&read_itrCount), sizeof(int));
    std::cin.read(reinterpret_cast<char *>(&read_epsilon), sizeof(float));
    std::cin.read(reinterpret_cast<char *>(&read_rows), sizeof(int));
    std::cin.read(reinterpret_cast<char *>(&read_columns), sizeof(int));

    std::cin.read(reinterpret_cast<char *>(&temp), sizeof(float));


    REQUIRE(temp == 0.0);
    REQUIRE(read_columns == columns);
    REQUIRE(read_epsilon == epsilon);
    REQUIRE(read_itrCount == itrCount);
    REQUIRE(read_rows == rows);




    std::cin.rdbuf(p_cin_streambuf); // restore


}

