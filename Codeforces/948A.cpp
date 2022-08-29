// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h, w;
    cin >> h >> w;

    vector <string> past(h);
    for(int i = 0; i < h; ++i){
        cin >> past[i];    
    }

    // check if there is a wolf close to a shep.
    bool possible = true;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(past[i][j] == 'S'){
                vector <int> di {1, -1, 0, 0};
                vector <int> dj {0, 0, -1, 1};

                for(int k = 0; k < 4; k++){
                    int i2 = i + di[k];
                    int j2 = j + dj[k];
                    if(i2 >= 0 and i2 < h and j2 >= 0 and j2 <= w and past[i2][j2] == 'W'){
                        possible = false;
                    }
                }
            }
        }
    }

    if(possible){
        cout << "Yes" << endl;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                cout << (past[i][j] == '.' ? 'D' : past[i][j]);
            }
            cout << endl;
        }
        cout << endl;
    }
    else cout << "No" << endl;
    return 0;   
}

// AC.