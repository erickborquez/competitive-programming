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
  int t, n, m, fail;
  char aux;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    map<char, int> p, total;
    vector<map<char, int>> tries;
    for (int i(0); i < n; i++)
    {
      cin >> aux;
      p[aux]++;
      tries.pb(p);
    }
    while (m--)
    {
      cin >> fail;
      for (auto h : tries[fail - 1])
      {
        total[h.F] += h.S;
      }
    }

    for (auto h : tries[tries.size() - 1])
    {
      total[h.F] += h.S;
    }

    for (int i('a'); i <= 'z'; i++)
    {
      cout << total[i] << " ";
    }
    cout << ENDL;
  }
  return 0;
}