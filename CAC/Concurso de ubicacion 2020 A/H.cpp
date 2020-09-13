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
  int q, n, aux;
  int to[300];
  cin >> q;
  int actual;
  int c;
  while (q--)
  {
    cin >> n;
    for (int i(1); i <= n; i++)
    {
      cin >> to[i];
    }
    for (int i(1); i <= n; i++)
    {
      c = 1;
      actual = to[i];
      while (actual != i)
      {
        actual = to[actual];
        c++;
      }
      cout << c << " ";
    }
    cout << ENDL;
  }

  return 0;
}