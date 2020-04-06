#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<int> v;
  int n, aux, total = 0;
  cin >> n;
  while (n--)
  {
    cin >> aux;
    v.pb(aux);
    if (aux == 1)
      total++;
  }
  int mx = 0;

  for (int i(0); i < v.size(); i++)
  {
    if (v[i] == 0)
    {
      int local = 0;
      int maxLocal = 1;
      for (int j(i); j < v.size(); j++)
      {
        if (v[j] == 0)
          local++;
        else
          local--;
        maxLocal = max(maxLocal, local);
      }
      mx = max(maxLocal, mx);
    }
  }
  if (mx == 0)
  {
    cout << total - 1 << ENDL;
    return 0;
  }
  cout << total + mx << ENDL;
  return 0;
}