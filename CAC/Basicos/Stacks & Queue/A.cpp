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
  int t, n, aux;
  cin >> t;
  queue<int> q;
  while (t--)
  {
    cin >> n;
    if (n == 1)
    {
      cin >> aux;
      q.push(aux);
    }
    else if (n == 2)
    {
      if (!q.empty())
        q.pop();
    }
    else
    {
      if (q.empty())
        cout << "Empty!" << ENDL;
      else
        cout << q.front() << ENDL;
    }
  }

  return 0;
}