// iagorrr ;) O(1)
#include <bits/stdc++.h>
using namespace std;

int main(){
    bool ans = true;
    int a, b, c, d;
    cin >> a >> b >> c >> d; 

    if(a != b+c+d) ans = false;
    if(b+c != d) ans = false;
    if(b!=c) ans = false;

    cout << (ans ? "S" : "N") << endl;

    return 0;
}

// 100/100 AC