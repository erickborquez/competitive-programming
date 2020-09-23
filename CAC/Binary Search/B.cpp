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

int timeLeft;

int sum(int u)
{
  return ((u * (u + 1)) / 2) * 5;
}

bool ok(int u)
{
  // deb(u);
  // debp(sum(u), timeLeft);
  return sum(u) <= timeLeft;
}

int main()
{
  IO;
  int n, k;
  cin >> n >> k;
  timeLeft = 240 - k;
  int ptr = 0;
  for (int i = n; i > 0; i /= 2)
  {
    while (ok(ptr + i))
      ptr += i;
  }
  cout << min(ptr, n) << ENDL;

  return 0;
}