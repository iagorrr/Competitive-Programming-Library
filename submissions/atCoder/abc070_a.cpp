// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;

    int l = 0; int r = (int)s.size()-1;

    while(l < r)
    {
        if(s[l] != s[r])
        {
            cout << "No\n";
            return 0;
        }
        l++; r--;
    }

    cout << "Yes\n";
}

// AC.

