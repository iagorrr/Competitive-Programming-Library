// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
vector<vll> kbd;
vll qs;
ll Q;
ll n, m;

ll solve() {
  /*
     x, y, i, m
     x - cordenada x
     y - cordenada y
     i - elemento que to caçando
     m - movimentos que já fiz
  */
  queue<array<ll , 4>> q;
  q.push({0, 0, 0, 0});


  vll vis(1e5+1, -1);

  while(!q.empty()){
    auto [x, y, i, M] = q.front(); q.pop();
    
    // to procurando o i+1
    while(i < Q and kbd[x][y] == qs[i])
      ++i;

    // achei todos !
    if(i == Q) return M;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    M++;
    for(int j = 0; j < 4; ++j) {
      int x2 = x+dx[j];
      int y2 = y+dy[j];
      
      if(x2 >= 0 and y2 >= 0 and x2 < n and y2 < m) {
        ll par = x2*m + y2;

        /*
           se ja tem na fila alguém que
           chegou mais longe eu ignoro.
        */
        if(vis[par] >= i) continue;
        array<ll, 4> tmp{x2, y2, i, M};
        vis[par] = i;
        q.push(tmp);
      }
    }
  }
}
int main() {
   cin >> n >> m;
  kbd = vector<vll>(n+1, vll(m+1));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> kbd[i][j];

  cin >> Q;
  qs = vll(Q+1);
  for(int i = 0; i < Q; ++i)
    cin >> qs[i];
 
  cout << solve() << '\n';
}

// AC, bfs.
