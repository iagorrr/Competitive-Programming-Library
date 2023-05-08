// iagorrr ;) O(n^2)
#include <bits/stdc++.h>

using namespace std;

int main(){
    int K, S;
    cin >> K >> S;

    int x, y;
    int ans = 0;
    for(x = 0; x <= K; ++x){
        for(y = 0; y <= K; ++y){
            if(S-x-y <= K && S-x-y >= 0) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
