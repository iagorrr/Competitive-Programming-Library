#include <bits/stdc++.h>

using namespace std;

int main(void){

    int cartas[5];
    bool crescendo = true;
    bool decrescendo = true;

    int i;
    for (i = 0;i < 5; i++){
        cin >> cartas[i];
        if ((cartas[i] < cartas[i-1]) && (i > 0)){
            crescendo = false;
        }
    }

    i = 1;
    while((decrescendo ) && (i < 5)){
        if (cartas[i] > cartas[i-1]){
            decrescendo = false;
        }
        i++;
    }

    if (crescendo){
        cout << "C" << '\n';
    }
    else if (decrescendo){
        cout << "D" << '\n';
    }
    else{
        cout << "N" << '\n';
    }
    return 0;
}