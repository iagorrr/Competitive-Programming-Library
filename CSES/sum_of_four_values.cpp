// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int> &a, const int n, const int x){
    using ii = pair<int,int>;
    unordered_map<int, set<ii>> vii;
    unordered_set<int> sums;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(i != j){
                vii[a[i]+a[j]].insert({i, j});
                sums.insert(a[i]+a[j]);
            }

    
    for(auto s : sums){
        for(auto pii : vii[s]){
            unordered_set<int> index;
            index.insert(pii.first);
            index.insert(pii.second);
            for(auto pjj : vii[x-s]){
                if(not index.count(pjj.first) and not index.count(pjj.second)){
                    cout << pii.first + 1 << ' ' << pii.second + 1 << ' ' << pjj.first + 1 << ' ' << pjj.second + 1 << '\n';
                    return;
                }
            }
        }
    }
    

    cout << "IMPOSSIBLE\n";
}

int main(){
    int n, x; cin >> n >> x;

    vector<int> a(n); 
    for (auto &xx : a) cin >> xx;

    solve(a, n, x);
}

// AC, meet in the middle.
