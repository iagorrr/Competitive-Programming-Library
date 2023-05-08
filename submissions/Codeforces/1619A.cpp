#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    bool valid = true;
    while(T--){
        string S;
        cin >> S;
        valid = true;
        if(S.size() % 2 == 0){
            int N = S.size();
            for(int i = 0; i < N/2; i++){
                if(S[i] != S[i+N/2]){
                    valid = false;
                    break;
                }
            }
        }
        else valid = false;
        if(valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}