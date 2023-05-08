#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    lli N, C;
    cin >> N >> C;

    map <lli, bool> infectado;

    // Mapeando infectados.
    lli infectouprimeiro;
    for(lli i = 0; i < C; i++){
        cin >> infectouprimeiro;
    
        if(!infectado[infectouprimeiro]) infectado[infectouprimeiro] = false;
        lli totalCadeia;
        cin >> totalCadeia;

        for(lli j = 0; j < totalCadeia; j++){
            lli temp;
            cin >> temp;
            infectado[temp] = true;
        }
    }
    
    vector <lli> zeros;
    for(auto paciente : infectado){
        // cout << "P: " << paciente.first << "E: " << paciente.second << endl;
        if(paciente.second == false){
            zeros.push_back(paciente.first);
        }
    }

    sort(zeros.begin(), zeros.end());
    cout << zeros[0] << endl;
    for(lli j = 1; j < zeros.size(); j++){
        cout << zeros[j] << endl;
    }

    return 0;
}

// 100/100
