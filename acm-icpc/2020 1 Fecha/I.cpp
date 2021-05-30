#include <bits/stdc++.h>
#define ENDL '\n'
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cont;
    string s;
    string special = ".#$%/(&)";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        vector<bool> rules(6, false);
        rules[2] = true;
        cin >> s;
        if (s.size() > 9)
        {
            rules[4] = true;
        }
        if (islower(s[0]))
        {
            rules[0] = true;
        }
        else if (isupper(s[0]))
        {
            rules[1] = true;
        }
        else if (isdigit(s[0]))
        {
            rules[5] = true;
        }
        else if (special.find(s[0]) != string::npos)
        {
            rules[3] = true;
        }
        for (int j = 1; j < s.size(); j++)
        {
            if (islower(s[j]))
            {
                rules[0] = true;
            }
            else if (isupper(s[j]))
            {
                rules[1] = true;
            }
            else if (isdigit(s[j]))
            {
                if (isdigit(s[j - 1]))
                {
                    if (abs(s[j] - s[j - 1]) == 1)
                        rules[2] = false;
                }
                rules[5] = true;
            }
            else if (special.find(s[j]) != string::npos)
            {
                rules[3] = true;
            }
        }
        cont = 0;
        for (int j = 0; j < 5; j++)
        {
            if (rules[j])
            {
                cont++;
            }
        }
        if (rules[2] && !rules[5])
        {
            cont--;
        }
        if (cont < 3)
        {
            s = "Rejected";
        }
        else if (cont == 5)
        {
            s = "Strong";
        }
        else if (cont == 4)
        {
            s = "Good";
        }
        else if (cont == 3)
        {
            s = "Weak";
        }

        cout << "Assertion number #" << i << ": " << s << ENDL;
    }
    return 0;
}