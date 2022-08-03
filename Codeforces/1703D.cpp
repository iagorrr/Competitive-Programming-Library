// iagorrr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve(ll N){
    string ans;
    ll i = N;
    while(i--)  ans.push_back('0');

    vector<string> ss;
    map <string, bool> m;
    for(i = 0; i < N; ++i){
        string temp;
        cin >> temp;
        ss.push_back(temp);
        m[temp] = true;
    }

    // For each string check if a substring from left exist, if so check the right.
    i = 0;
    for(auto a : ss){
        string s = a;

        for(ll n = 1; n < s.size(); n++){
            // cout << s.substr(0, n) << ' ' << s.substr(n) << endl;
            if(m[s.substr(0, n)] && m[s.substr(n)]){
                ans[i] = '1';
                break;
            }
        }
        cout << endl << endl << endl;

        i++;
    }

    return ans;
}
int main(){
    ll T;
    cin >> T;

    while(T--){
        ll N;
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}

// Accepted.