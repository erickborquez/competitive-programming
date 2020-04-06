#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second

#define lli long long
using namespace std;

int s[100010], sum[100010];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, aux, q, l, r;
  cin >> n;

  s[0] = 0;
  sum[0] = 0;
  for (int i(1); i <= n; i++)
  {
    cin >> aux;
    s[i] = aux;
    sum[i] = sum[i - 1] + aux;
  }

  cin >> q;
  int c;
  while (q--)
  {
    cin >> l >> r;
    c = (sum[r] - sum[l - 1]) / 10;
    cout << c << ENDL;
  }

  return 0;
}