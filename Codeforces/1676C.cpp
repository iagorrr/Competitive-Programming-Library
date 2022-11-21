// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int char_dist(char a, char b){
    return (a >= b ? a-b : b-a);
}
int solve(vector<string> vs){
    
    int ans = 9999;
    for(int i = 0; i < (int)vs.size(); ++i){
        for(int j = i+1; j < (int)vs.size(); ++j){
            int cans = 0;
            for(int k = 0; k < (int)vs[i].size(); ++k){
                cans += char_dist(vs[i][k], vs[j][k]);
            }

            ans = min(ans, cans);
        }
    }

    return ans;
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n, s;
        cin >> n >> s;
        vector <string> vs(n);
        for(auto &x : vs) cin >> x;

        cout << solve(vs) << endl;
    }
    return 0;
}
// Accepted.