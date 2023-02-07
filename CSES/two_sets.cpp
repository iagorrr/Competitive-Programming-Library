// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(NULL);

    int n; cin >> n;

    int sa=0, sb=0;
    vector<int> a, b;

    if(n&1){
        for(int i = 1; i <= n-2; i+=4){
            sa += i;
            sa += i+1;
            a.push_back(i);
            a.push_back(i+1);
        }
        for(int i = 3; i <= n-2; i += 4)
        {
            sb += i;
            sb += i+1;
            b.push_back(i);
            b.push_back(i+1);
        }
        b.push_back(n);
        sb += n;
    }
    else{
        int l = 1;
        int r = n;

        while(l < r){
            sa += l+r;
            a.push_back(l);
            a.push_back(r);
    
            l++; r--;
            if(l >= r) break;
            sb += l+r;
            b.push_back(l);
            b.push_back(r);

            l++; r--;
        }
    }
    // cout << sa << ' ' << sb << '\n';
    if(sa == sb){
        cout << "YES\n";
        cout << a.size() << '\n'; for(auto x : a) cout << x << ' ' ; cout << '\n';
        cout << b.size() << '\n'; for(auto x : b) cout << x << ' '; cout << '\n';
    }
    else{
        cout << "NO\n";
    }
}

// AC, math, permutation.
