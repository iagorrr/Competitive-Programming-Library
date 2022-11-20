#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    float ansPrice;
    int ansG;
    float ansPg;
    bool first = true;
    for(int i = 0; i < N; i++){
        float P;
        int G;
        cin >> P >> G;

        float pg = P/G;
        if(first){
            ansPrice = P;
            ansG = G;
            ansPg = pg;
            first = false;
        }
        else {
            if(pg < ansPg){
                ansPg = pg;
                ansPrice = P;
                ansG = G;
            }
        }
    }

    float ans;
    ans = 1000*ansPg;
    printf("%0.2f\n", ans);
    return 0;
}

// 100/100.