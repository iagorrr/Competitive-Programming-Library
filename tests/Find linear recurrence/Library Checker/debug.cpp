template <typename T>
concept Printable = requires(T t) {
  {
    std::cout << t
  } -> std::same_as<std::ostream &>;
};
template <Printable T>
void __print(const T &x) {
  cerr << x;
}
template <size_t T>
void __print(const bitset<T> &x) {
  cerr << x;
}
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x) {
  bool first = true;
  cerr << '{';
  for (const auto &i : x) {
    cerr << (first ? "" : ","), __print(i);
    first = false;
  }
  cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p) {
  cerr << '(';
  __print(p.first);
  cerr << ',';
  __print(p.second);
  cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t) {
  bool first = true;
  cerr << '(';
  apply(
      [&first](const auto &...args) {
        ((cerr << (first ? "" : ","),
          __print(args), first = false),
         ...);
      },
      t);
  cerr << ')';
}
template <typename T>
void __print(stack<T> s) {
  vector<T> debugVector;
  while (!s.empty()) {
    T t = s.top();
    debugVector.push_back(t);
    s.pop();
  }
  reverse(debugVector.begin(), debugVector.end());
  __print(debugVector);
}
template <typename T>
void __print(queue<T> q) {
  vector<T> debugVector;
  while (!q.empty()) {
    T t = q.front();
    debugVector.push_back(t);
    q.pop();
  }
  __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
  vector<T> debugVector;
  while (!q.empty()) {
    T t = q.top();
    debugVector.push_back(t);
    q.pop();
  }
  __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
  __print(H);
  if (sizeof...(T)) cerr << ", ";
  _print(T...);
}

#define dbg(x...)               \
  cerr << "[" << #x << "] = ["; \
  _print(x)
