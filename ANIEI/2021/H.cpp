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

#define type pair<int, pair<int, string> >

int main()
{
  IO;
  string s;
  int p;
  int pos = 1e6;
  priority_queue<type> pq;
  while (cin >> s)
  {
    if (s == "V")
    {
      if (pq.size() > 0)
      {
        type top = pq.top();
        pq.pop();
        cout << top.second.second << ENDL;
      }
      else
        cout << ENDL;
    }
    else
    {
      cin >> p;
      pq.push(make_pair(p, make_pair(pos--, s)));
    }
  }
  return 0;
}