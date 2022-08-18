// iagorrr ;) O(N)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll kadane(vll a, ll n){
    ll maxAns = LLONG_MIN, currmax = 0, start = 0, end = 0, spos =0;

    for(ll i = 0; i < n; ++i){
        currmax += a[i];

        if(currmax > maxAns){
            maxAns = currmax;
            start = spos;
            end = i;
        }

        if(currmax < 0){// regret from this choice start again, from the next.
            currmax = 0;
            spos = i+1;
        }
    }

    cout << "s: " << start << " " << "e: " <<  end << endl;
    return maxAns;
}
int main(){
    srand(time(NULL));
    ll n;
    cin >> n;

    vll a(n);
    for(auto &x : a){ x = rand()%10 >= 5 ? rand()%10 : -rand()%10; }
    for(auto x : a) cout << x << " ";
    cout << endl;

    cout << "kadane: " << kadane(a, n) << endl;;
    return 0;
}
