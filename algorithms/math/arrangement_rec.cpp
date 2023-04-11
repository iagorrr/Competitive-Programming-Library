/*
 * iagorrr ;)
 * generate every arrangement of a vector.
 */
#include <bits/stdc++.h>
using namespace std;

void combinations_with_repetition(const int k, int c, vector<int> &v, 
                                  const vector<int> &xs, function<void(const vector<int> &)> process){
    if(k == c){
        process(v);
        return;
    }

    for (auto x : xs){
        v.push_back(x);
        combinations_with_repetition(k, c+1, v, xs, process);
        v.pop_back();
    }
}
void show_vector(const vector<int> &v){
    cout << '(';
    for(auto x : v)
        cout << ' ' << x;
    cout << " )\n";
}
int main()
{
    int n, k;
    n = 3; k = 2;
    vector<int> xs(n);
    iota(xs.begin(), xs.end(), 1);
    vector<int> v;    
    combinations_with_repetition(k, 0, v, xs, [](const vector<int> &p){show_vector(p);});
}
