// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

void solve(const vector<int> &a, const int n, const int x){
    using ii = pair<int,int>;
    unordered_map<int, set<ii>> vii; 
    unordered_set<int> sums;
    for(int i = 0; i < n; ++i)
        for(int j = i+1; j < n; ++j){
          vii[a[i]+a[j]].insert({i, j});
          sums.insert(a[i]+a[j]);
        }

    
    for(auto s : sums){
        for(auto pii : vii[s]){
            for(auto pjj : vii[x-s]){
                if(pjj.first != pii.first and pjj.first != pii.second and pjj.second != pii.first and pjj.second != pii.second){
                    cout << pii.first + 1 << ' ' << pii.second + 1 << ' ' << pjj.first + 1 << ' ' << pjj.second + 1 << '\n';
                    return;
                }
            }
        }
    }
    

    cout << "IMPOSSIBLE\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;

    vector<int> a(n); 
    for (auto &xx : a) cin >> xx;

    solve(a, n, x);
}

// AC, meet in the middle.
