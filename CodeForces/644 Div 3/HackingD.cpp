#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define fios               \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define M_PI 3.14159265358979323846
typedef long long ll;

int main()
{
  //fios;
  int t;
  cin >> t;
  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    if (n <= k)
      puts("1");
    else
    {
      int flg1 = 1;
      for (int i = 2; i * i <= n; i++)
      {
        if (n % i == 0)
        {
          flg1 = 0;
          break;
        }
      }
      if (flg1 == 1)
      {
        cout << n << endl;
        continue;
      }
      int flg = 0;
      ll f = ceil(n * 1.0 / k);
      if (f * f <= n)
      {
        for (; f * f <= n && f <= k; f++)
        {
          if (n % f == 0)
          {
            cout << f << endl;
            flg = 1;
            break;
          }
        }
        if (flg == 0)
        {
          int tflag = 0;
          for (ll f = k; f >= 1; f--)
          {
            if (n % f == 0)
            {
              cout << n / f << endl;
              tflag = 1;
              break;
            }
          }
          if (tflag == 0)
            cout << n << endl;
        }
      }
      else
      {
        for (ll f = k; f >= 1; f--)
        {
          if (n % f == 0)
          {
            cout << n / f << endl;
            break;
          }
        }
      }
    }
  }
}