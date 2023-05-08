#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long int lli;


int main(){
    lli N, L, H;
    cin >> N >> L >> H;

    vector <lli> V(N+2, 0);
    for(lli i = 1; i < N+1; i++) cin >> V[i];

    vector <int> M(N+2, false);
    for(lli i = 1; i < N+1; i++) cin >> M[i];

    // Delta sum.
    for(lli i = 1; i < N+2; i++){
        V[i] += V[i-1];
        M[i] += M[i-1];
    }
    /*
    cout << endl;
    for(lli i = 0; i < N+2; i++){
        cout << V[i] << " ";
    }
    cout << endl;
    for(lli i = 0; i < N+2; i++){
        cout << M[i] << " ";
    }
    cout << endl;
    */

    // Two pointers opposite directional.
    lli ans;
    bool firstAns = true;
    lli l = 0;
    lli r = 1;
    while(l < r){
        lli dm = M[r]-M[l];
        lli dv = V[r]-V[l];
        if(dm <= H){
            if(dm >= L){
                if(firstAns){
                    ans = dv;
                    firstAns = false;
                } 
                else ans = max(ans, dv);
            }
            r++;
        }
        else{
            l++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
