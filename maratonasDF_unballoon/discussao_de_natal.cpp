// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans(2*1e5);
int hmax;
void dfs(const vector<pair<int, int>> &tree, int n, int no, int h){
    hmax= max(h, hmax);

    ans[h].push_back(no);

    if(tree[no].first)
        dfs(tree, n, tree[no].first, h+1);

    if(tree[no].second)
        dfs(tree, n, tree[no].second, h+1);
}
void solve(const vector<pair<int, int>> &tree, int n){
    dfs(tree, n, 1, 0); 

    // output.
    cout << hmax+1 << '\n';
    for(int i = 0; i <= hmax; ++i)
        cout << ans[i].front() << ' ';
    cout << '\n';

    for(int i = 0; i <= hmax; ++i)
        cout << ans[i].back() << ' ';

    cout << '\n';
    
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hmax = -1;

    int n;
    cin >> n;

    vector<pair<int,int>> tree(n+1); // chave pai, first esquerda second direita.
    for(int i = 0; i < n; ++i){
        int p, l, r;
        cin >> p >> l >> r;

        tree[p].first = l;
        tree[p].second = r;
    }

    solve(tree, n);
    return 0;
}

// Accepted.
