#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    int needP = 0, needM = 0;
    int temp;
    int pDone, mDone;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        if(temp == 1) needP++;
        else needM++;
    }

    cin >> pDone >> mDone;
    if(pDone >= needP && mDone >= needM) cout << "S";
    else cout << "N";
    cout << endl;
    return 0;
}

// 100/100