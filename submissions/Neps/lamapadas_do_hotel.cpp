#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int AA, AB, DA, DB;
    cin >> AA >> AB >> DA >> DB;

    if(AA == DA && DB == AB) cout << 0 << endl;
    else if(AA != DA && AB != DB) cout << 1 << endl;
    else if(AA != DA && AB == DB) cout << 1 << endl;
    else if(AA == DA && AB != DB) cout << 2 <<endl;
    else cout << 2 << endl;
    return 0;
}

// Não corrigido ainda.
