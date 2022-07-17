// iagorrr ;) O(1)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string solve(string s){
    // ab vai ser sempre igual a ba a menos que o último char mude isso.
    s[0] = s[s.size()];
    return s;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}
