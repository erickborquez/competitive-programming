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

int l, c, n;
string curr;
string m[100];
vector<string> words;
vector<vector<set<string>>> dp;

void searchHorizontal(int y, string w)
{
    int sz = w.size();
    if (sz > c)
        return;
    int left = 0;
    while (left + sz <= c)
    {
        curr = "";
        FOR(i, 0, sz)
        curr += m[y][left + i];
        sort(ALL(curr));
        if (w == curr)
        {
            FOR(i, 0, sz)
            dp[y][left + i].insert(w);
        }
        left++;
    }
}

void searchVertical(int x, string w)
{
    int sz = w.size();
    if (sz > l)
        return;
    int top = 0;
    while (top + sz <= l)
    {
        curr = "";
        FOR(i, 0, sz)
        curr += m[top + i][x];
        sort(ALL(curr));
        if (w == curr)
        {
            FOR(i, 0, sz)
            dp[top + i][x].insert(w);
        }
        top++;
    }
}

void searchOther(int y, int x, string w)
{
    int sz = w.size();
    if (x + sz > c || y + sz > l)
        return;

    int top = y, left = x;

    while (top + sz <= l && left + sz <= c)
    {
        curr = "";
        FOR(i, 0, sz)
        curr += m[top + i][left + i];
        sort(ALL(curr));
        if (w == curr)
        {
            FOR(i, 0, sz)
            dp[top + i][left + i].insert(w);
        }
        top++;
        left++;
    }
}
void searchOtherReversed(int y, int x, string w)
{
    int sz = w.size();
    if (sz > (x + 1) || y + sz > l)
        return;
    int top = y, right = x;

    while (top + sz <= l && sz <= right + 1)
    {
        curr = "";
        FOR(i, 0, sz)
        curr += m[top + i][right - i];
        sort(ALL(curr));

        if (w == curr)
        {
            FOR(i, 0, sz)
            dp[top + i][right - i].insert(w);
        }
        top++;
        right--;
    }
}

int main()
{
    IO;
    cin >> l >> c;
    string w;
    FOR(i, 0, l)
    {
        cin >> m[i];
    }
    cin >> n;
    words.resize(n);
    dp.assign(l, vector<set<string>>(c));
    FOR(i, 0, n)
    {
        cin >> w;
        words[i] = w;
        sort(ALL(words[i]));
    }
    FOR(i, 0, l)
    FOR(k, 0, n)
    searchHorizontal(i, words[k]);

    FOR(i, 0, c)
    FOR(k, 0, n)
    searchVertical(i, words[k]);

    FOR(i, 0, l)
    FOR(j, 0, c)
    FOR(k, 0, n)
    {
        searchOther(i, j, words[k]);
        searchOtherReversed(i, j, words[k]);
    }

    int ans = 0;
    FOR(i, 0, l)
    {
        FOR(j, 0, c)
        {
            // cout << dp[i][j].size() << " ";
            if (dp[i][j].size() > 1)
                ans++;
        }
        // cout << ENDL;
    }

    cout << ans << ENDL;

    return 0;
}