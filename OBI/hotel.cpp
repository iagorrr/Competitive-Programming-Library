#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lli D, A , N;

    cin >> D >> A >> N;

    lli ans;
    if(N < 16)
        ans = (D+((N-1  )*A))*(32-N);
    else
        ans = (D+(15-1)*A)*(32-N);
    cout << ans << endl;

    return 0;
}