// Iagorr ;)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;

int main(){
    ulli A, B;
    char op;
    cin >> A >> op >> B;
    
    lli ans = 0;
    if(op == '+') ans = A + B;
    else ans = A-B;

    cout << ans << endl;
    return 0;
}

// Accepted.
