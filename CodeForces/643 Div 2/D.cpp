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

int main()
{
  IO;
  int n, s;
  cin >> n >> s;
  if (n == 1 && s != 1)
  {
    cout << "YES" << ENDL << s << ENDL << 1 << ENDL;
  }
  else if (n == s)
    cout << "NO" << ENDL;
  else if (n == s - 1)
    cout << "NO" << ENDL;
  else if (s - n <= n - 1)
  {
    cout << "NO" << ENDL;
  }
  else
  {
    cout << "YES" << ENDL;
    FOR(i, 1, n)
    {
      cout << 1 << " ";
    }
    cout << s - n + 1 << ENDL;
    cout << s - n;
  }

  return 0;
}