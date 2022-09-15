// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string a;
    string b;

    cin >> a;
    cin >> b;

    string ans;
    ll i = 0;
    ll maxsize = max(a.size(), b.size());
    while(i < maxsize){
        if(a[i] == b[i]) ans.push_back(a[i]);
        else break;
        ++i;
    }
    
    cout << (ans.size() != a.size() || b.size() < a.size() ? "No" : "Yes") << '\n';
    return 0;
}

// Accepted.
