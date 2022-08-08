// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    map <int, bool> m;
    int ans = 0;

    int a;
    cin >> a;
    m[a] = true;
    ans++;

    cin >> a;
    if(!m[a]) ans++;
    m[a] = true;

    cin >> a;
    if(!m[a]) ans++;
    
    cout << ans;
    return 0;
}

// AC