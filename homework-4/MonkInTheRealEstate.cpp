#include <iostream>
#include<set>

using namespace std;

int main()
{
    int test_cases;
    cin >> test_cases;

    int roads_number;
    set<int> cities;
    for(int i = 0; i < test_cases; i++)
    {
        cin >> roads_number;
        int city_x, city_y;

        for(int j = 0; j < roads_number; j++)
        {
            cin >> city_x >> city_y;
            cities.insert(city_x);
            cities.insert(city_y);
        }
        cout << cities.size() << endl;
        cities.clear();
    }

    return 0;
}
