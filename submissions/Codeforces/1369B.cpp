// Não faço a mínima de como rolou isso aqui
#include <bits/stdc++.h>

using namespace std;

string solve(int N, string S)
{
    string ans;
    int l = 0;

    while (l < N and S[l] == '0')
    {
        ans.push_back('0');
        ++l;
    }

    int r = N - 1;

    while (r >= 0 and S[r] == '1')
        --r;

    if (l < r)
        ans.push_back('0');

    for (int i = 0; i < N - 1 - r; ++i)
        ans.push_back('1');
 
    return ans;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        string s;

        cin >> N >> s;

        auto ans = solve(N, s);

        cout << ans << '\n';
    }

    return 0;
}

// Accepted.
