// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<pair<int,int>> a, int n)
{
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    
    int current = 0;
    int job = 0;

    for(int i = 0; i < n; ++i)
    {

        current += a[i].second;

        job = max(max(0, job-a[i].second), a[i].first);
    }
   
    return current + job;
}

int main()
{
    int n;
    int i = 1;
    do
    {
        cin >> n; if(n == 0) break;
        vector<pair<int,int>> a(n); for(int j = 0; j < n; ++j){ cin >> a[j].second >> a[j].first; } 

        cout << "Case " << i++ << ": " << solve(a, n) << '\n';
    }while(true);

}

// AC, greedy.
