#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u << " : " << u << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

using namespace std;

bool compare(string a, string b)
{
  if (a == b)
    return false;
  if (a.size() == b.size())
    return a < b;
  bool ok = true;
  FOR(i, 0, min(a.size(), b.size()))
  {
    if (a[i] != b[i])
    {
      ok = false;
      break;
    }
  }
  if (!ok)
    return a < b;
  return a.size() > b.size();
}

int main()
{
  IO;
  int n;
  cin >> n;
  vector<string> ans(n);
  FOR(i, 0, n)
  {
    string s;
    cin >> s;
    sort(s.rbegin(), s.rend());
    ans[i] = s;
  }
  sort(ans.rbegin(), ans.rend(), compare);
  for (auto e : ans)
  {
    cout << e;
  }
  cout << ENDL;
  return 0;
}