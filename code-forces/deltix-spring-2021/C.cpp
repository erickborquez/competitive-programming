#include <bits/stdc++.h>
#define DEBUG true
#define ENDL '\n'
#define deb(u) \
  if (DEBUG)   \
    cout << #u " : " << (u) << ENDL;
#define deba(alias, u) \
  if (DEBUG)           \
    cout << alias << ": " << (u) << ENDL;
#define debp(u, v) \
  if (DEBUG)       \
    cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
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

vector<int> ls;

void print()
{
  FOR(i, 0, ls.size() - 1)
  {
    cout << ls[i] << ".";
  }
  cout << ls[ls.size() - 1] << ENDL;
}

void resolve(int u)
{
  if (ls.size() == 0 || u == 1)
  {
    ls.push_back(u);
    print();
    return;
  }
  while (ls.size() > 0)
  {

    if (ls[ls.size() - 1] == u - 1)
    {
      ls.pop_back();
      break;
    }
    ls.pop_back();
  }
  ls.push_back(u);
  print();
}

int main()
{
  IO;
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    ls.clear();
    FOR(i, 0, n)
    {
      int u;
      cin >> u;
      resolve(u);
    }
  }

  return 0;
}