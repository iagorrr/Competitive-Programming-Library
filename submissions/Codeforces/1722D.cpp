// iagorrr ;)
#include <bits/stdc++.h>
using namespace std; 
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<long long>;

void solve(string sx, ll n){
    string s = '#'+sx;
    ll initial = 0;
    ll max = 0;
    ll metade = n/2 + n%2;
    list <ll> poserradosl;
    list <ll> poserradosr;

    vll original(n+1, 0);
    for(ll i = 1; i <= n; ++i){
        if(s[i] == 'L') initial += i-1, original[i] = i-1;
        else initial += n-i, original[i] = n-i;
    
        if(i <  metade and s[i] == 'L') poserradosl.push_back(i);
        if(i == metade and n%2 == 0 and s[i]=='L') poserradosl.push_back(i);
        if(i  > metade and s[i] == 'R') poserradosr.push_back(i);
        max += i > n-i ? i : n-i;
    }

    // cout << "O: ";
    // for(int i = 1; i<=n; ++i) cout << original[i] << " ";
    // cout << endl;

    // cout << "L: ";
    // for(auto x : poserradosl) cout << x << " ";
    // cout << endl;

    // cout << "R: ";
    // for(auto y : poserradosr) cout << y << " ";
    // cout << endl;
    
    vll ans(n+1, 0);
    
    ll current = initial;
    ll count = 1;
    ll al;
    ll ar;
    while((!poserradosl.empty() || !poserradosr.empty()) and count <= n){
        al = 0;
        ar = 0;
        if(!poserradosl.empty()){
            al = (n-poserradosl.front()) - original[poserradosl.front()];
        }
        if(!poserradosr.empty()){
            ar = poserradosr.back() -1 - original[poserradosr.back()];
        }
        // cout << "ar: " << ar << " al: " << al << " c: " << current << endl;
        if(al == 0 and ar == 0) break;

        if(al >= ar){
            current+= al;
            poserradosl.pop_front();
        }
        else{
            current += ar;
            poserradosr.pop_back();
        }

        ans[count] = current;
        count++;
    }
    while(count <= n){
        ans[count] = current;
        count++;
    }      
    for(ll i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << endl;
}
int main(){
    fast
    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        string s;
        cin >> s;

        solve(s, n);
    }   

    return 0;
}