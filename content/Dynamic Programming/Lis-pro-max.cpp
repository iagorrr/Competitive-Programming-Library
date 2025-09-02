/*
@Description:  Just a regular lis, but very quick to code
 * */

multiset<int> s;
for (int i = 0; i < n; i++) {
    auto it = s.upper_bound(a[i]);
    if (it != s.end()) s.erase(it);
    s.insert(a[i]);
}
lis = len(s);
