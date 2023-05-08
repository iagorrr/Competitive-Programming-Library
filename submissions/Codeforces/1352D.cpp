#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll solve(vector <ll> v, ll N){
    ll a = 0;
    ll b = N-1;

    ll wa= 0;
    ll wb = 0;

    ll ans = 0;
    while(a <= b){
        if(wa == wb){ 
            ans = a + N-1-b;
        }

        if(wa <= wb){ wa += v[a]; a++;}
        else{ wb += v[b]; b--;}
    }
    if(wa == wb) ans = a + N-1-b;
    // cout << "wa: " << wa << " wb: " << wb << " b: " << b << " a: " << a << endl;

    return ans;
}
int main(){
    ll N;
    cin >> N;

    while(N--){
        ll S;
        cin >> S;

        vector <ll> a(S);

        for(ll i = 0; i < S; ++i) cin >> a[i];

        cout << solve(a, S) << endl;
    }

    return 0;
}