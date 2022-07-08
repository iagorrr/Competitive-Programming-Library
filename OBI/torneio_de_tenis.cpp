#include <bits/stdc++.h>

using namespace std;

int main(){

    int result =0;

    for(int i = 0; i < 6; i++){
        char vic;
        cin >> vic;

        if(vic == 'V'){
            result ++;
        }
    }

    if(result > 4) {
        cout << 1 << endl;
    }
    else if (result > 2){
        cout << 2 << endl;
    }
    else if(result > 0){
        cout << 3 << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}

// 100/100
