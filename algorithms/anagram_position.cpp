/*
    Algorithm to find the position of an anagram, still not the best solution.

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

ull totalPermutations(string s){
    ull ans = 1;
    map <char, int> h; // Histogram to remove the repetitions.
    for(int i = 0; i < s.size(); ++i){
        ans *= (i+1);
        h[s[i]] ++;
    }

    for(auto i : h){
        ans /= fastFat(i.second);        
    }

    return ans;
}

// Function that returns the position of an anagram s between all permutations.
ull anagramPosition(string s){
    // Find the sorted anagram is the first.
    string ss = s;
    sort(ss.begin(), ss.end());

    ull ans = 0;
    ull p = 0;
    while(!ss.empty()){
        unsigned int i = 0;
        while(i < ss.size()){
            if(ss[i] == s[p]){
                // cout << ss[i] << " YES." << endl;
                break;
            } 
            else {
                string tempstr = ss;
                tempstr.erase(tempstr.begin() + i);
                ans += totalPermutations(tempstr);
                // cout << ss[i] << " NO. Sum : " << totalPermutations(tempstr) << endl;
                char temp = ss[i];
                while(ss[i] == temp) i++;
            }
        }
        ss.erase(ss.begin()+i);
        p++;
    }
    return ans;
}

void showEveryAnagram(string s){
    sort(s.begin(), s.end());
    map<string,bool> check;
    ull i = 0;
    do{
        if(!check[s]) cout << i << " " <<  s << endl , ++i;

    }
    while(next_permutation(s.begin(), s.end()));
}

int main(){
    string s;
    cin >> s;
    showEveryAnagram(s);
    cout << anagramPosition(s) << endl;
    return 0;
}
