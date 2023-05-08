// iagorr ;)
#include <bits/stdc++.h>
using namespace std;

inline string solve(const int a, const int b, const int c){

    if(a + b == c) return "YES";
    if(b+c == a) return "YES";
    if(a+c == b) return "YES";
    return "NO";
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        cout << solve(a, b, c) << '\n';
    }
    return 0;
}

// Accepted.