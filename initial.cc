//
// Created by Rohit Khattar on 2019-01-22.
//

//Lot's of hard coded stuff in here but Need to template and use dynamic arrays in the next one

#include <iostream>
#include <math.h>


#define m 1024
#define n 1024

float main_array[m][n];
float temp_array[m][n];

float array_avg ( int y, int x)
{
    return (main_array[y-1][x] + main_array[y][x-1] + main_array[y][x+1] + main_array[y+1][x])/ 4 ;
}


float array_avg2 ( int y, int x)
{
    return (temp_array[y-1][x] + temp_array[y][x-1] + temp_array[y][x+1] + temp_array[y+1][x])/ 4 ;
}

float array_diff ( int y, int x){
    return fabs (array_avg(y,x) - main_array[y][x]);
}


int main() {


    float epsilon = 0.1;
    int i = 0;
    bool found = false, stable_flag = true;



    //Init float Array

    for (int j=0;j<m;j++){
        for(int k=0;k<n;k++){
            if(j==0 || k == 0 || j == 1023 || k ==1023){
                main_array[j][k]=0.0;
            } else {
                main_array[j][k]=50.0;
            }
        }
    }


    while (!found){


        //Check current i if It's stable

        for (int j=1;j<m-1;j++){
            for(int k=1;k<n-1;k++){
                if( array_diff(j,k) >= epsilon ){
                    //Bad one found. Not stable
                    stable_flag = false;
                    break;
                }
            }
        }

        if(stable_flag){
            std::cout<<i<<std::endl;
            found = true;
        }
        else {


            for (int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    temp_array[j][k] = main_array[j][k];
                }
            }


            for (int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(j >= 1 && j<m-1 && k>=1 && k < n-1){

                        main_array[j][k] = array_avg2(j,k);
                    } else {
                        main_array[j][k] = temp_array[j][k];
                    }
                }
            }

            i = i + 1;
            //Reset stable flag
            stable_flag = true;

        }
    }

    return 0;

}