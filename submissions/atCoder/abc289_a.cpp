// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
const int maxx = 10;
int main(){
    string s; cin >> s;

    bitset<maxx> rs(s);
    rs.flip();

    cout << rs.to_string().substr(maxx-s.size()) << '\n';
   
    return 0;
}
// AC, bitwise, string.
