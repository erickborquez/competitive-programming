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
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> pos(n);
    vector<bool> taken(n, false);
    FOR(i, 0, n)
    {
      int aux;
      cin >> aux;
      pos[aux - 1] = i;
    }
    bool ok = true;
    FOR(i, 0, n - 1)
    {
      if (pos[i] == n - 1 || taken[pos[i] + 1] || pos[i + 1] == pos[i] + 1)
      {
        taken[pos[i]] = true;
      }
      else
      {
        // deb(i);
        // deb(pos[i]);
        // deb(pos[i + 1]);

        ok = false;
        break;
      }
    }
    if (ok)
      cout << "Yes" << ENDL;
    else
      cout << "No" << ENDL;
  }
  return 0;
}