#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cont = 0, aux, j;
    cin >> n;
    vector<int> boxes(n);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> boxes[i];
    }
    vector<int> bo = boxes;
    sort(bo.begin(), bo.end());
    for (int i = 0; i < n; i++)
    {
        if (pos.count(bo[i]) == 0)
        {
            pos[bo[i]] = i;
        }
    }
    aux = 0;
    for (int i = 0; i < n; i++)
    {
        if (i - aux < pos[boxes[i]])
        {
            cont++;
            aux++;
        }
    }
    cout << cont << ENDL;
    return 0;
}