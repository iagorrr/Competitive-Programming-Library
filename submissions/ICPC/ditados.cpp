#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Um ou mais correto cada um ganha 1.

    se ngm acertar 0.5 os que chegaram mais perto.

    exibir a pontuacao do maior,

    exibir todos que tiveram essa melhor pontuacao.


*/
ll edit_distance(const string  &s1, const string &s2){
    ll editdp[s1.size()+1][s2.size()+1];
    // cost to : insert, delete, substitute
    const ll c_i = 1, c_d = 1, c_s = 1;

    const ll m = s1.size(), n = s2.size();

    // if there is i-characters at s1 and 0 at s2, the cost is the cost to remove from s1.
    for(ll i = 0; i <= m; ++i) editdp[i][0] = i*c_d;

    /* now if there is j-characters at s2 and 0 at s1 the total cost is the cost to insert 
    j-characters at s1.
    */
    for(ll j = 1; j <= n; ++j) editdp[0][j] = j*c_i;


    /*
        now for each pair i and j we check which is the best operation, and for that pair, the best
        one is the one with the lowest cost, and so on.

        - note that we already calculate every positon for i or j = 0.
    */
    for(ll i = 1; i <= m; ++i){
        for(ll j = 1; j <= n; ++j){
            ll insertion = editdp[i][j-1] + c_i;
            ll deletion = editdp[i-1][j] + c_d;
            ll change = editdp[i-1][j-1] + c_s*(s1[i-1] == s2[j-1] ? 0 : 1);

            editdp[i][j] = min({insertion, deletion, change});
        }
    }

    return editdp[m][n];
}

vector <ll> pontuacoes(5, 0);
void solve(string ori, vector<string> tent){
    bool acertaram = false;
    for(ll i = 0; i < 5; ++i){
        if(tent[i] == ori){
            acertaram = true;
            pontuacoes[i] += 10;
        }
    }

    if(acertaram) return;

    // verificar quem chegou mais perto e tal.
    ll minop = LLONG_MAX;
    vector<ll> ops(5);
    for(ll i = 0; i < 5; ++i){
        ll op = edit_distance(ori, tent[i]);
        if(op < minop) minop = op;
        ops[i] = op;
    }

    for(ll i = 0; i < 5; ++i){
        if(ops[i] == minop) pontuacoes[i] += 5;
    }
}
int main(){
    ll t;
    cin >> t;

    while(t--){
        string original;
        cin >> original;

        vector<string> tentativas(5);
        for(auto &x : tentativas) cin >> x;

        solve(original, tentativas);
    }

    ll maxpont = 0;
    for(ll i = 0; i < 5; ++i) if(pontuacoes[i] > maxpont) maxpont = pontuacoes[i];

    cout << maxpont/10 << '.' << maxpont%10 << '\n';
    ll i;
    for(i = 0; i < 5; ++i){
        if(pontuacoes[i] == maxpont){
            cout << i+1;
            break;
        }
    }
    for(i = i+1; i < 5; ++i){
        if(pontuacoes[i] == maxpont) cout << ' ' << i+1;
    }
    cout << '\n';



    return 0;
}

// Accepted.
