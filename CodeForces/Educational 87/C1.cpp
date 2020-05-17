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
#define PI 3.14159265359
#define INF 100000000

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    long double n;
    cin >> n;
    // n *= 2;
    // long double angle = 360 / n;
    // long double best = INF;
    // best = INF;
    // FOR(i, 0, 10)
    // {
    //   long double x, y;
    //   long double a = (angle / 10) * i;
    //   x = sin(a * PI / 180);
    //   y = cos(a * PI / 180);
    //   // deb(a);
    //   // debp(x, y);
    //   best = min(best, max(x, y));
    // }
    // long double apothem = 1 / (2 * tan(PI / n));
    // long double circumRadius = apothem / (cos(PI / n));
    // cout << best * (circumRadius * 2) << ENDL;
    cout << fixed << setprecision(10) << 1 / (2 * sin(PI / (4 * n))) << ENDL;
  }
  return 0;
}