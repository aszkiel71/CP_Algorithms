#include <iostream>

using namespace std;

// 0 -> draw, 1 -> s1, 2 -> s2
int winner(string s1, string s2){
    if (s1 == s2)
        return 0;

    else
    {
        if(s1 == "rock" and s2 == "scissors")
            return 1;
        else if(s1 == "scissors" and s2 == "paper")
            return 1;
        else if (s1 == "paper" and s2 == "rock")
            return 1;
    }
    return 0;
}

int main() {
    string fyodor, matroskin, sharic;
    cin >> fyodor >> matroskin >> sharic;
    if(fyodor == sharic and sharic == matroskin)
        cout << "?" << endl;
    else
    {
        int w_fyodor = 0, w_matroskin = 0, w_sharic = 0;
        // fyodor vs matroskin
        if(winner(fyodor, matroskin))
        {
            w_fyodor++;
        }
        else if(winner(matroskin, fyodor))
        {
            w_matroskin++;
        }

        // fyodor vs sharic
        if(winner(fyodor, sharic))
        {
            w_fyodor++;
        }
        else if(winner(sharic, fyodor))
        {
            w_sharic++;
        }

        //sharic vs matroskin
        if(winner(sharic, matroskin))
        {
            w_sharic++;
        }
        else if(winner(matroskin, sharic))
        {
            w_matroskin++;
        }

        if(w_sharic == w_fyodor && w_sharic == w_matroskin)
            cout << "?" << endl;
        else if(w_sharic == 2 || w_fyodor == 2 || w_matroskin == 2 )
        {
            if(w_sharic == 2)
            {
                cout << "S";
            }
            else if(w_matroskin == 2)
            {
                cout << "M";
            }
            else
            {
                cout << "F";
            }
        }
        else
            cout<<"?";

    }


    return 0;
}
