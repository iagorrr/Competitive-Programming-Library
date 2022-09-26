// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a;
    int b;
    
    cin >> a;
    int mod3a = a % 3;

    cin >> b;
    int  mod3b = b % 3;
    if(mod3b == mod3a) mod3b = (mod3b + 1) % 3;

    if(1 != mod3a and 1 != mod3b) cout << 1 << '\n';
    if(0 != mod3a and 0 != mod3b) cout << 0 << '\n';
    if(2 != mod3a and 2 != mod3b) cout << 2 << '\n';
    return 0;
}

// 100/100 Aceito.
