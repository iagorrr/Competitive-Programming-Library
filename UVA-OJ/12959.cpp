// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int j, r;

    while(cin >> j){
        cin >> r;

        vector<int> a(j+1, 0);
        for(int i = 1; i <= r; ++i){
            for(int k = 1; k <= j; ++k){
                int x;
                cin >> x;
                a[k] += x;
            }

        }

        int max = -1;
        int ans = 0;
        
        for(int i = 1; i <= j; ++i){
            if(a[i] >= max){
                max = a[i];
                ans = i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

// AC.
