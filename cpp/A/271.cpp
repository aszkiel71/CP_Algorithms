#include <iostream>

using namespace std;

bool is_distinct(int s){
    string tmp;
    int len;
    tmp = to_string(s);
    len = tmp.length();
    int array[len];
    int temp = s;
    for (int i = 0; i < len; i++)
    {
        array[i] = temp % 10;
        temp /= 10;
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if(array[i] == array[j])
                return false;
        }
    }

    return true;
}


int main() {
    int y;
    cin >> y;
    y++;
    while(true)
    {
        if (is_distinct(y))
        {
            cout << y << endl;
            return 0;
        }
        y++;

    }
    return 0;
}
