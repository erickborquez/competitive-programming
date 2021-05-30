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

int posY[7] = {0, 0, 1, 2, 2, 2, 1};
int posX[7] = {1, 2, 2, 2, 1, 0, 0};
pii newCenter = {2, 2};

int main()
{
  IO;
  int n;
  cin >> n;
  vector<pii> ans;
  ans.pb({0, 0});
  pii pos = {0, 0};
  FOR(i, 0, n + 1)
  {
    FOR(i, 0, 7)
    {
      ans.pb({pos.F + posY[i], pos.S + posX[i]});
    }
    pos.F += newCenter.F;
    pos.S += newCenter.S;
  }
  cout << ans.size() << ENDL;
  for (auto e : ans)
  {
    cout << e.F << " " << e.S << ENDL;
  }

  return 0;
}