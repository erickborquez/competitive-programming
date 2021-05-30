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
  int q, n, t;
  cin >> q;
  while (q--)
  {
    vector<int> type;
    vector<bool> colors;
    bool equal = false;
    bool lastDiferent = false;
    int mx = 1;
    cin >> n;
    for (int i(0); i < n; i++)
    {
      cin >> t;
      type.pb(t);
    }
    int last = true;
    colors.pb(1);
    for (int i(1); i < n; i++)
    {
      if (type[i] != type[i - 1])
      {
        mx = 2;
        last = !last;
      }
      else
        equal = true;
      colors.pb(last);
    }

    if (type[0] != type[n - 1] && colors[0] == colors[n - 1])
    {
      lastDiferent = true;
      mx = 3;
      if (equal)
      {
        bool inverting = false;
        for (int i(1); i < n; i++)
        {
          if (type[i] == type[i - 1])
            inverting = true;
          if (inverting)
          {
            colors[i] = !colors[i];
          }
        }
        cout << 2 << ENDL;
        for (auto c : colors)
          if (c)
            cout << 1 << " ";
          else
            cout << 2 << " ";
        cout << ENDL;
        continue;
      }
    }
    cout << mx << ENDL;
    for (int i(0); i < n - 1; i++)
    {
      if (colors[i])
        cout << 1 << " ";
      else
        cout << 2 << " ";
    }
    if (lastDiferent)
      cout << 3;
    else if (colors[n - 1])
      cout << 1;
    else
      cout << 2;
    cout << ENDL;
  }

  return 0;
}