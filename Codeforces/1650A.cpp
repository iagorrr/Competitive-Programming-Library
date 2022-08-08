// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


string solve(string s, char c){
    ll N = s.size();
    for(int i = 0; i < N; i++){
        if(s[i] == c){
            //cout << i << " " << N -i -1<< endl;
            if((i % 2 == 0) && ((N-i-1) % 2 == 0)){
                return "YES";
            }
        }
    }

    return "NO";
}
int main(){
    ll T;
    cin >> T;

    while(T--){
        string s;
        char c;

        cin >> s;
        cin >> c;

        cout << solve(s, c) << endl;
    }
    
    return 0;
}

// AC
