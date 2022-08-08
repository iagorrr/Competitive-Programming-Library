// iagorrr ;) O(N^2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int N, M;
vector <string> A(50);
vector <string> B(50);

string solve(){

    for(int i = 0; i <= N-M; ++i){
        for(int j = 0; j <= N-M; ++j){
            if(A[i].substr(j, M) == B[0]){
                int cnt = 0;
                int k = i;
                while(cnt < M && k < N && A[k].substr(j, M) == B[cnt]){++k; ++cnt;}

                if(cnt == M) return "Yes";
            }
        }
    }

    return "No";
}
int main(){
    fast
    cin >> N >> M;

    for(int  i = 0; i < N; ++i) cin >> A[i];

    for(int i = 0; i < M; ++i) cin >> B[i];

    cout << solve() << endl;

    return 0;
}

// Accepted.
