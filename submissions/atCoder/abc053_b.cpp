// iagorrr ;) O(N) 
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int fa = 0;
    while(fa < s.size() && s[fa] != 'A') ++fa;

    int lz = s.size()-1;
    while(lz >= 0 && s[lz] != 'Z') --lz;

    cout << lz - fa + 1<< endl;
    return 0;
}

// Accepted.