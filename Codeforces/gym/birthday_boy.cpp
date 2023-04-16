
// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)        \
  for (auto &xxx : xxxx) \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out()
{
  cerr << endl;
}
template <typename H, typename... T>
void dbg_out(H h, T... t)
{
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                 \
  {                              \
    cerr << #__VA_ARGS__ << ':'; \
    dbg_out(__VA_ARGS__);        \
  }

vector<int> days_month{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
array<int, 365> year;

pii daytodate(int x)
{
  int curday = 0;
  for (int i = 1; i <= 13; ++i)
  {
    for (int j = 1; j <= days_month[i]; ++j)
    {
      if (curday + j == x)
      {
        return make_pair(i, j);
      }
    }
    curday += days_month[i];
  }
}
int datetoday(pii x)
{
  // converts a day-month to the day in the year.
  int day = 0;
  for (int i = 1; i <= x.fst - 1; ++i)
  {
    day += days_month[i];
  }
  day += x.snd;
  return day;
}

int calcdist(int x, int y)
{
  // sair y ->>> x
  if(x > y) {
    return x - y;
  }
  else {
    return 365-y+x;
  }
}
int calcclose(int x)
{
  int original = datetoday(make_pair(10, 27));
  if (original > x)
  {
    return 365 - original + x;
  }
  else
  {
    return x - original;
  }
}
void run()
{
  int n;
  scanf("%d", &n);
  if (n == 1)
  {
    char foo[30];
    scanf("%s", foo);
    int day, month;
    scanf("%d-%d", &month, &day);
    int x = datetoday({month, day});
    x = x == 1 ? 365 : x - 1;
    auto [m, d] = daytodate(x);
    printf("%d%d-%d%d\n", m / 10, m % 10, d / 10, d % 10);
    return;
  }
  vi yearday(n);
  vector<pii> monthday(n);

  for (int i = 0; i < n; ++i)
  {
    char foo[30];
    scanf("%s", foo);
    int day, month;
    scanf("%d-%d", &month, &day);
    monthday[i].first = month;
    monthday[i].second = day;

    int aaa = datetoday(monthday[i]);
    yearday[i] = aaa;
    year[aaa - 1] = 1;
  }

  sort(all(monthday));
  sort(all(yearday));

  
  int curans = -1;
  int distans = -1;
  int lastbd = yearday.back();
  for (int i = 1; i <= 365; ++i)
  {
    if (year[i - 1])
    {
      lastbd = i;
      continue;
    }
    if (i == datetoday({10, 27}))
      continue;

  
    auto curdist = calcdist(i, lastbd);
    auto curclose = calcclose(i);
    if(curans == -1) {
      curans = i;
      distans = calcdist(i, lastbd);
      continue;
    }
    // printf("%d-%d: ", daytodate(i).fst, daytodate(i).second); dbg(curdist);
    if (curdist > distans)
    {
      curans = i;
      distans = curdist;
    }
    else if (curdist == distans)
    {
      if (curclose < calcclose(curans))
      {
        curans = i;
        distans = curdist;
      }
    }
  }

  auto [mes, dia] = daytodate(curans);
  printf("%d%d-%d%d\n", mes / 10, mes % 10, dia / 10, dia % 10);
}
int32_t main(void)
{
  int t;
  t = 1;

  // int a = datetoday({12, 31});
  // int b = datetoday({1, 1});
  // cout << a << ' ' << b << '\n';

  // cout << calcdist(a, b) << '\n';
  // return 0;
  while (t--)
    run();
}

// WA, on test 10