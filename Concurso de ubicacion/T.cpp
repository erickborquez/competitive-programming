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
  vector<int> s;
  int a, b, c;
  cin >> a >> b >> c;
  s.pb(a);
  s.pb(b);
  s.pb(c);
  sort(s.rbegin(), s.rend());
  if (s[0] < s[1] + s[2])
  {
    cout << 0 << ENDL;
  }
  else
  {
    cout << s[0] - s[1] - s[2] + 1 << ENDL;
  }
  return 0;
}