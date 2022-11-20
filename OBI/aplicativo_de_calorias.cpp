// iagorrr
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, e1, e2, e3;
    cin >> e1;
    cin >> e2;
    cin >> e3;
    cin >> x;

    cout << (e2-e1 <= x ? e2 : e3) << endl;

    return 0;
}

// Aceito 100 / 100