// iagorrr
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll X, Y;
map <ll, ll> check;

// Deep full search algorithm using recursion.
ll dfs(ll Y){

    // If is already checked return the value calculed before.
    if(check.find(Y) != check.end()) return check[Y];

    // If our current value is lower than we want, just increase it until get the X.
    if(Y <= X) return X-Y;

    // Else, compare the possibilites, sum one, decrease one, and divide.
    ll ans = Y - X; // if we just decrease as many possible.
    if(Y&1) ans = min(ans, min(dfs((Y-1)/2), dfs((Y+1)/2))+2); // +2 because we made two operations.
    else ans = std::min(ans, dfs(Y/2)+1); // +1 because is one operation more.

    check[Y] = ans; 
    return check[Y];
}

int main(){
    cin >> X >> Y;

    cout << dfs(Y) << endl;

    return 0;
}

// Accepted.