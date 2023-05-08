// iagorrr O(N)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
    Just find the begning of the string before it really starts,
    and the end of string after it ends...

    001000
     010
    0       start
        00  end

    we need that or the left start or the right start
    has at least one char so is possible to 'split' the string.
*/
string solve(string s, int l, int r){
    l--; r--;

    int i = 0;
    while(i < l){
        if(s[i] == s[l]) return "YES";
        i++;
    }

    i = s.size()-1;
    while(i > r){
        if(s[i] == s[r]) return "YES";
        i--;
    }

    return "NO";

}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    
    int N;
    cin >> N;

    while(N--){
        int size, q;
        cin >> size >> q;
        string s;
        cin >> s;
    
        
        while(q--){
            int l, r;
            cin >> l >> r;
            cout << solve(s, l, r) << endl;
        }
    }

    return 0;
}

// Accepted.
