#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, x, y, mx = 0;
  cin >> n;
  while (n--)
  {
    cin >> x >> y;
    mx = max(x + y, mx);
  }
  cout << mx << ENDL;

  return 0;
}