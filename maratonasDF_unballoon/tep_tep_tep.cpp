// iagorrr ;) O(N)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

/*
    Fazer um prefix sum ao contrário para o  total de P.

    Toda vez que for encontrado um E na posição i significa que ele pode ser combinado como todos
    os P que estão a sua direita, por tanto ep[i] += p[i].

    Tendo o total de EP's iterar de trás para frente e toda vez que se encontrar um T significa que
    ele se combinar com todos os ep[i], portanto ans += ep[i].

            A   T E M P E S T A D E   P A S S O U 
    p[i]    2 2 2 2 2 2 1 1 1 1 1 1 1 1 0 0 0 0 0 0 
    ep[i]   4 4 4 4 2 2 2 1 1 1 1 1 0 0 0 0 0 0 0 0 
    ans     5 5 5 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 
    
*/
int main(){
    fast
    int n;
    cin >> n; cin.ignore();

    string s;
    getline(cin, s);

    vector<int> p(n+1, 0);
    // prefix sum ao 'contrário'
    vector<ll> ep(n+1, 0);
    for(int i = n-1; i >= 0; --i){
        p[i] = p[i+1];
        ep[i] = ep[i+1];

        if(s[i] == 'P') p[i]++;

        if(s[i] == 'E') ep[i] += p[i];
    }

    cout << "  ";
    for(auto c : s) cout << c << ' ';
    cout << '\n';
    for(auto x : p) cout << x << ' ';
    cout << '\n';
    for(auto x : ep) cout << x << ' ';
    cout << '\n';    
    ll ans = 0;
    for(int i = n-1; i >= 0; --i){
        if(s[i] == 'T'){
            ans += ep[i];
        }
    }

    cout << ans << '\n';
    return 0;
}