#include <bits/stdc++.h>
#define ENDL '\n'
#define pb push_back
#define F first
#define S second
#define lli long long

using namespace std;

lli a, b;
vector<lli> answer;
bool printed = false;

bool transform(lli n)
{
  if (printed)
    return false;
  if (n == b)
  {
    printed = true;
    answer.pb(n);
    return true;
  }
  if (n > b)
  {
    return false;
  }

  if (transform(n * 2) || transform(n * 10 + 1))
  {
    answer.pb(n);
    return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;

  if (transform(a))
  {
    cout << "YES" << ENDL;
    cout << answer.size() << ENDL;

    for (int i = answer.size() - 1; i >= 0; i--)
    {
      cout << answer[i] << " ";
    }
    cout << ENDL;
  }
  else
  {
    cout << "NO" << ENDL;
  }
  return 0;
}