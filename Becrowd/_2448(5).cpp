#include <bits/stdc++.h>

#define vll vector<long long int>
#define lli long long int


#define LOOP(I, S, E) for(lli I = S; I < E; I++)
#define LOOPIN(i, E, V) for(lli i = 0; i < E; i++){cin >> V[i];}
#define LOOPOUT(i, E, V) for(lli i = 0; i < E; i++){cout << V[i] << endl;}
#define SWAP(A, B) A ^= B ^= A ^= B
#define endl '\n'
#define sws ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
using namespace std;



int main(void){
	sws

    // Declaring and receving max.
    lli nHouses;
    lli nOrders;
    cin >> nHouses >> nOrders;

    // Declaring, receiving and mapping houses.
    vll houses(nHouses);
    map <lli , lli> housesOrder;
    LOOP(i, 0, nHouses){
        cin >> houses[i];
        housesOrder[houses[i]] = i+1; // the position of each house.
    }

    // Declaring and receiving orders.
    vll orders(nOrders);
    LOOP(i, 0, nOrders){
        cin >> orders[i];
    }

    // Finding how much the postman will need to walk.
    lli totalDistance = 0;
    lli currentPosition = 1;
    LOOP(i, 0, nOrders){
        if (currentPosition == housesOrder[orders[i]]){
            continue;
        }
        else{
            if (housesOrder[orders[i]] - currentPosition < 0){
                totalDistance += currentPosition - housesOrder[orders[i]];
            }
            else{
                totalDistance += housesOrder[orders[i]] - currentPosition;
            }
            currentPosition = housesOrder[orders[i]];
        }
    }

    cout << totalDistance << endl;
	return 0;
}

// Accepted Iagorrr 11.02.2022
