#include <iostream>

int main(void){
    int complain;
    while(std::cin >> complain){
        if (complain <= 0){
            std::cout << "vai ter copa!" << std::endl;
        }
        else {
            std::cout << "vai ter duas!" << std::endl;
        }
    }
}

// Accepted
