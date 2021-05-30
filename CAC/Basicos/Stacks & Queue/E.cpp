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
  int n;
  while (cin >> n)
  {
    if (n == 0)
      return 0;
    int counter = 1;
    int last = 0, c;
    stack<int> s;
    while (n--)
    {
      cin >> c;

      s.push(c);

      while (!s.empty() && s.top() == counter)
      {
        counter++;
        s.pop();
      }
    }
    if (s.empty())
      cout << "yes" << ENDL;
    else
      cout << "no" << ENDL;
  }
  return 0;
}
