// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Implementação com backing track.
    - Para cada moeda:
        Não escolher,
        Se possível, escolher.
    O(2^N)
*/
vector <ll> a(1000+4);
ll v, n; 
string ans = "N";

void backingtrack(ll i, ll s){
    // cout << "i: " << i << " s: " << s << endl;

    // já chegamos no valor que queriamos.
    if(s == v){
        ans = "S";
        return;
    }

    // analisamos todas as moedas.
    if(i == n) return;
    

    // Verificar não pegando a moeda atual.
    backingtrack(i+1, s);

    // Verificar pegando a moeda atual, caso ela não ultrapasse os valor máximo
    if(s+a[i] <= v)backingtrack(i+1, s + a[i]);
}

int main(){
    cin >> v  >> n;

    for(ll i = 0; i < n; ++i) cin >> a[i];

    backingtrack(0, 0);

    cout << ans << endl;
    return 0;
}

// 70/100, casos teste com menos N <= 20 e TLE no Neps