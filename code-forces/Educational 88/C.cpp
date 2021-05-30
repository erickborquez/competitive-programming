#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;
long double h, c, t, m, best = 1000000;

bool upper(long double n)
{
  // deb(n);
  long double total = ((long double)(n) * (h + c) + h) / (long double)(n * 2 + 1);
  // deb(total);
  return total > t;
}
bool lower(long double n)
{
  // deb(n);
  long double total = ((long double)(n) * (h + c) + h) / (long double)(n * 2 + 1);
  // deb(total);
  return total < t;
}

int main()
{
  IO;
  int p;
  cin >> p;
  while (p--)
  {
    cin >> h >> c >> t;
    m = (h + c) / 2;
    if (t == h)
    {
      cout << 1 << ENDL;
      continue;
    }
    if (t <= m)
    {
      cout << 2 << ENDL;
      continue;
    }
    int ptr = 0;
    for (int i = 100000000; i > 0; i /= 2)
    {
      while ((ptr + i) > 0 && upper(ptr + i))
        ptr += i;
    }
    long double firstAbs = abs(t - (long double)(ptr * (h + c) + h) / (long double)(2 * ptr + 1));
    long double first = ptr;

    ptr = 100000000;
    for (int i = 100000000; i > 0; i /= 2)
    {
      while ((ptr - i) > 0 && lower(ptr - i))
        ptr -= i;
    }

    long double secondAbs = abs(t - (long double)(ptr * (h + c) + h) / (long double)(2 * ptr + 1));
    long double second = ptr;
    if (firstAbs > secondAbs)
      cout << second * 2 + 1 << ENDL;
    else
      cout << first * 2 + 1 << ENDL;
  }
  return 0;
}