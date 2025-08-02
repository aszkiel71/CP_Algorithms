#include <iostream>

using namespace std;

bool isAlcohol(string drink){
  string alcohol[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    int amount = sizeof(alcohol) / sizeof(alcohol[0]);
    for (int i = 0; i < amount; i++){
    if (drink == alcohol[i])
      return true;
  }
  return false;
}

bool isNumber(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isUnderage(int age)
{
    if(age >= 18)
        return false;
    return true;
}


int main() {
    int n;
    cin >> n;


    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        string order;
        cin >> order;
        if (isAlcohol(order))
            counter++;
        else
        {
            if (isNumber(order))
            {
                if(isUnderage(stoi(order)))
                    counter++;
            }
        }
    }
    cout << counter;
    return 0;
}
