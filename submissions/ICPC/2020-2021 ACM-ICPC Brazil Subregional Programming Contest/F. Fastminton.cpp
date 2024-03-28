/*
	- melhor de três
	- cada game ganho quando faz pelo menos 5 pontos, com
	2 pontos de diferença, ou alcançando 10
	- left começa o primeiro game, nos demais quem ganhou
	começa
	- o ponto vai pro 'server' ou pro 'receiver'

	- S: server
	- R: receiver
	- Q: score/query
	- sempre que for Q printa o score atual
	- "GL (PL) - GR (PR)
	- "GL - GR" with the string "(winner)"
	-  An asterisk (*) must be appended to the point marked
       	of the player that will serve in the next round. so 
	vale quando pergunta imediatamenta pós acabar o round ?
*/
#include <bits/stdc++.h>
using namespace std;

int get_winner(vector<int> &pts, int server) {
	if (pts[server] == 10) return server;
	if (pts[!server] == 10) return !server;

	if (pts[server] >= 5 and pts[server] - 2 >= pts[!server])
		return server;
	if (pts[!server] >= 5 and pts[!server] - 2 >= pts[server])
		return !server;

	return -1;
}



void query(vector<int> &pts, vector<int> &games, int server, int i, int n) {
	if (i == n - 1) {
		cout << games[0] << ' ';
		if (games[0] > games[1])
			cout << "(winner)";
		cout << " - " << games[1] << ' ';
		if (games[0] < games[1])
			cout << "(winner)";
		cout << '\n';
		return;
	}

	cout << games[0];
	cout << " (" << pts[0];
	if (server == 0)
		cout << "*";
	cout << ")";
	cout << " - ";
	cout << games[1];
	cout << " (" << pts[1];
	if (server == 1)
		cout << "*";
	cout << ")";
	cout << "\n";

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	int server = 0;
	vector<int> pts(2), games(2);
	pts[0] = pts[1] = games[0] = games[1] = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];
		if (c == 'Q') {
			query(pts, games, server, i, (int)s.size());
			continue;
		}

		if (c == 'S') {
			pts[server]++;
		}
		else {
			pts[!server]++;
			server = !server;
		}

		int winner = get_winner(pts, server);
		if (winner != -1) {
			games[winner]++;
			pts[0] = pts[1] = 0;
		}
	}
}
