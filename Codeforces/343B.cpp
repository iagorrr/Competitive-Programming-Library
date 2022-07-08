#include <bits/stdc++.h>

#define vll vector<long long int>
#define lli long long int
#define ulli unsigned long long int

#define LOOP(I, S, E) for(lli I = S; I < E; I++)
#define LOOPIN(i, E, V) for(lli i = 0; i < E; i++){cin >> V[i];}
#define LOOPOUT(i, E, V) for(lli i = 0; i < E; i++){cout << V[i] << endl;}
#define SWAP(A, B) A ^= B ^= A ^= B
#define TOBIN(I, b) bitset<b>(I).to_string()
#define endl '\n'
#define sws ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

ulli LASTBIT(ulli number){
	long double numberfloat = number;
	ulli result = 0;
	while(true){
		numberfloat = numberfloat/2;
		result++;
		if(numberfloat < 1){
			break;
		}
	}
	return result;
}


ulli negame(ulli number){
    long double numberfloat = number;
    ulli toshift = 0;
    while(true){
        numberfloat = numberfloat/2;
        toshift++;
        if (numberfloat < 1){
            break;
        }
    }
    return (~number)^(ULLONG_MAX<<(toshift));
}

using namespace std;


int main(void){
	sws
	string wires;
    cin >> wires;

    stack <char> check;
    for (auto I : wires){
        if(!check.empty()){
            if(check.top() == I){
                check.pop();
            }
            else{
                check.push(I);
            }
        }
        else{
            check.push(I);
        }
    }

    if(check.empty()){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
	return 0;
}

// Accepted Iagorrr 21.02.2022 
