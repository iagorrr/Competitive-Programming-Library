#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    int D, A;
    cin >> D >> A;

    int ans;
    if(D > A){
        ans = D - A;
    }
    else{
        ans = N - A + D;
    }

    cout << ans << endl;
    return 0;
}

// Accepted.
