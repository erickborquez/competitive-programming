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
  int t, n, m;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    cout << "W";
    for (int i(1); i < m; i++)
    {
      cout << "B";
    }
    cout << ENDL;
    for (int i(1); i < n; i++)
    {
      for (int j(0); j < m; j++)
        cout << "B";
      cout << ENDL;
    }
  }

  return 0;
}