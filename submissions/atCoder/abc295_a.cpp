// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<string> a{"and", "not", "that", "the", "you"};
    while(n--) {
        string s;
        cin >> s;
        if(a.count(s)) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}
// AC, implementation.
