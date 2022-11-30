// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    while(m--){
        int x, y;
        cin >> x >> y;

        a[x]++;
        a[y]++;
    }

    for(int i = 1; i <= n; ++i) cout << a[i] << '\n';


    return 0;
}

// AC.