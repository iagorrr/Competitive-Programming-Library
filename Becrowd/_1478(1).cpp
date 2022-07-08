#include <iostream>
#include <iomanip>

using namespace std;

int main(void){

    short int sample;
    short int i, j;

    sample = 1;
    while (sample != 0){

        cin >> sample;
        if (sample == 0){
            break;
        }

        for (i = 0; i < sample; i++) {
            for (j = 0; j < sample; j++) {
                if (j >= i) {
                    std::cout << std::setw(3) << (j-i+1);
                }
                else {
                    std::cout << std::setw(3) << (i-j+1);
                }

                if (j +1 < sample){
                    std::cout << " ";
                }
            }
           std::cout << std::endl;
        }
        std::cout <<std::endl;
    }



    return 0;
}