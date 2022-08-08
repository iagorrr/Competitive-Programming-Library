// iagorrr ;) O(N)
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

string solve(string s, int x, int y){
    map <char, int> m;
    for(auto it = s.begin(); it != s.end(); ++it) m[*it]++;

    bool cx = true;
    if(x < 0) cx = m['L'] >= -1*x;
    else cx = m['R'] >= x;

    bool cy = true;
    if(y < 0) cy = m['D'] >= -1*y;
    else cy = m['U'] >= y;

    return cx && cy ? "YES" : "NO";
}

int main(){
    fast
    int T;
    cin >> T;

    while(T--){
        int x, y;
        cin >> x >> y;

        string s;
        cin >> s;

        cout << solve(s, x, y ) << endl;
    }

    return 0;
}

// Accepted.