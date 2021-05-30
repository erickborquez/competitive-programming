#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dat;
map<pair<int, int>, set<string>> res;
bool isde(string &a, char b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == b)
        {
            a[i] = 'a';
            return true;
        }
    }
    return false;
}
vector<string> dato;
void fu(string a)
{
    string dax = a;
    int i = 0, j = 0, cont = 0, n = 0, auk;
    while (i < dato.size())
    {
        j = 0;
        n = 0;
        cont = 0;
        auk = 0;
        a = dax;
        while (auk < dato[0].size())
        {
            j = auk++;
            a = dax;
            while (j < dato[i].size())
            {
                if (isde(a, dato[i][j]))
                {
                    cont++;
                }
                else
                {
                    cont = 0;
                    a = dax;
                    break;
                }
                if (cont == a.size())
                {
                    int k = j - cont + 1;
                    while (k <= j)
                    {
                        res[{i, k++}].insert(dax);
                    }
                    cont = 0;
                    a = dax;
                    break;
                }
                else
                {
                    j++;
                }
            }
        }
        i++;
    }
    a = dax;
    i = 0, j = 0, cont = 0, auk = 0;
    while (j < dato[0].size())
    {
        i = 0;
        cont = 0;
        a = dax;
        auk = 0;
        n = 0;
        while (auk < dato.size())
        {
            i = auk++;
            a = dax;
            while (i < dato.size())
            {
                if (isde(a, dato[i][j]))
                {
                    cont++;
                }
                else
                {
                    a = dax;
                    cont = 0;
                    break;
                }
                if (cont == a.size())
                {
                    int k = i - cont + 1;
                    while (k <= i)
                    {
                        res[{k++, j}].insert(dax);
                    }
                    cont = 0;
                    a = dax;
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
        j++;
    }
    a = dax;
    i = 0, j = 0, cont = 0;
    int auxj = 0, t = 0;
    while (j < dato[0].size())
    {
        t = 0;
        while (t < dato.size())
        {
            int m1 = j, n1 = t;
            cont = 0;
            a = dax;
            while (m1 < dato.size() && n1 < dato[0].size())
            {
                if (isde(a, dato[m1][n1]))
                {
                    cont++;
                }
                else
                {
                    a = dax;
                    cont = 0;
                    break;
                }
                if (cont == a.size())
                {
                    int k = m1 - cont + 1;
                    int l = n1 - cont + 1;
                    int r = 0;
                    while (r++ < cont)
                    {
                        res[{k++, l++}].insert(dax);
                        // dat[k++][l++]++;
                    }
                    cont = 0;
                    a = dax;
                    break;
                }
                else
                {
                    m1++;
                    n1++;
                }
            }
            t++;
        }
        j++;
    }
    a = dax;
    i = 0, j = dato[0].size() - 1, cont = 0;
    auxj = 0, t = 0;
    while (j < dato[0].size())
    {
        t = 0;
        while (t < dato.size())
        {
            int m1 = t, n1 = j;
            cont = 0;
            a = dax;
            while (m1 < dato.size() && n1 >= 0)
            {
                if (isde(a, dato[m1][n1]))
                {
                    cont++;
                }
                else
                {
                    a = dax;
                    cont = 0;
                    break;
                }
                if (cont == a.size())
                {
                    int k = m1;
                    int l = n1;
                    int r = 0;
                    while (r++ < cont)
                    {
                        res[{k--, l++}].insert(dax);
                        // dat[k++][l++]++;
                    }
                    cont = 0;
                    a = dax;
                    break;
                }
                else
                {
                    m1++;
                    n1--;
                }
            }
            t++;
        }
        j--;
    }
}
int main()
{
    int a, b, i = 0;
    cin >> a >> b;
    string aux;
    dat = vector<vector<int>>(a, vector<int>(b, 0));
    while (i < a)
    {
        cin >> aux;
        dato.push_back(aux);
        i++;
    }
    cin >> a;
    i = a;
    while (a--)
    {
        cin >> aux;
        fu(aux);
    }
    int result = 0;
    for (auto m : res)
    {
        if (m.second.size() > 1)
        {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
