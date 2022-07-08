#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK 1000
#define MAXU 10000

using namespace std;

bool cartelas[MAXN][MAXU];
int cnt[MAXN];
vector <int> venceu;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, K, U;
    cin >> N >> K >> U;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int value;
            cin >> value;
            cartelas[i][value] = true;
        }
    }

    for(int i = 0; i < U; i++){
        int value;
        cin >> value;
        for(int j = 0; j < N; j++){
            if(cartelas[j][value]) cnt[j]++;

            if(cnt[j] == K){
                venceu.push_back(j+1);
            }
        }

        if(!venceu.empty()){
            for(int j = 0; j < venceu.size(); j++){
                cout << venceu[j] << " ";
            }
            cout << endl;
            break;
        }
    }


    return 0;
}

// 100/100