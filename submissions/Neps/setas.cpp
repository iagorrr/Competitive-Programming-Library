#include <bits/stdc++.h>

using namespace std;

int N;
int answer;
vector <vector<char>> table;
map <pair<int,int>, bool> check;
map <pair<int, int>, bool> safe;

bool dfs(int x, int y){
    // Check if overflow the table.
    if(y < 0 || y >= N || x < 0 || x >= N) return false;

    // If is already checked return the previous result.
    if(check[{x, y}]) return safe[{x, y}];

    check[{x, y}] = true;
    safe[{x, y}] = true;

    int x2, y2;
    x2 = x;
    y2 = y;
    switch (table[x][y]){
        case('>'): y2++; break;
        case('<'): y2--; break;
        case('V'): x2++; break;
        case('A'): x2--; break;
    }



    return safe[{x, y}] = dfs(x2, y2);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cin.tie(0);

    cin >> N;
    table = vector <vector<char>>(N, vector<char>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> table[i][j];

    answer = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            // Not checked yet.
            if(!check[{i, j}])
                dfs(i, j);
            
            answer += safe[{i, j}];
        }
    }

    cout << answer << endl;
    return 0;
}

// Accepted.
