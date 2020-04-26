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
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  int n, k;
  cin >> n >> k;
  vector<long double> dist(n);
  FOR(i, 0, n)
  {
    long double x, y, z, diff;
    cin >> x >> y >> z;
    diff = x * x + y * y + z * z;
    dist[i] = diff;
  }
  sort(ALL(dist));
  cout << fixed << setprecision(12) << sqrtl(dist[k - 1]) << ENDL;
  return 0;
}