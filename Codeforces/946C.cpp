// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

string solve(string s){
    if((int)s.size() < 26) return "-1";

    int current = 'a';
    int max = 'z';
    string ans = s;
    for(int i = 0; i < (int)ans.size(); ++i){
        if(ans[i] <= current){
            ans[i] = (char)current;
            current++;
        }

        if(current > max) break;
    }

    return current > max ? ans : "-1";
}
int main(){
    string s;
    cin >> s;
    
    cout << solve(s) << endl;

    return 0;
}

// Accepted.
