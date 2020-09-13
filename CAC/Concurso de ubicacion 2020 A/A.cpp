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
  int n, aux;
  vector<pair<int, bool>> b;
  cin >> n;
  for (int i(0); i < n; i++)
  {
    cin >> aux;
    b.pb(make_pair(aux, true));
  }

  sort(b.begin(), b.end());
  int taken = 0;
  int piles = 0;
  int boxes;
  while (taken < n)
  {
    piles++;
    boxes = 0;
    for (int i(0); i < n; i++)
    {
      if (b[i].S)
      {
        if (b[i].F >= boxes)
        {
          b[i].S = false;
          boxes++;
          taken++;
        }
      }
    }
  }
  cout << piles << ENDL;
  return 0;
}