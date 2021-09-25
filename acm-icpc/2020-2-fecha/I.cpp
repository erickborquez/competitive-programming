#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
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

vector<int> formatNumber(int n)
{
  vector<int> ans;

  while (n > 0)
  {
    ans.pb(n % 10);
    n /= 10;
  }

  if (ans.size() == 0)
    ans.pb(0);
  return ans;
}

int multiply(vector<int> v)
{
  int sol = 1;
  FOR(i, 0, v.size())
  sol *= v[i];

  return sol;
}

int main()
{
  IO;
  int tc;
  cin >> tc;

  while (tc--)
  {
    // deb(tc);
    int n;
    int steps = 0;
    cin >> n;
    while (n >= 10)
    {
      // deb(n);
      steps++;
      n = multiply(formatNumber(n));
    }
    cout << steps << ENDL;
  }
  return 0;
}