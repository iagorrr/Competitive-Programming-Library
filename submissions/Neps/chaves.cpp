#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    lli N;
    cin >> N;

    char codigo[N][102];
    for(int i = 0; i < N; i++) fgets(codigo[i], 102, stdin);

    stack <char> balance;
    for(lli i = 0; i < N; i ++){
        for(lli j = 0; j < strlen(codigo[i]); j++){
            if(codigo[i][j]=='{'){
                balance.push('{');
            }
            else if(codigo[i][j] == '}'){
                if(!balance.empty() && balance.top() == '{'){
                    balance.pop();
                }
                else{
                    cout << 'N' << endl;
                    return 0;
                }
            }
        }
    }

    if(balance.empty()) cout << 'S' << endl;
    else cout << 'N' << endl;
    return 0;
}

// Não corrigido ainda.
