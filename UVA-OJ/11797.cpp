// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

const int ex = 2;
map<string, int> cn;
vector<string> nc {"Ja", "Sam", "Sha", "Sid", "Tan"};
void solve(int M, int N, int f, deque<deque<int>> lists){
    int cm = 0;

    vector<int> ans(5, 0);
    int css = f;
    while(cm <= N){
        // sum the time that the css will stay.
        ans[css] += cm + M < N ? M : M - ((cm+M) - N);
        
        // invert the seats.
        int prev = css;
        css = lists[css].front();

        // update the previous list.
        int temp = lists[prev].front();
        lists[prev].pop_front();
        lists[prev].push_back(temp);

        cm += M + 2; // time spent including exchange.
    }

    // print each one.
    for(int i = 0; i < 5; ++i){
        cout << nc[i] <<  ' ' << ans[i] << '\n';
    }
}
int main(){
    cn["Ja"] = 0;
    cn["Sam"] = 1;
    cn["Sha"] = 2;
    cn["Sid"] = 3;
    cn["Tan"] = 4;


    int t;
    cin >> t;

    for(int i = 0; i < t; ++i){
        int M, N, f;
        string namef;
        cin >> M >> N >> namef;

        f = cn[namef];
        deque<deque<int>> lists(5);

        for(int j = 0; j < 5; ++j){
            int k;
            cin >> k;

            for(int l = 0; l < k; ++l){
                string a;
                cin >> a;

                lists[j].push_back(cn[a]);
            }
        }

        cout << "Case " << i+1 << ":\n";
        solve(M, N, f, lists);
    }

    return 0;
}

// AC.

