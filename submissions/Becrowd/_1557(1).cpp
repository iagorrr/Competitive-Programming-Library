// #1557 Square Matrix III by Gabriel Dalalio
#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main(void){
    int sample;
    int l, c;
    long long int result;
    int T;

    do
    {      
        cin >> sample;
        if (sample == 0){
            break;
        }

        // Digits of the biggest number
        T = int(log10(pow(2, sample*2-2)) + 1);

        // Showing each number based in the calculation. number = 2^l*2^c
        for (l = 0; l < sample; l++){
            for (c = 0; c < sample; c++){
                result = int(pow(2, l+c));

                std::cout << std::setw(T) << result;
                if (c + 1 < sample){
                    std::cout << " ";
                }
            }
            std:cout << std::endl;
        }
        std::cout << std::endl;
    
    } while (sample != 0);
    
}

// Accepted
