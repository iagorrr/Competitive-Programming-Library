/*
 * iagorrr ;)
 * https://github.com/edsomjr/TEP/blob/master/Paradigmas/slides/complete_search/complete_search.pdf 
 * algorithm to generate the combinatoric n choose k elements, and process each one with a given function.
 */
#include <bits/stdc++.h>
using namespace std;

void process_combinations(int n, int m,  function<void(const vector<char>&)> process){
    vector<char> ns(m, 1);
    ns.resize(n);
    do{
        process(ns);
    }while(prev_permutation(ns.begin(), ns.end()));
}

void show_vector(const vector<char> &p, int N){
    cout << '(';
    for (int i = 0; i < N; ++i) if (p[i]) cout << ' ' << i+1;
    cout << " )\n";
}
int main(){
    int n, k; cin >> n >> k;

    process_combinations(n, k, [n](const vector<char>& p) { show_vector(p, n);});

    return 0;
}
