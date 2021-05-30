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
  string s;
  int n = 0, counter;
  while (cin >> s)
  {
    if (s[0] == '-')
      return 0;
    counter = 0;
    n++;
    stack<char> st;
    for (auto c : s)
    {
      if (c == '{')
        st.push(c);
      else if (!st.empty())
        st.pop();
      else
        counter++;
    }
    int left = st.size() / 2 + st.size() % 2;
    int right = counter / 2 + counter % 2;
    cout << n << ". " << left + right << ENDL;
  }

  return 0;
}