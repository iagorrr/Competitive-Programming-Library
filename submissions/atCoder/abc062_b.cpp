// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    vector<string> a(x);
    for(auto &aa : a)
        cin >> aa;

    for(int i= 0; i < y+2; ++i)
        cout << '#';
    cout << '\n';

    for(auto aa : a)
        cout << '#' << aa << "#\n";

    for(int i= 0; i < y+2; ++i)
        cout << '#';
    cout << '\n';
}
// AC.
