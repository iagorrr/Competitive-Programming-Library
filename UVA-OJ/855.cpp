// iagorrr ;)
#include <bits/stdc++.h>
#define sws ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using pii = pair<int, int>;

void solve(vector<int> X, vector<int> Y, int f){
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    if(!(f&1))
        f--;

    cout << "(Street: " << X[f/2] << ", Avenue: " << Y[f/2] << ")\n";
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int ax, y, f;
        cin >> ax >> y >> f;
    
        vector<int> X(f), Y(f);
        for(int i = 0; i < f; ++i)
            cin >> X[i] >> Y[i];
        solve(X, Y, f);
    }
}

// AC.
