// iagorrr ;)
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using  pll = pair<ll,ll>;

/*
    Simplesmente utilizar um 'ponteiro' para a string a, e  outro para b,
    a medida que os valores do ponteiros conincidirem incrementar o de a tambem,
    caso o ponteiro de b chegue ao final é porque b foi totalmente encontrado em a.
*/
inline string solve(const string a, const string b) {
    int posb = 0;

    int i = 0;
    while(i < (int)a.size() and posb < (int)b.size()){
        if(a[i] == b[posb]){
            posb++;
        }
        ++i;
    }
    return posb == (int)b.size() ? "Sim" : "Nao";
}
int main(){
    fast
    string a;
    string b;
    cin >> a;
    cin >> b;
    cout << solve(a, b) << '\n';    
    return 0;
}

