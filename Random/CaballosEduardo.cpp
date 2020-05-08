#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                          \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using namespace std;
int n;

vector<vector<bool>> attacked, horses;

bool isValidPos(int i, int j)
{
  return !(i >= n || i < 0 || j >= n || j < 0);
}

int movesI[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int movesJ[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int getOverlap(int i, int j)
{
  if (horses[i][j])
    return -1;
  int total = 0;
  FOR(k, 0, 8)
  {
    int newI = i + movesI[k];
    int newJ = j + movesJ[k];
    if (isValidPos(newI, newJ))
    {
      if (horses[newI][newJ])
        return -1;
      if (attacked[newI][newJ])
        total++;
    }
  }
  return total;
}

int main()
{
  IO;
  cin >> n;

  map<vector<vector<bool>>, int> bests;
  int maxHorses = -1;
  FOR(startI, 0, n)
  {
    FOR(startJ, 0, n)
    {
      pair<pair<int, int>, int> best;
      horses = vector<vector<bool>>(n, vector<bool>(n, false));
      attacked = vector<vector<bool>>(n, vector<bool>(n, false));
      //// Setting the moves for the first horse
      int horseI = startI;
      int horseJ = startJ;
      horses[horseI][horseJ] = true;
      FOR(k, 0, 8)
      {
        int newI = horseI + movesI[k];
        int newJ = horseJ + movesJ[k];
        if (isValidPos(newI, newJ))
        {
          attacked[newI][newJ] = true;
        }
      }

      while (true)
      {
        pair<int, pair<int, int>> best = make_pair(-1, make_pair(-1, -1));
        FOR(i, 0, n)
        {
          FOR(j, 0, n)
          {
            int overlap = getOverlap(i, j);
            if (overlap > best.F)
            {
              best = make_pair(overlap, make_pair(i, j));
            }
          }
        }
        if (best.F == -1)
          break;
        int horseI = best.S.F;
        int horseJ = best.S.S;
        horses[horseI][horseJ] = true;
        FOR(k, 0, 8)
        {
          int newI = horseI + movesI[k];
          int newJ = horseJ + movesJ[k];
          if (isValidPos(newI, newJ))
          {
            attacked[newI][newJ] = true;
          }
        }
      }
      int localMaxHorses = 0;
      FOR(i, 0, n)
      {
        FOR(j, 0, n)
        {
          if (horses[i][j])
            localMaxHorses++;
        }
      }
      maxHorses = max(localMaxHorses, maxHorses);
      bests[horses] = localMaxHorses;
    }
  }
  cout << maxHorses << ENDL;
  int boards = 0;
  for (auto b : bests)
    if (b.S == maxHorses)
      boards++;
  cout << boards << ENDL << ENDL;
  for (auto m : bests)
  {
    if (m.S == maxHorses)
    {
      FOR(i, 0, n)
      {
        FOR(j, 0, n)
        {
          cout << m.F[i][j] << " ";
        }
        cout << ENDL;
      }
    }
    cout << ENDL;
  }

  return 0;
}