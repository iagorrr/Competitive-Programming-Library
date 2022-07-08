// #1789 The Races of Slugs by Thalyson Nepomuceno
#include <iostream>

int main(void){
    short int total;
    short int i;
    short int temp;
    short int higher;

    // Receiving inputs.
    while(std::cin >> total){


        higher = 1;
        for (i = 0; i < total; i++){
            std::cin >> temp;

            if ((temp >= 10) && (temp < 20) && (higher != 3)) {
                higher = 2;
            }
            else if (temp >= 20) {
                higher = 3;
            }
        }

        std::cout << higher << std::endl;
    }
}

// Accepted
