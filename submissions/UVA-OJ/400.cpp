// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
string line {"------------------------------------------------------------"};

void solve(vector<string> a, const int n){
    sort(a.begin(), a.end());

    int maxname = 0;
    for(auto x : a)
        maxname = max(maxname, (int)x.size());

    // the longer name define the size.
    int col = (60-maxname) / (maxname+2) + 1; // total char left / total each word shall use.
    int lin = (n-1)/col +1; // total words divided by total column.


    cout << line << '\n';
    // cout << "col : " << col << " lin: " << lin << '\n';
    for(int i = 0; i < lin; ++i){
        for(int j = 0; j < col; ++j){
            int pos = j*lin + i;
            if(pos < n){
                cout << a[pos];
                for(int i = a[pos].size(); i < maxname; ++i)
                    cout << ' ';

                if(j != col-1)
                    cout << "  ";
            }
        }
        cout << '\n';
    }
}
int main(){

    int n;
    while(cin >> n){
        vector<string> a(n);
        
        for(auto &x : a) 
            cin >> x;

        solve(a, n);
    }
        cout << line  << '\n';
    return 0;
}
// AC.
