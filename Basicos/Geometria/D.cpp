#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define INF 1000000.0

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  double a, b, best = INF, n, x, y, v, dist;
  cin >> a >> b;
  cin >> n;
  while (n--)
  {
    cin >> x >> y >> v;
    dist = sqrt((x - a) * (x - a) + (b - y) * (b - y)) / v;
    best = min(best, dist);
  }
  cout << setprecision(12) << best << ENDL;

  return 0;
}