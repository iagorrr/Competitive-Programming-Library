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

    lli ans = 0;
    bool firstAns = true;
    for(lli l = 0; l < N+2; l++){
        for(lli r = l+1; r < N+2; r++){
            if(M[r]-M[l] >= L && M[r]-M[l] <= H){
                if(firstAns){ 
                    ans = V[r]-V[l];
                    firstAns = false;
                }
                else ans = max(ans, V[r]-V[l]);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}

// TLE.