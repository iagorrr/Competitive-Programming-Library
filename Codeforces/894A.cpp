#include <bits/stdc++.h>
using namespace std;


inline int solve(const string s){

    int ans = 0;
    for(int i = 0; i < (int)s.size(); ++i){
        if(s[i] == 'Q'){
            int ta =0;
            for(int j = i; j < (int)s.size(); ++j){
                ta += s[j] == 'A' ? 1 : 0;
                ans += s[j] == 'Q' ? ta : 0;
            }
        }
    }

    return ans;
}
int main(){
    string s;
    cin >> s;

    cout << solve(s) << '\n';
    return 0;
}
