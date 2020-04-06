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
  int t, n;
  string x, a, b;
  cin >> t;
  while (t--)
  {
    cin >> n >> x;
    bool equal = true;
    a = "";
    b = "";
    for (int i(0); i < n; i++)
    {
      if (x[i] == '2')
      {
        if (equal)
        {
          a += '1';
          b += '1';
        }
        else
        {
          a += '0';
          b += '2';
        }
      }
      else if (x[i] == '1')
      {
        if (equal)
        {
          equal = false;
          a += '1';
          b += '0';
        }
        else
        {
          a += '0';
          b += '1';
        }
      }
      else
      {
        a += '0';
        b += '0';
      }
    }
    cout << a << ENDL << b << ENDL;
  }

  return 0;
}