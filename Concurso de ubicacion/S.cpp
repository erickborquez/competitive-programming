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
  int n, d;
  int p[100000];
  cin >> n >> d;

  for (int i(0); i < n; i++)
  {
    cin >> p[i];
  }
  lli total = 0, aux;
  int left, right;
  for (int i(0); i < n; i++)
  {
    // auto left = i - (lower_bound(p, p + i, p[i] - d) - p);
    auto right = upper_bound(p + i, p + n, p[i] + d) - p - i - 1;
    lli fact = 1;

    if (right == 2)
    {
      total++;
    }
    else if (right > 2)
    {

      for (int i(right - 1); i <= right; i++)
      {
        fact *= i;
      }
      fact /= 2;
      total += fact;
    }
  }
  cout << total << ENDL;
  return 0;
}