/*
 * Longest increasing Sequence, dynamic programming and binary search.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<long long>;

ll lis(vll &a){
    // Inicialization.
    ll n = a.size();
    ll INF = LLONG_MAX;
    vll d(n+1, INF);

    d[0] = -INF;

    for(ll i = 0; i < n; ++i){
        ll j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();

        if(d[j-1] < a[i] && a[i] < d[j]) d[j] = a[i];
    }

    ll ans = 0;
    for(ll i = 0; i <=n; ++i){
        if(d[i] < INF) ans = i;
    }

    return ans;
}

int main(){
    ll n;
    cout << "size of the vector : ";
    cin >> n;
    
    // generate vector.
    srand(time(NULL));
    vll a(n);
    for(ll i = 0; i < n; ++i){
        a[i] = rand()%100;
        cout << a[i] << " ";
    }
    cout << endl;

    
    cout << "lis : " << lis(a) << endl;

    return 0;
}

