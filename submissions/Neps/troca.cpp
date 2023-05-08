// iagorrr ;) prefix sum.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <ll> ans(10, 0);

/*
    if some position is flipped an even number of times, keep the up position.
    Using delta sum the second example goes like.

    l r
    1 3
    5 10
    2 6
    5 9
    1 7 

    sum 1 at l and -1 at r+1

     1  2  3  4  5  6  7  8  9  10
  0  0  0  0  0  0  0  0  0  0  0  0
  0  1  0  0 -1  0  0  0  0  0  0  0
  0  1  0  0 -1  1  0  0  0  0  0 -1
  0  1  1  0 -1  2  0 -1  0  0 -1 -1
  0  2  1  0 -1  2  0 -1 -1  0 -1 -1

    Appying prefix sum we get

  0  2  1  0 -1  2  0 -1 -1  0 -1 -1
  0  2  3  3  2  4  4  3  2  2  1  0

     u  d  d  u  u  u  d  u  u  d 

    up :  7 88 23 44 1 67 73 2 9 11

    ans:  7 55 1  44 1 67 82 2 9 37
    
    down : 4 55 1  1  3 74 82 9 8 37

*/

int main(){
    int n, q;
    cin >> n >> q;
    vector <int> up(100000+5);
    vector <int> down(100000+5);
    vector <ll> turn(100000+5, 0);
    vector<ll> ds(100000+5, 0);

    for(int i = 1; i < n+1; ++i) cin >> up[i];

    for(int i = 1; i < n+1; ++i) cin >> down[i];

    // delta sum.
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;

        turn[l]++;
        turn[r+1]--;
    }

    // prefix sum and getting only the positive.
    for(ll i = 1; i < n+2; ++i) ds[i] = ds[i-1]+turn[i];

    // done !
    cout << (ds[1]%2==0 ? up[1] : down[1]);
    for(ll i = 2; i < n+1; ++i){
        if(ds[i]%2==0) cout << " " << up[i];
        else cout << " " << down[i];
    }
    cout << endl;

    return 0;
}

// Accepted :(