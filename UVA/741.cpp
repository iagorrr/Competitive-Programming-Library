/*
    iagorrr ;) O(N) ?
    Reverse the Burrows Wheeler
    https://www.youtube.com/watch?v=ni_w-rdItG8

          1 2 3 4 5 6   
        1 A B A N A N
        2 A N A B A N
        3 A N A N A B
        4 B A N A N A
        5 N A B A N A
        6 N A N A B A

    Given the last one, the first is just it self sorted.

           1 2 3 4 5 6                   
        1 A          N                   
        2 A          N
        3 A          B
        4 B          A
        5 N          A
        6 N          A

    It's possible to reconstruct the matrix using a map, as each char of the right points to the one in left.
    This can be justified by the cyclic propertie of the Burrows Wheeler Transform

            1 2 3 4 5 6                   
        1 A1          N1
        2 A2          N2  
        3 A3          B1  
        4 B1          A1  
        5 N1          A2  
        6 N2          A3

        N1 -> A1
        N2 -> A2
        B1 -> A3
        A1 -> B1
        A2 -> N1
        A3 -> N2
    
    As we have the specific line where our orignal word is symply rebuild it one by one

    4 B1 -> A3 -> N2 -> A2 -> N1 -> A1

    So...

    B A N A N A !!!!!!
*/
#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string solve(string s, int k){
    string ss = s; // s sorted.
    sort(ss.begin(), ss.end());

    // map each character from left to each from right.
    map <char, int> qright;
    map <char, int> qleft;
    map <pair<char, int>, pair<char,int>> ltr;
    vector <pair<char, int>> ans;
    for(int i = 0; i < s.size(); i++){
        //  char     qtd               char          qtd
        ltr[{s[i], ++qright[s[i]]}] = {ss[i], ++qleft[ss[i]]};
        //cout << s[i] << qright[s[i]] << "="  << ss[i] << qleft[ss[i]] << endl;

        if(i == k){
            ans.push_back({ss[k], qleft[ss[k]]});
        }
    }
    for(auto a : ltr){
        // cout << a.first.first << a.first.second << "=" << a.second.first << a.second.second << endl;
    }
    // Just rebuild by pointing to next until reach the size of the string.
    string anss;
    anss.push_back(ans[0].first);
    while(ans.size() < s.size()){
        ans.push_back(ltr[{ans.back().first, ans.back().second}]);
        anss.push_back(ans[ans.size()-1].first);
    }

    return anss; 
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    string s;
    vector <string> ans;
    do{
        cin >> s;
        cin >> k;
        k--;

        if(k >= 0) ans.push_back(solve(s, k));
    }while(s != "END" && k != -1);

    cout << ans[0] << endl;
    for(int i = 1;i < ans.size(); ++i){
        cout << endl << ans[i] << endl;
    }
    return 0;
}

// Accepted.
