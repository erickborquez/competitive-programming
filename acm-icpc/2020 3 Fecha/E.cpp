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

int main()
{
    IO;
    lli n, b;
    cin >> n >> b;
    vector<lli> perf(n);
    vector<lli> ans(n, b);
    priority_queue<pll> toVisit;
    FOR(i, 0, n)
    {
        cin >> perf[i];
        if (perf[i] == 0)
        {
            ans[i] = 0;
        }
        else
        {
            pll p = {-perf[i], i};
            toVisit.emplace(p);
        }
    }
    while (!toVisit.empty())
    {
        priority_queue<pll> pq;
        auto top = toVisit.top();
        toVisit.pop();
        pll next = {ans[top.S], top.S};
        pq.emplace(next);
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            lli u = top.S;
            lli val = top.F;
            // deb(u);
            if (ans[u] > val)
                continue;
            lli left = (u + n - 1) % n;
            lli right = (u + n + 1) % n;

            if (perf[left] > perf[u] && ans[left] <= val)
            {
                pq.push({val + b, left});
                ans[left] = val + b;
            }
            // else if (perf[left] == perf[u] && ans[left] < val)
            // {
            //     pq.push({val, left});
            //     ans[left] = val;
            // }

            if (perf[right] > perf[u] && ans[right] <= val)
            {
                pq.push({val + b, right});
                ans[right] = val + b;
            }
            // else if (perf[right] == perf[u] && ans[right] < val)
            // {
            //     pq.push({val, right});
            //     ans[right] = val;
            // }
        }
    }

    FOR(i, 0, n - 1)
    cout << ans[i] << " ";
    cout << ans[n - 1] << ENDL;

    return 0;
}