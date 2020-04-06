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
  int t, n, m, aux;
  cin >> t;
  while (t--)
  {
    lli e1 = 0, o1 = 0, e2 = 0, o2 = 0;
    cin >> n;
    while (n--)
    {
      cin >> aux;
      if (aux % 2)
        e1++;
      else
        o1++;
    }
    cin >> m;
    while (m--)
    {
      cin >> aux;
      if (aux % 2)
      {
        e2++;
      }
      else
      {
        o2++;
      }
    }
    // int total = 0;
    // if (e1 > 0 && e2 > 0)
    //   total += max(e1, e2);
    // if (o1 > 0 && o2 > 0)
    //   total += max(o1, o2);
    cout << e1 * e2 + o1 * o2 << ENDL;
  }
  return 0;
}