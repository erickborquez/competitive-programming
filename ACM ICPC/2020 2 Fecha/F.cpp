#include <bits/stdc++.h>
#define ENDL '\n'
#define deb(u) cout << #u " : " << (u) << ENDL;
#define deba(alias, u) cout << alias << ": " << (u) << ENDL;
#define debp(u, v) cout << u << " : " << v << ENDL;
#define pb push_back
#define F first
#define S second
#define lli long long
#define ld long double
#define pii pair<int, int>
#define pll pair<lli, lli>
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define FORN(i, a, n) for (int i = (a - 1); i >= n; --i)
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

int s, r;
int score[2], games[2];
int current;
int winner;

void printGame()
{
    cout << games[0] << " ";
    if (winner == -1)
    {
        cout << "(" << score[0];
        if (s == 0)
            cout << "*";
        cout << ")";
    }
    else if (winner == 0)
        cout << "(winner)";
    cout << " - ";
    cout << games[1] << " ";
    if (winner == -1)
    {
        cout << "(" << score[1];
        if (s == 1)
            cout << "*";
        cout << ")";
    }
    else if (winner == 1)
        cout << "(winner)";
    cout << ENDL;
}

void handleWin(bool server)
{
    if (server)
        games[s]++;
    else
        games[r]++;
    if (games[s] >= 2)
        winner = s;
    else if (games[r] >= 2)
        winner = r;
    score[0] = 0;
    score[1] = 0;
}

void point(bool server)
{
    if (server)
        score[s]++;
    else
        score[r]++;

    if (score[s] >= 5 && score[s] - score[r] >= 2 || score[s] == 10)
        handleWin(true);
    else if (score[r] >= 5 && score[r] - score[s] >= 2 || score[r] == 10)
        handleWin(false);
    if (!server)
        swap(s, r);
}

int main()
{
    IO;
    string st;
    cin >> st;
    s = 0;
    r = 1;
    winner = -1;
    games[0] = games[1] = 0;
    score[0] = score[1] = 0;

    for (auto c : st)
    {
        if (c == 'Q')
            printGame();
        else
            point(c == 'S');
    }

    return 0;
}