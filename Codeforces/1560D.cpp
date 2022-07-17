// iagorrr ;) O(n)
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
using ll = long long;

vector <string> pow2;
void make_twoPow(ll max){
    ll n = 1;
    int i = 0;
    while(n <= max && n > 0){
        pow2.push_back(to_string(n));
        n *= 2;
        i++;
    }
}

int solve(string n){
    int ans = 1000000000;
    for(int i = 0; i < pow2.size(); i++){
        string s = pow2[i];
        int pn = 0;
        int ps = 0;

        while(pn < n.size() && ps < s.size()){
            if(n[pn] == s[ps]){
                pn++;
                ps++;
            }
            else pn++;
        }
        int temp = n.size()-ps+s.size()-ps;
        ans = min(temp, ans);
    }

    return ans;

}
int main(){
    int T;
    cin >> T;
    make_twoPow(1e18);
    while(T--){
        string n;
        cin >> n;
        cout << solve(n) << endl;
    }

    return 0;
}

// Accepted.
