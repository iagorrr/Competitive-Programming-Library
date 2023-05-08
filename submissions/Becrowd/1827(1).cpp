// #1827 Square Array IV by Neilor Tonin
#include <iostream>

using namespace std;

int main(void){
    unsigned short int size;
    unsigned short int i, j;
    unsigned short int inside;
    char current;

    while(std::cin >> size){
        inside = int((size-1)/3);

        for (i = 0; i < size; i++){
            for (j = 0; j < size; j++){
                
                // outside square.
                current = '0';

                // Main diagonal.
                if (i == j){
                    current = '2';
                }

                // Second diagonal.
                if (i == size - 1 - j){
                    current = '3';
                }

                // inside square.
                if ( ((i >= inside) && (i < size-inside)) && ((j >= inside) && (j <= size-inside-1)) ){
                    current = '1';
                }

                // center.
                if ((i == size/2) && (j == size/2)){
                    current = '4';
                }

                // output.
                std::cout << current;
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
    }
}