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
  int t, a, b;
  cin >> t;
  while (t--)
  {
    cin >> a >> b;
    if (a == b)
    {
      cout << 0 << ENDL;
    }
    else if (a > b)
    {
      if (a % 2 == b % 2)
      {
        cout << 1 << ENDL;
      }
      else
      {
        cout << 2 << ENDL;
      }
    }
    else
    {
      if (a % 2 == b % 2)
      {
        cout << 2 << ENDL;
      }
      else
      {
        cout << 1 << ENDL;
      }
    }
  }

  return 0;
}