/*8<
  @Time: $O(N)$
>8*/
template<typename T>
double ccRadius(const Point<T>& A, const Point<T>& B, const Point<T>& C) {
	return (B-A).dist()*(C-B).dist()*(A-C).dist()/
			abs((B-A).cross(C-A))/2;
}

template<typename T>
Point<T> ccCenter(const Point<T>& A, const Point<T>& B, const Point<T>& C) {
	Point<T> b = C-A, c = B-A;
	return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

template<typename T>
pair<Point<T>, double> mec(vector<Point<T>> ps) {
	shuffle(all(ps), mt19937(time(0)));
	Point<T> o = ps[0];
	double r = 0, EPS = 1 + 1e-8;
	rep(i,0,len(ps)) if ((o - ps[i]).dist() > r * EPS) {
		o = ps[i], r = 0;
		rep(j,0,i) if ((o - ps[j]).dist() > r * EPS) {
			o = (ps[i] + ps[j]) / 2;
			r = (o - ps[i]).dist();
			rep(k,0,j) if ((o - ps[k]).dist() > r * EPS) {
				o = ccCenter(ps[i], ps[j], ps[k]);
				r = (o - ps[i]).dist();
			}
		}
	}
	return {o, r};
}
