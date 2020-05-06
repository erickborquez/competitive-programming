#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;

int main()
{
  IO;
  int n, base;
  cin >> n >> base;
  base++;
  vector<int> v(n);
  FOR(i, 0, n)
  cin >> v[i];

  set<vector<int>> st;
  FOR(i, 0, pow(base, n))
  {
    int num = i;
    int count = 0;
    while (num > 0)
    {
      int amount = num % base;
      num /= base;
      FOR(k, 0, amount)
      cout << v[count] << " ";
      /// En lugar de imprimirklos lo meten en un vector
      /// Luego lo ordenan y lo meten en un set
      count++;
    }
    cout << ENDL;
  }

  // Y al final solo tienen que imprimir las cosas en el set
  // for (auto e : st)
  // {
  //   for (auto p : e)
  //     cout << p << " ";
  //   cout << ENDL;
  // }

  return 0;
}