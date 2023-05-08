#include <bits/stdc++.h>

using namespace std;
int N, L;

bool check(int x){
    if(L-x >= N-1) return true;

    return false;
}

int main(){

    cin >> L >> N;

    // Upper bound pra achar o maior número que não estrapola o L.
    long long int l = 1;
    long long int r = L;
    long long int mid;
    long long int ans;

    while(l + 1< r){
        mid = (l+r)/2;

        if(check(mid)) l = mid;
        else r = mid -1;
    }

    if(check(l)) ans = l;
    if(check(r)) ans = r;

    // cout << ans << endl;

    // Completar com o menor valor possível.
    long long int cArea = ans*ans;
    long long int cTapetes = 1;
    while(cTapetes < N){
        cTapetes++;
        cArea++;
    }

    cout << cArea << endl;
    return 0;
}

// Accepted.