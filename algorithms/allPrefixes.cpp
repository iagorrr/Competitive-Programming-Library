/*
 *
 * Algorith to return a vector of all possible prefixes of a given string.
 * O(N)
 *
 * */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <string> stringPrefixes(const string& s){
    int N = s.size();
    vector <string> ps(N);

    for(int i = 0; i < N; i++){
        ps[i] = s.substr(0, i+1);
    }

    return ps;
}
