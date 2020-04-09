#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define lli long long
#define pii pair<int, int>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    vector<int> a(n), b(n);
    bool pos = false, neg = false;
    bool ok = true;
    for (int i(0); i < n; i++)
      cin >> a[i];
    for (int i(0); i < n; i++)
      cin >> b[i];
    for (int i(0); i < n; i++)
    {
      if (a[i] > b[i] && !neg)
        ok = false;
      if (a[i] < b[i] && !pos)
        ok = false;
      if (a[i] == -1)
        neg = true;
      if (a[i] == 1)
        pos = true;
    }
    if (ok)
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  }

  return 0;
}