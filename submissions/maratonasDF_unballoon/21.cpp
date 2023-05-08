// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
map<char,int> v;


int main(){ 
    fastio
    v['J'] = 10;
    v['T'] = 10;
    v['Q'] = 10;
    v['K'] = 10;
    v['A'] = 1;

    ll maxans = -1;
    deque<int> cartas;

    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 13; ++j){
            string carta;
            cin >> carta;

            if(!(carta[0] >= '2' and carta[0] <= '9')) 
                cartas.push_back(v[carta[0]]);
            else
                cartas.push_back(carta[0] - '0');
        }
    }

    ll hand = cartas.front();
    cartas.pop_front();
    hand += cartas.front();
    cartas.pop_front();

    while(!cartas.empty() and hand + cartas.front() <= 21){
        hand += cartas.front();
        cartas.pop_front();
    }

    cout << hand << '\n';
    return 0;
}
