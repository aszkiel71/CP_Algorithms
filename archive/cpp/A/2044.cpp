#include <iostream>

using namespace std;

bool goodtho(int a, int b, int n)
{
    return (a + b == n);
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int counter = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(goodtho(i,j,n))
                    counter++;
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}
