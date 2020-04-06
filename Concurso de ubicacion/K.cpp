#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, x, y = 0;
  string s;
  cin >> n >> x >> y >> s;
  int from = s.size() - x;
  if (from < 0)
    from = 0;
  s = s.substr(from);

  int posOne = s.size() - y - 1;
  int count = 0;
  for (int i(0); i < s.size(); i++)
  {
    if (i == posOne)
    {
      if (s[i] == '0')
        count++;
    }
    else
    {
      if (s[i] == '1')
        count++;
    }
  }
  cout << count << ENDL;
  return 0;
}