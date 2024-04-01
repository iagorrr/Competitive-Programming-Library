#include <bits/stdc++.h>
using namespace std;

void ask(int x, int y) {
	cout << "? " << x << ' ' << y << '\n';
	cout.flush();
}

void answer(int x, int y) {
	cout << "! " << x << ' ' << y << '\n';
	cout.flush();
}

void solve() {
	int n, m;
	cin >> n >> m;

	ask(1, 1);
	int d1;
	cin >> d1;

	int bx, by; // bottom x, bottom y
	if (d1 < n-1){
		bx = 1 + d1;
		by = 1;
	}
	else {
		bx = n;
		by = 2 + d1 - n;
	}
	int sd = min(m-by+1, bx);

	int tx, ty; // top x, top y
	tx = bx - (sd - 1);
	ty = by + (sd - 1);

	int db; // distance from top
	ask(bx, by);
	cin >> db;

	int dt; // distance from top
	ask(tx, ty);
	cin >> dt;

	if (!(db&1)) { // may be from the bottom
		int d = db / 2;
		int mayx = bx - d, mayy = by + d;
		ask(mayx, mayy);
		int fd;
		cin >> fd;
		if (fd == 0) {
			answer(mayx, mayy);
		}
		else {
			answer(tx + dt/2, ty - dt/2);
		}

	}
	else { // it's for sure at top
			answer(tx + dt/2, ty - dt/2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}

/*
   	> AC, greddy

	- 4 queries
	- find ONE OF the mines

	> make a query from (1, 1), let the response be d1
		> then you will be SURE that there is a mine at the
		d1-th 'diagonal', we will find the exact position in
		the diagonal by making a query at the bottom of the 
		diagonal (bx, by) and at the top (tx, ty)
		> note that the distance from (bx, by) or (tx, ty) will
		always be even as is in the same diagonal, so if some of
		them is odd than the distance from the other will be
		correct
		> buuut, if both of them are even let's say that the distance
		from (bx, by) to a mine is db and the distance from (tx, ty)
		to a mine is dt, you can simply verify if the db-th cell
		counting from bottom is with distance 0 to mine, then the
		answer will be it, otherwise we take the dt-th cell counting
		from (tx,ty) down.



	> faz querie na 1, 1
		> vai dar que uma das bombas
		vai estar na diagonal
			> seja db a querie na parte mais
			baixa de diagonal
			e da a querie no ponto mais alto
				> se um dos dois forem impar
				tu pega o que tiver par e faz
				o calculinho de distancia
				> se os dois forem par ???
					> faz a querie onde tu acha
					que seria o o ponto 
					considerando ou o de cima
					ou o de baixo
					se o que tu fizer der 0 perfeito
					se não é o oposto do que tu cnsiderou
 */
