// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int c, t;
    c = 0;
    t = 0;
    while(n--){
        int x;
        cin >> x;
        c += x < 50 ? 1 : 0;
        t += (x >= 50 and x < 85) ? 1 : 0;
    }

    cout << c  << " " << t << endl;
    return 0;
}

// Aceito.
