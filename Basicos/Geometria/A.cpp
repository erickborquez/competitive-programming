#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, aux;
  vector<int> v;
  cin >> n;
  while (n--)
  {
    cin >> aux;
    v.pb(aux);
  }
  sort(v.begin(), v.end());
  for (int i(2); i < v.size(); i++)
  {
    if (v[i] < v[i - 1] + v[i - 2])
    {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO" << ENDL;

  return 0;
}