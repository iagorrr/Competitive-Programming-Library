// iagorrr ;) O(s.size()*p.size())
#include <bits/stdc++.h>

using namespace std;

vector<int> strong_borders(const string& P)
{
    int m = P.size(), t = -1;
    vector<int> bs(m + 1, -1);

    for (int j = 1; j <= m; ++j)
    {
        while (t > -1 and P[t] != P[j - 1])
            t = bs[t];

        ++t;
        bs[j] = (j == m or P[t] != P[j]) ? t : bs[t];
    }

    return bs;
}

int KMP(const string& S, const string& P)
{
    int n = S.size(), m = P.size(), i = 0, j = 0, occ = 0;

    vector<int> bs = strong_borders(P);

    while (i <= n - m)
    {
        while (j < m and P[j] == S[i + j])
            ++j;

        if (j == m) ++occ;

        int shift = j - bs[j];
        i += shift;
        j = max(0, j - shift);
    } 

    return occ;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int t;
        cin >> t;

        while(t--){
            string p;
            cin >> p;

            cout << (KMP(s, p) != 0 ? 'y' : 'n') << endl;
        }
    }

    return 0;
}

// Accepted.