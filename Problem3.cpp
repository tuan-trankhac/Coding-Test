#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m, d, k, c;
    cin >> m >> d >> k >> c;

    if (d < k)
    { // impossible
        cout << -1;
    }
    else
    {
        // the amount of gold
        int g = 0;

        // The number of monsters that can be killed in 1 turn without the sword disappearing
        int x;
        if ((d % k) == 0)
        {
            x = (d / k - 1);
        }
        else
        {
            x = d / k;
        }

        // Number of monsters remaining after the first turn
        m -= x;

        // Fix and kill monsters
        while ((double)m != (double)(d / k) && m > 0)
        {
            m -= x;
            // cout << m << " ";
            g += c;
        }
        if ((double)m == (double)(d / k))
            g += c;
        cout << g;
    }
    return 0;
}
