#include <iostream>

using namespace std;

int main(void){
    int testcases;

    // Reading total test cases.
    std::cin >> testcases;

    int R1, R2;
    int i;
    for (i = 0; i < testcases; i++){
        cin >> R1;
        cin >> R2;

        std::cout << (R1+R2) << std::endl;
    }

}

// Accepted
