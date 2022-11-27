// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

string solve(string s, const int B, const int D){
	// chechar se e tudo zero.
	bool zero = s.find('1') == string::npos ? true : false;

	if(zero)
		return string(B, '0');

	// tudo a esquerda como zero.
	string ans = string(B-D, '0') + s;

	// negar.
	for(auto &c : ans)
		c = c == '1' ? '0' : '1';

	// somar 1. (colocar tudo a esquerda como zero até achar o primeiro zero)
	for(int i = B-1; i >= 0; --i){
		if(ans[i] == '1') 
			ans[i] = '0';
		else{
			ans[i] = '1';
			break;
		}
	}
	
	// igonorar os zeros a esquerda.
	auto p = ans.find('1');
	return p == string::npos ? ans : ans.substr(p);
}


int main(){
	int B, D;
	cin >> B >> D;

	string s;
	cin >> s;
	
	cout << solve(s, B , D) << '\n';
	return 0;
}
