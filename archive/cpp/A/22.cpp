#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    //vector<int> v(n);
    if(n < 2)
    {
        int k;
        cin >> k;
        cout<<"NO";
    }
    else
    {
        int v[n];
        for(int i=0;i<n;i++)
            cin>>v[i];

        int min_val = v[0];
        for(int c : v)
        {
            if(c < min_val)
            {
                min_val = c;
            }
        }

        vector<int> new_arr;
        for(int i=0;i<n;i++)
        {
            if(min_val != v[i])
            {
                new_arr.push_back(v[i]);
            }
        }

        if(new_arr.empty())
        {
            cout<<"NO";
        }
        else
        {
            int min_val_2 = new_arr[0];
            for(int c2 : new_arr)
            {
                if(min_val_2 > c2)
                    min_val_2 = c2;
            }
            cout<<min_val_2;
        }

    }


    return 0;
}
