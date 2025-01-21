#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}



int main() {
    int n, k;
    vector<int> primes;
    cin>>n>>k;
    int counter = 0;
    int tmp_max_prime_val = 0;
    int tmp_prime = 2;
    while(tmp_max_prime_val <= n)
    {
        if(isPrime(tmp_prime))
        {
            primes.push_back(tmp_prime);
            tmp_max_prime_val = tmp_prime;
        }
        tmp_prime++;
    }

    for(int i = 2; i <= n; i++)
    {
        if(isPrime(i))
        {
            for(int j = 0; j <= primes.size()-1; j++)
            {
                if(primes[j] + primes[j+1] + 1 == i)
                {
                    counter++;
                }
            }
        }

    }


    if (counter >= k)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
