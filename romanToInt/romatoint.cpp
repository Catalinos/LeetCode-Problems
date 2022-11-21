#include <iostream>
#include <string>
using namespace std;

int main()
{

    int result = 0;
    string value;

    cout << "Insert a roman number: ";
    cin >> value;

    for (int i = 0; i < value.length(); ++i)
    {

        if (value[i] == 'C')
        {
            if (value[i + 1] == 'M')
            {
                result += 900;
                i += 2;
            }
            else if (value[i + 1] == 'D')
            {
                result += 400;
                i += 2;
            }
            else
                result += 100;
        }

        if (value[i] == 'X')
        {
            if (value[i + 1] == 'C')
            {
                result += 90;
                i += 2;
            }
            else if (value[i + 1] == 'L')
            {
                result += 40;
                i += 2;
            }
            else
                result += 10;
        }

        if (value[i] == 'I')
        {
            if (value[i + 1] == 'X')
            {
                result += 9;
                i += 2;
            }
            else if (value[i + 1] == 'V')
            {
                result += 4;
                i += 2;
            }
            else
                result += 1;
        }

        if (value[i] == 'M')
            result += 1000;
        if (value[i] == 'D')
            result += 500;
        if (value[i] == 'L')
            result += 50;
        if (value[i] == 'V')
            result += 5;
    }

    cout << "Rezultatul esteeeeeeee: " << result << endl;
    return 0;
}