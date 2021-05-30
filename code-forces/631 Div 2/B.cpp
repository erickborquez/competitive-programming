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

int n;
vector<int> num;

pii leftToRight()
{
  set<int> a, b;
  bool flag = true;
  FOR(i, 0, n)
  {
    if (a.count(num[i]))
      break;
    a.insert(num[i]);
  }
  FOR(i, 1, a.size() + 1)
  {
    if (!a.count(i))
    {
      flag = false;
      break;
    }
  }
  FOR(i, a.size(), n)
  {
    if (b.count(num[i]))
    {
      flag = false;
      break;
    }
    b.insert(num[i]);
  }

  FOR(i, 1, b.size() + 1)
  {
    if (!b.count(i))
    {
      flag = false;
    }
  }
  if (flag)
    return {a.size(), b.size()};
  return {-1, -1};
}
pii rightToLeft()
{
  set<int> a, b;
  bool flag = true;
  FORN(i, n, 0)
  {
    if (a.count(num[i]))
      break;
    a.insert(num[i]);
  }
  FOR(i, 1, a.size() + 1)
  {
    if (!a.count(i))
    {
      flag = false;
      break;
    }
  }
  FORN(i, n - a.size(), 0)
  {
    if (b.count(num[i]))
    {
      flag = false;
      break;
    }
    b.insert(num[i]);
  }

  FOR(i, 1, b.size() + 1)
  {
    if (!b.count(i))
    {
      flag = false;
    }
  }
  if (flag)
    return {b.size(), a.size()};
  return {-1, -1};
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int i;
    int mx = 0;
    num.resize(n);
    FOR(i, 0, n)
    {
      cin >> num[i];
    }
    pii left, right;
    left = leftToRight();
    right = rightToLeft();
    if (left.F != -1 && right.F != -1 && right.F != left.F)
    {
      cout << 2 << ENDL;
      cout << left.F << " " << left.S << ENDL;
      cout << right.F << " " << right.S << ENDL;
    }
    else if (left.F != -1)
    {
      cout << 1 << ENDL;
      cout << left.F << " " << left.S << ENDL;
    }
    else if (right.F != -1)
    {
      cout << 1 << ENDL;
      cout << right.F << " " << right.S << ENDL;
    }
    else
    {
      cout << 0 << ENDL;
    }
  }

  return 0;
}