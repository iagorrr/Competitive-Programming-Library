/*
 * iagorrr ;)
 * https://github.com/edsomjr/TEP/blob/master/Paradigmas/slides/complete_search/complete_search.pdf
 * generate every combinatorics of N choose K with repetition, useful to use as the vector index.
 */
#include <bits/stdc++.h>
using namespace std;

void combinations_with_repetition(int n, int k, function<void (const vector<int> &)> process){
    vector<int> v(k, 1);
    int pos = k - 1;

    while (true)
    {
        process(v);

        v[pos]++;

        while (pos > 0 and v[pos] > n)
        {
            --pos;
            v[pos]++;
        }

        if (pos == 0 and v[pos] > n)
            break; 

        for (int i = pos + 1; i < k; ++i)
            v[i] = v[pos];

        pos = k - 1;
    } 
}
void show_vector(const vector<int> &v){
    cout << '(';
    for(auto x : v) cout << ' ' << x;    
    cout << " )\n";
}
int main()
{
    int n, k; cin >> n >> k;
    combinations_with_repetition(n, k, [](const vector<int> &v){show_vector(v);});
}
