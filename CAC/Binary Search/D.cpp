#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
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

ld DELTA = 1e-4;
ld INF = 1e18;

vector<ld> s;

ld ok(ld u)
{
  ld acc = 0;
  for (auto e : s)
  {
    if (e > u)
    {
      acc += e - u;
    }
    else
    {
      acc += u - e;
    }
  }
  return acc;
}

int main()
{
  IO;

  int tc;
  cin >> tc;
  while (tc--)
  {

    int n;
    ld k;
    cin >> n >> k;
    s.resize(n);
    ld mx = -1;
    FOR(i, 0, n)
    {
      cin >> s[i];
      mx = max(mx, s[i]);
    }
    ld ptr = 0;
    for (ld i = mx; i > DELTA; i /= 2.0)
    {
      while (ok(i + ptr) > ok(i + ptr + DELTA))
      {
        // cout << "Yep" << ENDL;
        ptr += i;
      }
    }
    cout << ptr << ENDL;
    if (ptr < k || (k - ptr) > 1e-4)
    {
      cout << "May the Force be with you" << ENDL;
    }
    else
    {
      cout << "It's a trap!" << ENDL;
    }
  }
  return 0;
}