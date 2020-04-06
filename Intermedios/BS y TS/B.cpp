#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;

string s;
vector<vector<int>> m;
vector<int> d(26, 0);

bool ok(int i)
{

  for (int j(0); j < 26; j++)
  {
    bool flag = true;
    for (int k(i); k < s.size(); k++)
    {
      if (m[k][j] - m[k - i][j] == 0)
      {
        flag = false;
        break;
      }
    }
    if (flag)
      return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s;

  for (int i(0); i < s.size(); i++)
  {
    d[s[i] - 'a']++;
    m.pb(d);
  }

  int p = s.size();

  for (int i(s.size()); i > 0; i /= 2)
  {
    while (p - i >= 0 && ok(p - i))
      p -= i;
  }

  cout << p << ENDL;

  return 0;
}