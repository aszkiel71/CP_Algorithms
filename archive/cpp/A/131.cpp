#include <iostream>
#include <cctype>
using namespace std;


bool isUpperCase(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}
bool isLowerCase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}



int main() {
    string word;
    cin >> word;

    int amount_of_upper = 0;
    for (char c : word)
    {
        if (isUpperCase(c))
        {
            amount_of_upper++;
        }
    }
    //case if we got all uppercase in it

    if (amount_of_upper == word.size())
    {

        for (char &c : word)
        {
            c = tolower(c);
        }
        cout << word;
        return 0;
    }
    //case if we got first letter lowercase and the rest uppercase
    if (amount_of_upper == word.size() - 1 and isLowerCase(word[0]))
    {
        if (isLowerCase(word[0]))
        {
            word[0] = toupper(word[0]);
        }
        for (int i = 1; i < word.size(); i++)
        {
            word[i] = tolower(word[i]);
        }
        cout << word;
        return 0;
    }

    if (amount_of_upper == 1 and isUpperCase(word[0]))
    {
        cout << word;
        return 0;
    }

    cout << word;
    return 0;
}
