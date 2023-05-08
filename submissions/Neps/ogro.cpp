// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin  >> n;

    string me;
    string md;

    while(n and me.size() < 5){
        n--;
        me.push_back('I');
    }

    while(n and md.size() < 5){
        n--;
        md.push_back('I');
    }

    cout << (me.empty() ? "*" : me) << endl;
    cout << (md.empty() ? "*" : md) << endl;
    return 0;
}

// Aceito 100/100
