/*
 * Backpack problem using backtracking.
 *
 * 2^n
 * Because for each element we can choose or not.
 * 
 * */
#include <bits/stdc++.h>
#define MAX_N 1000
using namespace std;
using ll = long long;
using vll = vector<long long>;

/*
 * i - checking the i value and after.
 * wsum - the weight sum of the current elements.
 * vsum - the value sum of the current elements.
 *
 * here considering the 1-index.
 * needs to choose elements that sum <= s weights.
 * needs maximize the value.
 * */
vll w(1000+1), v(1000+1);
ll ans, s, n;
void backpack_backtracking(ll i, ll wsum, ll vsum){
    // already at the end, check if is the best anwer.
    if(i == n+1){
        ans = max(ans, vsum);
        return;
    }
    
    // not choosing the i-element.
    backpack_backtracking(i+1, wsum, vsum);

    // if is still possible to add weight so check adding the i-element.
    if(wsum + w[i] <= s) backpack_backtracking(i+1, wsum+w[i], vsum + v[i]);
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));

    cout << "total elements : ";
    cin >> n;

    cout << "max weight : ";
    cin >> s;

    for(ll i = 1; i <= n; ++i){
        w[i] = rand()%10;
        v[i] = rand()%10;

        cout << i << "w: " << w[i] << " v: " << v[i] << endl;
    }

    // starts with '1' element.
    backpack_backtracking(1, 0, 0);

    cout << "max sum of values : " << ans << endl;
    
    return 0;
}
