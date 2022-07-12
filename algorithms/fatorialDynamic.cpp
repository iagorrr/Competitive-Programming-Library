/*
    Algorithm to calculate fatorial using dynamic programming.
    The great advantage of this one is for cases that require the same, or close values a lot of time.

    O(n)  
*/
#include <bits/stdc++.h>
#define MAX 250

using namespace std;
using ll = long long;
using ull = unsigned long long;

vector <ull> fatAns(MAX, 0); 

ull fastFat(int n){
    if(fatAns[n]) return fatAns[n];
    fatAns[n] = n * fastFat(n-1);
    return fatAns[n];

}

int main(){
    fatAns[0] = 1;
    int n;
    cin >> n;
    cout << fastFat(n) << endl;
}
