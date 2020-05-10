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
#define ALLR(a) (a).rbegin(), (a).rend()
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
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> c(n);
    FOR(i, 0, n)
    cin >> c[i];
    int actualA = 0, actualB = 0;
    int ptrA = -1, ptrB = n;
    int accA = 0, accB = 0;
    int moves = 0;
    bool ok = true;
    while (ok)
    {
      actualA = 0;
      bool flag = false;
      while (actualA <= actualB)
      {
        ptrA++;
        if (ptrA == ptrB)
        {
          ok = false;
          break;
        }
        flag = true;
        actualA += c[ptrA];
      }
      if (flag)
        moves++;
      flag = false;
      actualB = 0;
      while (ok && actualB <= actualA)
      {
        ptrB--;
        if (ptrA == ptrB)
        {
          ok = false;
          break;
        }
        flag = true;
        actualB += c[ptrB];
      }
      if (flag)
        moves++;
      accA += actualA;
      accB += actualB;
    }
    cout << moves << " " << accA << " " << accB << ENDL;
  }
  return 0;
}