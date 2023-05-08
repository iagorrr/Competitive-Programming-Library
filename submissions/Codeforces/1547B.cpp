// iagorrr  ;) O(N)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const string a = "abcdefghijklmnopqrstuvwxyz";
string solve(string s){
    int apos = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            apos = i;
            break;
        }
    }
    if(apos == -1) return "NO";

    int l = apos - 1;
    int r = apos +1;
    int p = 1;
    while(l >= 0 || r < s.size()){
        if(l >= 0 && s[l] == a[p]){
            l--;
            p++;
            continue;
        }
        if(r < s.size() && s[r] == a[p]){
            r++;
            p++;
            continue;
        }

        return "NO";
    }

    return "YES";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}

// Accepted.

