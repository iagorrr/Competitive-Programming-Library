#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
queue <pair<int, int>> lavaSpread;
map <pair<int,int>, bool> mark;
vector <string> terreno;
    int N, F;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void spreadLava(int y, int x){
        mark[{y, x}] = true; // posicao ja checada.
        int y2, x2;

        for(int i = 0; i < 4; i++){
            y2 = y + dy[i]; x2 = x + dx[i];
            if(min(y2, x2) >= 0 && max(y2,x2) <= N-1){
                if(!mark[{y2, x2}]){
                    if(terreno[y2][x2] <= F+'0' && terreno[y2][x2] != '*'){
                        terreno[y2][x2] = '*';
                        spreadLava(y2, x2);
                    }
                }
            }
        }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> F;
    terreno = vector<string>(N);

    for(int i = 0; i < N; i++)
        cin >> terreno[i];

    if(terreno[0][0] <= F+'0'){
        terreno[0][0] = '*';
        spreadLava(0, 0);
    }
    
    for(int i = 0; i < N; i++)
        cout << terreno[i] << endl;

    return 0;
}

// 80/100