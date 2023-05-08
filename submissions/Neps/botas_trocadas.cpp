#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
    lli N;
    cin >> N;
    map <pair<lli, char>, lli> V;

    lli M;
    char L;
    lli ans = 0;
    for(lli i = 0; i < N; i++){
        cin >> M >> L;
        if(L == 'E'){
            if(V[{M, 'D'}] > 0){// Tem o outro lado.
                ans++;
                V[{M, 'D'}]--;
            }
            else{
                V[{M, 'E'}]++;
            }
        }
        else{
            if(V[{M, 'E'}]){// Tem o outro lado.
                ans++;
                V[{M, 'E'}]--;
            }
            else{
                V[{M, 'D'}]++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// Accepted.
