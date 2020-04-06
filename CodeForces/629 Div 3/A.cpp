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
  int a, b, t;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    if (a % b == 0)
      cout << 0 << ENDL;
    else if (a > b)
    {
      cout << b - a % b << ENDL;
    }
    else
    {
      cout << b - a << ENDL;
    }
  }

  return 0;
}