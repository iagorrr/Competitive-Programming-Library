// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

// mete unordered nos de string pra fazer hash. >_<

// chave programa, value suas dependencias.
unordered_map<string, unordered_set<string>> depen;

// chave programa, value programas que dependem dele.
unordered_map<string, unordered_set<string>> neped; // contrário de depen :P


void process(vector<string> inp, int n){
    for(int i = 0; i < n; ++i){
        stringstream iinp (inp[i]);

        string prog;
        iinp >> prog;
        prog.pop_back(); // dois pontos.
        depen[prog]; // caso não tenha dependencias já inicializa.

        string d;
        while(iinp >> d){
            depen[prog].insert(d); // prg depende de d.
            neped[d].insert(prog); // d é dependencia de prog.
        }
    }
}

// baixar ele e desmarcar de todas as dependencias.
void removeall(string p){
    for(auto &ne : neped[p])
        depen[ne].erase(p);

    // não tá mais pra ser baixado.
    depen.erase(p);
}

void solve(vector<string> inp, int n){
    process(inp, n);

    vector<string> ans;

    while(depen.size()){
        // procurar um programa que tenha zero dependencias.
        bool achou = false;
        string r;
        for(auto &dd : depen){
            if(dd.second.size() == 0){
                achou = true;
                r = dd.first;
                break;
            }
        }
        if(achou){
            removeall(r);
            ans.push_back(r);
        }
        else{
            cout << "impossivel\n";
            exit(0);
        }
    }

    for(auto xx : ans)
        cout << xx << ' ';
    cout << '\n';
}
int main(){
    // fastio sempre por favor.
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int n;
    cin >> n;
    cin.ignore();
    vector<string> inputs(n);
    for(int i = 0; i < n; ++i)
        getline(cin, inputs[i]);
    
    solve(inputs, n);
    return 0;
}

// Accepted.