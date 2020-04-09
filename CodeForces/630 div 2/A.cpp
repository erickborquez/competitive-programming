#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, a, b, c, d;
  cin >> t;
  while (t--)
  {
    int tY = 0, tX = 0;
    cin >> a >> b >> c >> d;
    tX = b - a;
    tY = d - c;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    tX += x;
    tY += y;
    if (x == x1 && x == x2 && (a > 0 || b > 0))
    {
      cout << "NO" << ENDL;
      continue;
    }
    if (y == y1 && y == y2 && (c > 0 || d > 0))
    {
      cout << "NO" << ENDL;
      continue;
    }
    if (tX < x1 || tX > x2 || tY < y1 || tY > y2)
      cout << "NO" << ENDL;
    else
      cout << "YES" << ENDL;
  }

  return 0;
}