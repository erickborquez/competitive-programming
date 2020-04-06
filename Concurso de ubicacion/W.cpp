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
  int k, n;
  string s, t;
  cin >> k;
  while (k--)
  {
    cin >> n >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s != t)
    {
      cout << "NO" << ENDL;
      continue;
    }
    cout << "YES" << ENDL;
  }

  return 0;
}