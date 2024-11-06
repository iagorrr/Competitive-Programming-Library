/*8<
  @Warning: if some vertex lies exactly on the line A B, theese vertex will be
  included in teh answer
>8*/
#include "./Determinant.cpp"
#include "./template.cpp"

template <typename T>
vector<Point<T>> leftOfPolygonCut(const vector<Point<T>>& vs, const Point<T>& A,
                                  const Point<T>& B) {
    // Interseção entre a reta AB e o segmento de reta PQ
    auto intersection = [&](const Point<T>& P, const Point<T>& Q,
                            const Point<T>& A, const Point<T>& B) -> Point<T> {
        auto a = B.y - A.y;
        auto b = A.x - B.x;
        auto c = B.x * A.y - A.x * B.y;
        auto u = fabs(a * P.x + b * P.y + c);
        auto v = fabs(a * Q.x + b * Q.y + c);

        // Média ponderada pelas distâncias de P e Q até a reta AB
        return {(P.x * v + Q.x * u) / (u + v), (P.y * v + Q.y * u) / (u + v)};
    };

    vector<Point<T>> points;

    int n = size(vs);
    for (int i = 0; i < n; ++i) {
        auto d1 = determinant(A, B, vs[i]);
        auto d2 = determinant(A, B, vs[(i + 1) % n]);

        // Vértice à esquerda da reta
        if (d1 > -EPS) points.push_back(vs[i]);

        // A aresta cruza a reta
        if (d1 * d2 < -EPS)
            points.push_back(intersection(vs[i], vs[(i + 1) % n], A, B));
    }

    return points;
}
