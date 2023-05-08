// iagorr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> move;
        vector<int> checkc(n+1, 0);
        vector<int> checkr(n+1, 0);
        map<pair<int,int>, bool> exist;
        int d = 0;
        bool mate = false;
        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;
            move.push_back({x,y});
            exist[{x, y}] = true;

            checkc[x]++;
            checkr[y]++;
        }

        bool ans = false;
        for(auto [x, y] : move){
            for(int i = 1; i <= n; ++i){
                if(checkc[x] == 1 and checkr[i] == 0 and i != y and not exist[{x, i}]){
                    ans = true;
                    break;
                }

                if(checkr[y] == 1 and checkc[i] == 0 and i != x and not exist[{i, y}]){
                    ans = true;
                    break;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}

// Accepted.
