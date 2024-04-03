#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1'0'000;
int N, A, B;
pair<int,int> XS[MAXN];

struct point{
	int x, y;
	int id;

	point operator-(const point &o) const{ return {x - o.x, y - o.y}; }
	int operator^(const point &o) const{ return x * o.y - y * o.x; }
};

/*
   	Verify the direction that the point
	_e_ is in relation to the vector
	formed by the points a->b
	-1 = right
	0 = collinear
	1 = left
 */
int ccw(point a, point b, point e){ 
	int tmp = (b-a) ^ (e-a);
	return (tmp > 0) - (tmp < 0);
}

/*
	Verify if the point e
	is inside the triangle formed by 
	the points t1, t2, t3
 */
bool inside_triangle(point t1, point t2, point t3, point e){
	int x = ccw(t1, t2, e);
	int y = ccw(t2, t3, e);
	int z = ccw(t3, t1, e);
	return !((x==1 or y==1 or z==1) and (x==-1 or y==-1 or z==-1));
}


bool is_inside(int u, int v)  {
	auto [xu, yu] = XS[u];
	auto [xv, yv] = XS[v];
	return inside_triangle({A,0}, {B,0}, {xu,yu}, {xv, yv});
}

int memo[MAXN];
int solve(int u) {
	if (memo[u] != -1) return memo[u];
	int ret = 1;

	for (int v = 0; v < N; v++) {
		if (v == u) continue;
		if (is_inside(u, v)) {
			ret = max(ret, solve(v) + 1);
		}
	}

	return memo[u] = ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> B;
	memset(memo, -1, sizeof memo);

	for (int i = 0; i < N; i++) {
		cin >> XS[i].first >> XS[i].second;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, solve(i));
	}

	cout << ans << '\n';


}

// AC, geomery, greddy

/*
	- Escolher um subset maximal dos pontos tal
	que não existe intersecção entre os SEGMENTOS
	de retas que eles formam com a âncora

	> N = 100 !
	> considerar que A vê B se B está dentro do triângulo que 
	A forma ao ser ligado com as âncoras e o eixo X
	> Se um ponto tá no 'campo de visão' do iésimo ponto, eles
	nunca vao ter intersecção

	> acho que faz sentido começar do ponto que consegue
	ver mais pontos
		> a partir dele pega o outro que consegue ver mais...
		? So o ponto A ve o ponto B então A vê todo ponto que 
		B está vendo ???
			> acho que sim né ...
		> Meio que uma DFS né, tá num ponto, checa todos
			> se não estiver dentro ignora
			> cc conta quantos ele ve e armazena
			> dps de saber info sobre todos os filhos vai pro
			que ve mais
			> shablaw !

 */
