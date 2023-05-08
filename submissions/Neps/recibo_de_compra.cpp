// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 0;
ll r, k;

// need to use recursive function because there is no fixe value for K.
void LOOP(int level, int min, int max){
    if(level == k){
        if(min <= max) ans++; // there is still others elements to take.
    }
    else{
        for(int i = min; i < max; ++i) LOOP(level+1, i+1, max-i); // check the other possibilities.
    }
    
}
int main(){

    cin >> r >> k;


    LOOP(1, 1,  r);
    cout << ans << endl;
}

// AC