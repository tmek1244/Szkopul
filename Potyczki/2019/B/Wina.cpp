//result: 100%

#include <algorithm>
#include <bits/ios_base.h>
#include <iostream>

using namespace std;

int get_bottle_amount(int height)
{
    return height * (height + 1) / 2;
}

bool is_possible(int row, int col, int bottles)
{
    return get_bottle_amount(row) - get_bottle_amount(col - 1) - get_bottle_amount(row - col) <= bottles;
}

int get_min_year(int height, int bottles)
{
    int minimal_year = 2020;
    int row = 1, col = 1;

    for(int i = 0; i < get_bottle_amount(height); i++)
    {
        if(col > row)
        {
            row++;
            col = 1;
        }

        int next_bottle;
        cin >> next_bottle;

        if(next_bottle < minimal_year and is_possible(row, col, bottles))
            minimal_year = next_bottle;

        col++;
    }
    return minimal_year;
}


int main()
{
    ios_base::sync_with_stdio(false);

    int height, bottles;
    cin >> height >> bottles;

    cout << get_min_year(height, bottles) << endl;

    return 0;
}