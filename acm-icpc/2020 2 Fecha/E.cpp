#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
unordered_map<int, set<int>> tree;
vector<int> ages;
vector<int> parties;
vector<bool> auxiliar;

void checkParty(int n, int l, int r)
{
    auxiliar[n] = true;
    if (ages[n] <= r && ages[n] >= l)
    {
        parties[n]++;
        for (auto x : tree[n])
        {
            if (!auxiliar[x])
            {
                checkParty(x, l, r);
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, aux, age, o, l, r;
    cin >> n >> m;
    ages = vector<int>(n);
    parties = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> age >> aux;
        ages[i] = age;
        tree[i].insert(aux - 1);
        tree[aux - 1].insert(i);
    }

    while (m--)
    {
        cin >> o >> l >> r;
        auxiliar = vector<bool>(n, false);
        checkParty(o - 1, l, r);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << parties[i] << " ";
    }
    cout << parties[n - 1] << ENDL;

    return 0;
}