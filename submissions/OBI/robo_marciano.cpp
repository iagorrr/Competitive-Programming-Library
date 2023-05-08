#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

typedef struct sombra{
    lli x1, y1;
    lli x2, y2;
}Sombra;

int main(){
    lli xi, yi, xf, yf;
    cin >> xi >> yi >> xf >> yf;

    lli N;
    cin >> N;

    // Marcar as posicoes que possúi sombra.
    map <pair<lli,lli>, bool> temSombra;
    vector <Sombra> S;
    Sombra Temp;
    for(int i = 0; i < N; i++){
        cin >> Temp.x1 >> Temp.y1 >> Temp.x2 >> Temp.y2;
        S.push_back(Temp);

        for(lli j = Temp.x1; j < Temp.x2; j++)
            for(lli k = Temp.y1; k < Temp.y2; j++)
                temSombra[{j, k}] = true;
    }



    // x, y, total no sol.
    queue <tuple<lli, lli, lli>> find;
    find.push({xi, yi, 0});
    lli ans = -1;
    while(!find.empty()){
        
    }



    return 0;
}