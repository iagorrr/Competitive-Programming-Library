// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;

// trie implementation.
using Node = map<char, int>;// caracter naquele nó e posição dele na trie.
using Trie = vector<Node>;
string vogais {"aeiou"};
Trie trie(1);
void build_trie(const string& s){
	int root = 0;
	int next = 0;
	

	// processa de tras pra frente.
	for(int i = (int)s.size(); i >= 0; --i){
		string suffix = s.substr(i); // substring que comeca.
		int v = root;

		for(auto c : suffix){
			auto it = trie[v].find(c);

			// se achar pega o seguinte desse que achou.
			if(it != trie[v].end()){
				v = it->second;
			}
			else{
				trie.push_back({});// novo nó.
				trie[v][c] = ++next; // o nó em que estávamos agora aponta pra mais um char.
				v = next;// estamos agora em uma nova ramificação da trie.
			}
		}
	}	
}

// contar o número de substrings distintas porém só as que começam em vogais.
int solve(const string& s){
	build_trie(s);
	int ans =0;
	queue<int> q;

	// só pode começar em vogais.
	for(auto [c, v] : trie[0]){
		if(vogais.find(c) != string::npos){
			ans++;
			q.push(v);
		}
	}
	while(!q.empty()){
		auto u = q.front(); q.pop();
		
		for(auto [c, v] : trie[u]){
			ans++;
			q.push(v);
		}
	}

	return ans;
}
int main(){
	string s;
	cin >> s;

	cout << solve(s) << '\n';
	return 0;
}

