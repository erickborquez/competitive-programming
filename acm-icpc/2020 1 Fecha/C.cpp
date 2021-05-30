#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;

unordered_map<string, string> sus1;
unordered_map<string, string> sus2;
unordered_set<string> pas;
string rec(string s)
{
    pas.insert(s);
    string aux = s, aux2 = s;
    if (sus1.count(s) && pas.find(sus1[s]) == pas.end())
    {
        aux = rec(sus1[s]);
        if (aux.size() > s.size())
        {
            aux = s;
        }
        else if (aux.size() == s.size())
        {
            if (aux > s)
            {
                aux = s;
            }
        }
    }
    if (sus2.count(s) && pas.find(sus2[s]) == pas.end())
    {
        aux2 = rec(sus2[s]);
    }
    if (aux2.size() < aux.size())
    {
        return aux2;
    }
    else if (aux2.size() == aux.size())
    {
        return min(aux, aux2);
    }
    return aux;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string aux, aux2, s, res, m;
    vector<string> words;

    for (int i = 0; i < n; i++)
    {
        cin >> aux >> aux2;
        sus1[aux] = aux2;
        sus2[aux2] = aux;
    }
    cin.ignore();
    getline(cin, m);
    res = "";
    for (auto &x : m)
    {
        if (x == ' ')
        {
            words.push_back(res);
            res = "";
        }
        else
        {
            res += x;
        }
    }
    words.push_back(res);
    for (auto &x : words)
    {
        pas.clear();
        x = rec(x);
    }
    res = "";
    for (auto &x : words)
    {
        res += x;
        res += ' ';
    }
    res.pop_back();
    cout << res << ENDL;
    return 0;
}