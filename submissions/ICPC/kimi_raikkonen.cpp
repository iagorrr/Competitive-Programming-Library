// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll parse(){
    string s;
    cin >> s;
    
    string current;
    ll msms = 0;
    ll ans = 0;
    for(ll i = 0; i < s.size(); ++i){
        if(s[i]!= ':') current.push_back(s[i]);
        else{
            if(msms == 0) ans += (ll)stoi(current) * 60 * 1000;
            else if(msms == 1) ans += (ll)stoi(current) * 1000;
            msms++;
            current.erase();
        }
    }
    ans += (ll)stoi(current);
    return ans;
}
int main(){
    ll n, v;
    cin >> n >> v;

    ll tempo_melhor_volta = LLONG_MAX;
    ll momento_melhor_volta = LLONG_MAX;
    ll corredor_melhor_volta = 0;
    
    vector<pair<ll, ll>> tempo_corredor;

    for(ll i = 0; i < n; ++i){
        ll c;
        cin >> c;

        ll tempo_atual_corredor = 0;

        for(ll j = 0; j < v; ++j){
            ll tempo_volta = parse();
            

            // verificar se ele teve a melhor volta, e se foi antes de alguem que teve esse mesmo tempo.
            if(tempo_volta < tempo_melhor_volta and tempo_atual_corredor < momento_melhor_volta){
                tempo_melhor_volta = tempo_volta;
                corredor_melhor_volta = c;
                momento_melhor_volta = tempo_atual_corredor;
            }

            tempo_atual_corredor += tempo_volta;
        }

        tempo_corredor.push_back({tempo_atual_corredor, c});
    }

    // verificar no rank se o que teve essa melhor volta tá no top 10.
    sort(tempo_corredor.begin(), tempo_corredor.end(), greater<pair<ll,ll>>());
    for(ll i = 0 ; i < 10; ++i){
        if(tempo_corredor[i].second == corredor_melhor_volta){
            cout << corredor_melhor_volta << '\n';
            return 0;
        }
    }

    cout << "NENHUM\n";
    return 0;
}

// Accepted.