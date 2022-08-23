/*
   The backpack problem : given the maximum weight you can carry, and n items with w_i weight, and v_i value,
   maximize the value, without overflow the maximum weight.

   O(N*S)
   - because there is n*s states, and for each one the cost is O(1) to calculate.
*/
#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;
using ll = long long;
using vll = vector<long long>;

/*
   decrease the second parameter of the dp, to verify if is possible to add the element...
*/
ll w[MAX_N+1], v[MAX_N+1];
ll n, s;
ll knapsack_dp(){
    // dp initialization.
    ll INF = LLONG_MAX;
    ll dp[MAX_N+1][s+1];

    dp[0][0] = 0;
    for(ll i = 1; i <= s; ++i) dp[0][i] = -INF;
    
    // calcucating the best options.
    for(ll i = 1; i <= n; ++i){
        for(ll j = 0; j <= s; ++j){
            // can't choose this element.
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else{
                if(dp[i-1][j] <= dp[i-1][j -w[i]]+v[i]){// choose this element.
                    dp[i][j] = dp[i-1][j-w[i]] + v[i];
                }
                else{// don't choose this element.
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    // finding the answer.
    ll ans = 0;
    for(ll i = 1; i <= s; ++i)
        if(ans < dp[n][i]) ans = dp[n][i];
    


    return ans;

}

/*
    Almost the same but in this way restore the elements choosen. 
*/
ll knapsack_dp_elements(){
    // choosed elements.
    bool opt[MAX_N+1][s+1];

    // dp initialization.
    ll INF = LLONG_MAX;
    ll dp[MAX_N+1][s+1];
    dp[0][0] = 0;
    for(ll i = 1; i <= s; ++i) dp[0][i] = -INF;
    
    // calcucating the best options.
    for(ll i = 1; i <= n; ++i){
        for(ll j = 0; j <= s; ++j){
            // can't choose this element.
            if(w[i] > j){
                opt[i][j] = false;
                dp[i][j] = dp[i-1][j];
            }
            else{
                if(dp[i-1][j] <= dp[i-1][j -w[i]]+v[i]){// choose this element.
                    opt[i][j] = true;
                    dp[i][j] = dp[i-1][j-w[i]] + v[i];
                }
                else{// don't choose this element.
                    opt[i][j] = false;
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    
    // finding the answer.
    ll s2 = 0;
    ll ans = 0;
    for(ll i = 1; i <= s; ++i){
        if(ans < dp[n][i]){
            s2 = i;
            ans = dp[n][i];
        }
    }

    // finding the best sequence.
    vll items;
    for(ll i = n; i > 0; --i){
        if(opt[i][s2]){// the element was used.
            s -= w[i];
            items.push_back(i);        
        }
    }
    reverse(items.begin(), items.end());
    cout << "items at the maximum sum : ";
    for(auto x : items) cout << x << " ";
    cout << endl;

    return ans;
}

int main(){
    srand(time(NULL));

    cout << "total items : ";
    cin >>  n;
    cout << "max weight : ";
    cin >> s;
    for(ll i = 1; i <= n; ++i){
        v[i] = rand()%100;
        w[i] = rand()%100;
        cout << "w: " << w[i] << " v: " << v[i] << endl;    
    }
    
    cout << knapsack_dp_elements() << endl;
    cout << knapsack_dp() << endl;

    return 0;
}
