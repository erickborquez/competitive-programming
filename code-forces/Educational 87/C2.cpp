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

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    long double n;
    cin >> n;
    long double apothem = 1 / (2 * tan(PI / (n * 2)));
    long double circumRadius = apothem / (cos(PI / (n * 2)));
    // deb(circumRadius);
    // deb(apothem * 2 + circumRadius * 2 / PI);
    deb(apothem);
    deb(circumRadius * 2);
    deb((circumRadius * 2) / sqrt(2));
    // cout
    //     << fixed << setprecision(12) << (circumRadius * 2) / sqrt(2) << ENDL;
  }
  return 0;
}