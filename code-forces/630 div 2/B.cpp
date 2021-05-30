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
  cin >> t;
  int primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
  while (t--)
  {
    cin >> n;
    vector<int> used(11, -1);
    vector<int> color;
    vector<int> v(n);
    int current = 0;
    for (int i(0); i < n; i++)
    {
      cin >> v[i];
      for (int j(0); j < 11; j++)
      {
        if (v[i] % primes[j] == 0)
        {
          if (used[j] == -1)
          {
            used[j] = ++current;
          }
          color.pb(used[j]);
          break;
        }
      }
    }

    cout << current << ENDL;
    for (auto e : color)
      cout << e << " ";
    cout << ENDL;
  }

  return 0;
}