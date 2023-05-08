#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    string sA, sB;
    cin >> sA >> sB;
    lli angA, angB;
    lli ans;
    char A = sA[0]; char B = sB[0];

    if(A == B)ans = 0;
    else if(A == 's' && B == 'n' || (A == 'n' && B == 's')) ans = 180;
    else if(A == 'o' && B == 'l' || (A == 'l' && B == 'o')) ans = 180;
    else ans = 90;

    cout << ans << endl;
    return 0;
}

// 100/100.
