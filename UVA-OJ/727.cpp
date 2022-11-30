// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

map<char, int> prio;

int priority (char alpha){
    if(alpha == '+' || alpha =='-')
        return 1;
 
    if(alpha == '*' || alpha =='/')
        return 2;
    return 0;
}

string solve(string infix)
{
    int i = 0;
    string postfix = "";
    stack <char>s;

    while(infix[i]!='\0')
    {
        // if operand add to the postfix expression
        if(infix[i] >= '0' and infix[i] <= '9')          
        {
            postfix += infix[i];
            i++;
        }
        // if opening bracket then push the stack
        else if(infix[i]=='(')
        {
            s.push(infix[i]);
            i++;
        }
        // if closing bracket encounted then keep popping from stack until 
        // closing a pair opening bracket is not encountered
        else if(infix[i]==')')
        {
            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
            i++;
        }
        else            
        {
            while (!s.empty() && priority(infix[i]) <= priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
   
    return postfix;
}

int main(){
    prio['/'] = 2;
    prio['*'] = 2;
    prio['+'] = 1;
    prio['-'] = 1;
    prio['('] = -1;
    prio[')'] = -1;

    string s;
    getline(cin, s);

    int t;
    t = stoi(s);

    getline(cin, s);
    while(t--){
        string C;
        string infix;

        while(getline(cin, C)){
            if(C == "") break;

            infix += C;
        }

        cout << solve(infix) << "\n";
        if(t) cout << '\n';
    }
    return 0;
}

// AC
