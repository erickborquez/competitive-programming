#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

using namespace std;

struct Day
{
  int min, max;
  int actual;
  bool canGet()
  {
    return actual < max;
  };
};

main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int d, sumTime;
  vector<Day> days;
  cin >> d >> sumTime;
  Day aux;
  while (d--)
  {
    cin >> aux.min >> aux.max;
    aux.actual = aux.min;
    sumTime -= aux.actual;
    days.pb(aux);
  }
  if (sumTime < 0)
  {
    cout << "NO" << ENDL;
    return 0;
  }

  while (sumTime > 0)
  {
    bool give = false;
    for (auto &d : days)
    {
      if (sumTime <= 0)
        break;
      if (d.canGet())
      {
        sumTime--;
        give = true;
        d.actual++;
      }
    }
    if (!give)
    {
      cout << "NO" << ENDL;
      return 0;
    }
  }

  cout << "YES" << ENDL;
  for (auto d : days)
  {
    cout << d.actual << " ";
  }

  return 0;
}