/*
 *	Algorith based into avail the last hash calculus.
 *	The first one is O(N), and from there until endis O(1).
 *  
 *  Part of the difference is because we calculate the hash of all prefixes firt.
 *  Very useful to calculate unique substrings.
 *  Decrease the time compexity from N^3 logN to N^2logN, because set now is comparing integers not strings.
 */
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll p = 53, q = 1000000007;

/*
 * Match each character to a number, in this case :
 * a b c d e f g h i j k l m n o p q r s t u v x y z
 * 1 2 3 4 5 6 7 8 9 ......
 * */
int f(char c){
    return c - 'a' + 1;
}

int ihash(const string& s){
    ll ans = 0;

    for(auto it = s.rbegin(); it != s.rend(); ++it){
        ans = (ans * p) % q;
        ans = (ans + f(*it)) % q;
    }

    return ans;
}

vector<ll> prefixesHash(const string& s){
    int N = s.size();
    vector <ll> psh(N, 0);

    //  Find the hash of each prefix.
    for(int i = 0; i < N; ++i) psh[i] = ihash(s.substr(0, i+1));

    return psh;
}

ll fastExpMod(ll a, ll b){
    ll ans = 1;
    ll base = a;

    while(b){
        if(b & 1) ans = (ans*base) % q;

        base = (base * base) % q;
        b >>= 1;
    }

    return ans;
} 

// Returns the multiplicative inverse necessary to the calculus.
vector <ll> inverses(ll N){
    vector <ll> is(N);
    ll  base = 1;

    for(int i = 0; i < N; ++i){
        is[i] = fastExpMod(base, q-2);
        base = (base * p) % q;
    }

    return is;
}

// Hash based into the previous values calculed.
int hash2(int i, int j, const vector<ll> &ps, const vector<ll> &is){
    auto diff = i ? ps[j] - ps[i-1] : ps[j];
    diff = (diff * is[i]) % q;
    
    return (diff + q) % q;
}

int uniqueSubstrings(const string& s){
    set <ll> hs; // store the set of each string.
    int N = s.size();
    auto ps = prefixesHash(s);
    auto is = inverses(s.size());
    
    // pass through all substrings broo.
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            auto hij = hash2(i, j, ps, is);
            hs.insert(hij);
        }
    }
    
    // total of elements, set only allow one of each.
    return hs.size();
}

int main(){
    cout << uniqueSubstrings("tep") << endl;
    cout << uniqueSubstrings("aaaaa") << endl;
    cout << uniqueSubstrings("banana") << endl;
    cout << uniqueSubstrings("thisisharderthanlooks") << endl;
    cout << uniqueSubstrings("tomalucooooooo") << endl;
    return 0;
}
