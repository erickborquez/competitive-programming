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
  int n;
  string s;
  cin >> n >> s;
  if (n == 1)
  {
    cout << "NO" << ENDL;
    return 0;
  }
  char last = s[0];
  for (int i(1); i < n; i++)
  {
    if (s[i] != last)
    {
      cout << "YES" << ENDL;
      cout << last << s[i] << ENDL;
      return 0;
    }
    last = s[i];
  }
  cout << "NO" << ENDL;

  return 0;
}