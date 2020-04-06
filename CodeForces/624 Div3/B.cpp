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
  int t, n, m, aux;
  cin >> t;
  while (t--)
  {
    vector<pair<int, int>> el;
    vector<int> pos;
    int toLeft[1000];
    int toRight[1000];
    cin >> n >> m;
    for (int i(1); i <= n; i++)
    {
      toLeft[i] = -1;
      toRight[i] = -1;
      cin >> aux;
      el.pb(make_pair(aux, i));
    }
    sort(el.begin(), el.end());

    while (m--)
    {
      cin >> aux;
      pos.pb(aux);
    }

    sort(pos.begin(), pos.end());
    for (int i(0); i < pos.size(); i++)
    {
      if (toLeft[pos[i]] == -1)
      {
        toLeft[pos[i]] = pos[i];
      }
      toLeft[pos[i] + 1] = toLeft[pos[i]];
    }
    for (int i(pos.size() - 1); i >= 0; i--)
    {
      if (toRight[pos[i] + 1] == -1)
      {
        toRight[pos[i] + 1] = pos[i] + 1;
      }
      toRight[pos[i]] = toRight[pos[i] + 1];
    }
    int actual, original;
    bool flag = true;

    for (int i(0); i < el.size(); i++)
    {
      original = el[i].S;
      actual = i + 1;

      if (toRight[original] == -1)
      {
        if (original != actual)
        {
          flag = false;
        }
      }
      else if (actual > toRight[original] || actual < toLeft[original])
      {

        flag = false;
      }
    }
    if (flag)
    {
      cout << "YES" << ENDL;
    }
    else
    {
      cout << "NO" << ENDL;
    }
  }

  return 0;
}