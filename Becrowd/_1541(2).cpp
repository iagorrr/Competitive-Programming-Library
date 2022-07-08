// #1541 Building Houses by Normander Jr, UFU
#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int A, B, C;
    int X;

    do
    {   
        // Receiving values.
        cin >> A;
        if (A == 0){
            break;
        }
        cin >> B;
        cin >> C;

        // Calculating
        X = sqrt( ((A * B * 100) / C ) );

        // Showing output.
        std::cout << X << std::endl;

    } while (A != 0);
    
}

// Accepted
