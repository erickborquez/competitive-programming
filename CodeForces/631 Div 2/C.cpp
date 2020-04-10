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
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a)-1; i >= n; --i)
#define INF 100001

#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  int n, m, i;
  cin >> n >> m;
  vector<int> vec(n + 1);
  vector<int> pos(m + 1);
  vector<int> mx(m + 2, INF);
  int maxMovements = INF;
  FOR(i, 1, m + 1)
  {
    cin >> vec[i];
    maxMovements = min(maxMovements, n - vec[i] - i + 1);
    if (maxMovements < 0)
    {
      cout << -1 << ENDL;
      return 0;
    }
  }
  int desplaced = 0;
  int toComplete = n - vec[m] - m + 1;
  FORN(i, m + 1, 1)
  {
    mx[i] = min(mx[i + 1], n - vec[i] - i + 1);
    // debp(i, mx[i]);
  }
  FOR(i, 1, m)
  {
    pos[i] = desplaced + i;
    if (toComplete > 0)
    {
      int dist = min(toComplete, vec[i] - 1);
      dist = min(dist, mx[i + 1] - desplaced);
      desplaced += dist;
      toComplete -= dist;
    }
  }
  pos[m] = desplaced + m;
  if (toComplete > 0)
  {
    cout << -1 << ENDL;
  }
  else
  {
    FOR(i, 1, m + 1)
    {
      cout << pos[i] << " ";
    }
  }
  return 0;
}