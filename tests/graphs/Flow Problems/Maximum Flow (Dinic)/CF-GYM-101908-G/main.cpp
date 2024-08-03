#include <bits/stdc++.h>
using namespace std;

#include "../../../../../algorithms/graphs/flow-problems/Maximum Flow (Dinic).cpp"

using vi = vector<int>;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int P, R, C;
	cin >> P >> R >> C;

	vi DS(P);
	for (auto& di : DS)
		cin >> di;

	vi ES(R);
	for (auto& ei : ES)
		cin >> ei;

	using tipin = tuple<int,int,int>;
	vector<tipin> CS(C);
	for (auto& [ti, ii, ji] : CS) {
		cin >> ii >> ji >> ti;
		ii--, ji--;
	}
	sort(CS.begin(), CS.end());
	
	int ans = 1'000'000 +  1;
	const int oo = 1'000'000;
	for (int l = 0, r = 1'000'000+1; l <= r; ) {
		int k = midpoint(l ,r);


		Dinic dinic(R+P+1 + 1);
		int source = R+P, sink = R+P+1;
		
		for (auto [ti, pi, ri] : CS) {
			if (ti > k) break;
			dinic.addEdge(ri, pi + R, oo);
		}

		for (int i = 0; i < R; i++)
			dinic.addEdge(source, i, ES[i]);
		int tot = 0;
		for (int i = 0; i < P; i++) {
			dinic.addEdge(R+i, sink, DS[i]);
			tot += DS[i];
		}

		if (dinic.maxFlow(source, sink) == tot) {
			ans = min(ans, k);
			r = k - 1;
		}
		else l = k + 1;
	}

	if (ans == 1'000'000 + 1)
		ans = -1;

	cout << ans << '\n';
}

/*
	Acho que da pra fazer busca binária na maior aresta
	Dai tenta abastecer geral dando prioridade pras maiores arestas
	Se der vapo

	Deu errado

	Acho que se tiver um caso que a maior aresta X vai consumir tudo de uma refinaria
	que era a unica que abastecia um mano lá com essa única conexão, era melhor
	ter feito pro mano lá com essa única conexão

	E se o guloso for nos postos com menos conexões, resovler eles primeiro

	E se eu rodar um fluxo e ver se deu fluxo máximo ???
	Num da TLE n ?

	E V^2
	2*10^4 * (1000)^2
	2*10^4 * 10^6

	Acho que da ruim né po

	Ou o dinic é o brabo msm
	
	Taporra passou ????

	binary search, flow, dinic
 */


