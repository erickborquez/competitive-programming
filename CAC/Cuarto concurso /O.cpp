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

const int INF = 1e9;

unordered_map<int, unordered_set<int>> jumps;
unordered_map<int, unordered_set<int>> longjump;

vector<int> best;
vector<int> bestJumps;

void getJumps(int s, int k)
{
    best[s] = 0;
    bestJumps[s] = 1;
    priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto top = pq.top();
        int u = top.S;
        int cost = top.F;
        pq.pop();

        if (cost != best[u])
            continue;

        for (auto &x : jumps[u])
        {
            if (cost + 1 < best[x])
            {
                pq.push({cost + 1, x});
                best[x] = cost + 1;
            }
        }
        if (cost + 1 < bestJumps[u % k])
            for (auto &x : longjump[u % k])
            {
                if (x == u)
                    continue;
                if (cost + 1 < best[x])
                {
                    pq.push({cost + 1, x});
                    best[x] = cost + 1;
                }
            }
    }
}

int main()
{
    IO;
    int n, m, k, u, v, s, t;
    cin >> n >> m >> k;
    best = vector<int>(n + 1, INF);
    bestJumps = vector<int>(n + 1, INF);
    FOR(i, 1, m + 1)
    {
        cin >> v >> u;
        longjump[u % k].insert(u);
        longjump[v % k].insert(v);
        if (u != v)
            jumps[u].insert(v);
    }
    cin >> s >> t;
    getJumps(t, k);
    if (best[s] == INF)
        cout << -1 << ENDL;
    else
        cout << best[s] << ENDL;
    return 0;
}