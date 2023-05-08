// iagorrr O(N)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string a;
    string b;
    cin >> a >> b;
    
    // Achar a maior semelhança entre as duas da direita para a esquerda.
    int ra = a.size()-1;
    int rb = b.size()-1;
    int e = 0;

    while(ra >= 0  && rb >= 0 && a[ra] == b[rb] ){ // sempre checa os limites antes das posições !!!
        ra--;
        rb--;
        e++;
    }

    cout << a.size()-e + b.size()-e << endl;

    return 0;
}

// Accepted.
