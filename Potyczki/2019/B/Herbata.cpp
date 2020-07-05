//result: 100%

#include <algorithm>
#include <bits/ios_base.h>
#include <iostream>
#include <vector>

using namespace std;

struct cup
{
    long long size;
    long long temperature;

    cup(long long size, long long temperature) {
        this->size = size;
        this->temperature = temperature;
    }
};

bool comparator(cup a, cup b)
{
    return a.temperature > b.temperature;
}


void task()
{
    int kids;
    cin >> kids;

    vector<cup> input;
    vector<cup> target;

    for(int i = 0; i < kids; i++)
    {
        int size, a, b;

        cin >> size >> a >> b;
        cup next_input = cup(size, a);
        cup next_output = cup(size, b);

        input.push_back(next_input);
        target.push_back(next_output);
    }
    sort(input.begin(), input.end(), comparator);
    sort(target.begin(), target.end(), comparator);


    cup input_cup = cup(0, 0);
    cup target_cup = cup(0, 0);

    int i = 0, j = 0;
    while(j < target.size() or i < input.size())
    {
//        cout<<input_cup.size<<" "<<input_cup.temperature<<endl;
//        cout<<target_cup.size<<" "<<target_cup.temperature<<endl;
//        cout<<endl;
        if(input_cup.size < target_cup.size)
        {
            long long to_take = 0;
            long long temperature = 0;
            if(target_cup.size - input_cup.size >= input[i].size)
            {
                to_take = input[i].size;
                temperature = input[i].temperature;
                i++;
            } else{
                to_take = target_cup.size - input_cup.size;
                input[i].size -= to_take;
                temperature = input[i].temperature;

            }

            input_cup.size += to_take;
            input_cup.temperature += temperature * to_take;
        }
        else if(input_cup.temperature < target_cup.temperature)
        {
            cout<<"NIE"<<endl;
            return;
        } else
        {
            target_cup.size += target[j].size;
            target_cup.temperature += target[j].size * target[j].temperature;
            j++;
        }
    }

    if(input_cup.size == target_cup.size and input_cup.temperature == target_cup.temperature)
    {
        cout<<"TAK"<<endl;
        return;
    }
    cout<<"NIE"<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for(int i = 0; i < tests; i++)
        task();

    return 0;
}