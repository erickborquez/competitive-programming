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
    int a, b, c;
    cin >> a >> b >> c;
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int ans = 0;
    while (!pq.empty())
    {
        int top = pq.top();
        pq.pop();
        if (top >= 500)
            ans += top - 100;
        else
        {
            if (!pq.empty())
            {
                int next = pq.top();
                pq.pop();
                pq.push(top + next);
            }
            else
            {
                ans += top;
            }
        }
    }

    cout << ans << ENDL;

    return 0;
}