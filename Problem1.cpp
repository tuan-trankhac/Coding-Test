#include <stack>
#include <iostream>
#include <vector>

using namespace std;

bool match(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '{' && b == '}')
        return true;
    return false;
}
bool solve(string x, int n)
{
    stack<char> S;
    for (int i = 0; i <= n - 1; i++)
    {
        if (x[i] == '[' || x[i] == '(' || x[i] == '{')
            S.push(x[i]);
        else
        {
            if (S.empty())
                return false;
            else
            {
                char c = S.top();
                S.pop();
                if (!match(c, x[i]))
                    return false;
            }
        }
    }
    return S.empty();
}
int main()
{

    int N;
    cin >> N;

    vector<string> cases;

    for (int i = 0; i < N; ++i)
    {
        string parentheses;
        cin >> parentheses;
        cases.push_back(parentheses);
    }

    for (int i = 0; i < N; ++i)
    {
        if (cases[i].empty())
        {
            cout << "true" << endl;
        }
        else if (solve(cases[i], cases[i].length()))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}