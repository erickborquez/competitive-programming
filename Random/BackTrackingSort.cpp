#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

vector<int> sortBT(vector<int> copy, vector<bool> taken)
{
  vector<int> toReturn;
  for (int i = 1; i < copy.size(); i++)
  {
    if (copy[i] < copy[i - 1])
      return toReturn;
  }
  if (copy.size() == n)
    return copy;
  for (int i = 0; i < n; i++)
  {
    if (!taken[i])
    {
      // debp(i, taken[i]);
      vector<int> newCopy = copy;
      vector<bool> newTaken = taken;
      newTaken[i] = true;
      newCopy.push_back(v[i]);
      toReturn = sortBT(newCopy, newTaken);
      if (toReturn.size() > 0)
        break;
    }
  }
  return toReturn;
}

int main()
{
  cin >> n;
  v = vector<int>(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
  {
    vector<int> start;
    start.push_back(v[i]);
    vector<bool> taken(n, false);
    taken[i] = true;
    vector<int> sorted = sortBT(start, taken);
    // deb(sorted.size());
    if (sorted.size() > 0)
    {
      for (auto e : sorted)
        cout << e << " ";
      break;
    }
  }
  return 0;
}