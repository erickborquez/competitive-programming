#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define deb(u) cout << #u ": " << (u) << endl;
#define PI 3.1415926536

#define lli long long

using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, aux;
  vector<int> v;
  cin >> n;
  while (n--)
  {
    cin >> aux;
    v.pb(aux);
  }
  sort(v.begin(), v.end());

  double area = 0;
  for (int i = (v.size() - 1), j = 1; i >= 0; i--, j++)
  {
    if (j % 2)
    {
      area += PI * v[i] * v[i];
    }
    else
    {
      area -= PI * v[i] * v[i];
    }
  }
  cout << setprecision(12) << area << ENDL;

  return 0;
}