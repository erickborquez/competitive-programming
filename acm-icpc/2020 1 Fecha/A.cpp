#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, d, e, f, g;
    cin >> a;
    vector<map<ll, ll>> dat;
    dat.resize(a + 1);
    cin >> b;
    char c;
    for (ll i = 0; i < b; i++)
    {
        cin >> c;
        if (c == 'R')
        {
            cin >> d >> e;
            dat[d][e]++;
        }
        else if (c == 'Q')
        {
            cin >> d;
            e = 0;
            f = 0;
            bool ig = false;
            for (auto k : dat[d])
            {
                if (k.second > e)
                {
                    e = k.second;
                    f = k.first;
                    ig = false;
                }
                else if (k.second == e)
                {
                    ig = true;
                }
            }
            if (ig)
            {
                cout << "Multiple\n";
            }
            else if (f != 0)
            {
                cout << f << "\n";
            }
            else
            {
                cout << "No info\n";
            }
        }
        else
        {
            e = 0;
            f = 0;
            bool ig = false;
            for (ll i = 0; i < dat.size(); i++)
            {
                for (auto m : dat[i])
                {
                    if (m.second > e)
                    {
                        e = m.second;
                        f = m.first;
                        g = i;
                        ig = false;
                    }
                    else if (m.second == e)
                    {
                        ig = true;
                    }
                }
            }
            if (ig)
            {
                cout << "Multiple\n";
            }
            else if (f != 0)
            {
                cout << g << " " << f << "\n";
            }
            else
            {
                cout << "No info\n";
            }
        }
    }
    return 0;
}
