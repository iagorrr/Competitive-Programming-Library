// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    /*
        Se for maior do que 5 tentar pegar o 5 ou 0 mais a esquerda possível, aumentar o número.
    */
   if(a[n-1] > 5){
        for(int i = 0; i < n; ++i){
            if(a[i] == 5 || a[i] == 0){
                int temp = a[i];
                a[i] = a[n-1];
                a[n-1] = temp;
                break;
            }
        }
   }
   else{// se for menor ou igual a 5 tentar trocar pelo o 0 mais a esquerda, aumentar o número.
        bool achou = false;
        for(int i = 0; i < n; ++i){
            if(a[i] == 0){
                int temp = a[i];
                a[i] = a[n-1];
                a[n-1] = temp;
                achou = true;
                break;
            }
        }

        // se não tiver nem um 0, pegar o 5 mais a direita, vai reduzir menos o número.
        if(!achou){
            for(int i = n -1; i >= 0; --i){
                if(a[i] == 5){
                int temp = a[i];
                a[i] = a[n-1];
                a[n-1] = temp;
                achou = true;
                break;
                }
            }
        }
   }

    if(a[n-1]%5 != 0){
        cout << -1 << '\n';
    }
    else{
        cout << a[0];
        for(int i = 1; i < n; ++i) cout << ' ' << a[i];
        cout << '\n';
    }

    return 0;
}

// Aceito 100/100