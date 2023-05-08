#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string solve(int N, int M, int, const string& s, const vector<string>& xs, ll P)
{
    queue<int> is;
    for (int i = 0; i < N; ++i)
        if (s[i] == '#')
            is.push(i);
    ll total = 1;
    string ans(s);
    int pos = 0;
    for (int i = M - 1; i >= 0; --i)
    {
        total *= xs[i].size();
        if (total > P)
        {
            pos = i;
            for (int j = 0; j < i; ++j)
            {
                ans[is.front()] = xs[j].front();
                is.pop();
            }
            break;
        }
    }
//cout << "-- pos = " << pos << ", M = " << M << ", total = " << total << '\n';
    for (int i = pos; i < M; ++i)
    {
        if (P == 0)
        {
            ans[is.front()] = xs[i].front();
            is.pop();
            continue;
        }
        int size = (int) xs[i].size();
        total /= size;
        int a = 0, b = size - 1;
        bool ok = false;
//cout << "++ total = " << total << ", P = " << P << '\n';
        while (a <= b)
        { 
            auto m = a + (b - a)/2;
//cout << "-> m = " << m << '\n';
            if ((m + 1)*total < P)
            {
//cout << "### aqui\n";
                a = m + 1;
            } else
            {
                ans[is.front()] = xs[i][m];
                is.pop();
                P -= m*total;
                ok = true;
                break;
            }
        }
        if (not ok)
        {
            ans[is.front()] = xs[i].front();
            is.pop();
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    string s;
    cin >> s;
    vector<string> xs;
    for (int i = 0; i < M; ++i)
    {
        string w;
        cin >> w;
        set<char> S(w.begin(), w.end());
        xs.emplace_back(string(S.begin(), S.end()));
    }

    ll P;
    cin >> P;
    auto ans = solve(N, M, K, s, xs, P);
    cout << ans << '\n';
    return 0;
}