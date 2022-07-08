#include <bits/stdc++.h>

using namespace std;

struct balance{
    int left;
    int right;
    int previous;
    int operations;
    queue <int> history;
};
typedef struct balance Balance;
int main(){

    int i;
    char cTemp;
    vector <int> weights;
    for(i = 0; i < 10; i++){
        scanf("%c", &cTemp);
        if(cTemp == '1'){
            weights.push_back(i+1);
        }

    }
    int m;
    scanf("%i", &m);

    bool possible = false;
    
    queue <Balance> balanceStates;
    Balance stateTemp;
    stateTemp.left = 0;
    stateTemp.right = 0;
    stateTemp.previous = -1;
    stateTemp.operations = 0;
    balanceStates.push(stateTemp);


    bool possibleWeight;
    balance newState;
    while(!balanceStates.empty()){
        stateTemp = balanceStates.front();
        balanceStates.pop();
        

        if(stateTemp.operations % 2 == 0){// Put in left.
            if(stateTemp.operations == m){
                // printf("ANAL A: %i  %i %i %i\n", stateTemp.left, stateTemp.right, stateTemp.previous, stateTemp.operations);
                if(stateTemp.left < stateTemp.right){
                    printf("YES\n");
                    printf("%i", stateTemp.history.front());
                    stateTemp.history.pop();
                    while(!stateTemp.history.empty()){
                        printf(" %i", stateTemp.history.front());
                        stateTemp.history.pop();
                    }
                    printf("\n");
                    return 0;
                }
            }
            else{
                for(i = 0; i < weights.size(); i++){
                    if((i != stateTemp.previous) && (stateTemp.left + weights[i] >  stateTemp.right)){
                        newState.left = stateTemp.left + weights[i];
                        newState.right = stateTemp.right;
                        newState.previous = i;
                        newState.operations = stateTemp.operations + 1;
                        newState.history = stateTemp.history;
                        newState.history.push(weights[i]);
                        balanceStates.push(newState);
                    }
                }
            }
            
        }
        else{// Put in right;
            if(stateTemp.operations == m){
                // printf("ANAL B: %i %i %i %i\n", stateTemp.left, stateTemp.right, stateTemp.previous, stateTemp.operations);
                if(stateTemp.left > stateTemp.right){
                    printf("YES\n");
                    printf("%i", stateTemp.history.front());
                    stateTemp.history.pop();
                    while(!stateTemp.history.empty()){
                        printf(" %i", stateTemp.history.front());
                        stateTemp.history.pop();
                    }
                    printf("\n");
                    return 0;
                }
            }
            else{
                for(i = 0; i < weights.size(); i++){
                    if((i != stateTemp.previous) && (stateTemp.right + weights[i] >  stateTemp.left)){
                        newState.left = stateTemp.left;
                        newState.right = stateTemp.right + weights[i];
                        newState.previous = i;
                        newState.operations = stateTemp.operations + 1;
                        newState.history = stateTemp.history;
                        newState.history.push(weights[i]);
                        balanceStates.push(newState);
                    }
                }
            }
            
        }
    }

    printf("NO\n");
    return 0;
}