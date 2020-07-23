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

string w = "abacaba";
int n;

bool isExact(string s)
{
  bool ok = false;

  FOR(i, 0, n - w.size() + 2)
  {
    string word = s.substr(i, w.size());
    // deb(word);
    if (word == w)
    {
      if (ok)
      {
        return false;
      }
      ok = true;
    }
  }
  return ok;
}

void printAns(string s)
{
  cout << "Yes" << ENDL;
  FOR(i, 0, s.size())
  {
    if (s[i] == '?')
      cout << 'z';
    else
      cout << s[i];
  }
  cout << ENDL;
}

int main()
{
  IO;
  int t;
  cin >> t;
  while (t--)
  {
    string s, ans;
    cin >> n >> s;
    vector<bool> can(n, true);
    ans = s;
    if (isExact(ans))
      printAns(s);
    else
    {
      bool ok = false;
      FOR(i, 0, n - w.size() + 1)
      {
        string copy = s;
        bool flag = true;
        FOR(j, 0, w.size())
        {
          if (copy[i + j] == w[j] || copy[i + j] == '?')
          {
            copy[i + j] = w[j];
          }
          else
          {
            flag = false;
            break;
          }
        }
        if (flag && isExact(copy))
        {
          ok = true;
          printAns(copy);
          break;
        }
      }
      if (!ok)
        cout << "No" << ENDL;
    }
  }

  return 0;
}