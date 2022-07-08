#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    string ans;
    for(int i = 0; i < S.size(); i++){
        if(S[i] != 'B') ans.push_back(S[i]);
        else{
            if(!ans.empty()) ans.pop_back();
        }
    }
    cout << ans << endl;
    
    return 0;
}