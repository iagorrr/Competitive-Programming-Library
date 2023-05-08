// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n, k;
    cin >> n >> k;


    vector <string> vs(n);
    for(int i = 0; i < n; ++i){
        cin >> vs[i];
    }   

    string pswd;
    cin >> pswd;
    sort(vs.begin(), vs.end());

    bool found = false;
    ll max=0;
    ll min=0;
    for(int i = 0; i < n; ++i){
        if(vs[i].size() < pswd.size())min++;

        if(vs[i].size() <= pswd.size()) max++;
    }

    min = min + min/k * 5 + 1;
    max = max + (max-1)/k * 5;

    cout << min << " " << max << endl;
    return 0;
}
// Accepted.