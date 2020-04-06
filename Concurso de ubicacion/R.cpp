#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  pair<int, int> t[100000];
  cin >> n;
  for (int i(0); i < n; i++)
  {
    cin >> t[i].F >> t[i].S;
  }
  if (n <= 2)
  {
    cout << n << ENDL;
    return 0;
  }
  int spaceLeft, spaceRight, total = 2;
  spaceLeft = t[1].F - t[0].F - 1;
  spaceRight = t[2].F - t[1].F - 1;
  // cout << spaceLeft << " " << spaceRight << ENDL;
  for (int i(1); i < n - 1; i++)
  {
    spaceRight = t[i + 1].F - t[i].F - 1;
    if (t[i].S <= spaceLeft)
    {
      total++;
    }
    else if (t[i].S <= spaceRight)
    {
      spaceRight -= t[i].S;
      total++;
    }
    spaceLeft = spaceRight;
  }
  cout << total << ENDL;
  return 0;
}