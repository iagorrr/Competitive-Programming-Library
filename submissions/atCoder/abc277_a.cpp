// iagorrr ;) 
#include <bits/stdc++.h>
using namespace std;
/*====================================================================================================*/
int main(void) { 
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    int ans;
    for(int i = 0 ; i < n; ++i){
        int c;
        cin >> c;
        if(c == x){
          ans = i+1;
          break;
        }
    }

    cout << ans << '\n';
    return 0; 
}
/*====================================================================================================*/
// Accepted.
