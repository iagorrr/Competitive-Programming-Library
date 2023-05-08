// iagorrr ;) O(N)
#include <bits/stdc++.h>
using namespace std;

const string a = "abcdefghijklmnopqrstuvwxyz";

string solve(string s){
    for(int i = 0; i < s.size(); i++){
        if(!(i&1)) s[i] = s[i] == 'a' ? 'b' : 'a';
        else s[i] = s[i] == 'z' ? 'y': 'z';
    }

    return s;
}
int main(){
    int N;
    cin >> N;

    while(N--){
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}

// Accepted.
