#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 5000000 + 1;

int main() {
    vector<bool> primes(N, true);
    primes[0] = primes[1] = false;

    for (long long p = 2; p * p < N; ++p) {
        if (primes[p]) {
            for (long long i = p * p; i < N; i += p) {
                primes[i] = false;
            }
        }
    }

    vector<int> prime_numbers;
    for (int i = 2; i < N; ++i) {
        if (primes[i]) {
            prime_numbers.push_back(i);
        }
    }

    cout << "std::vector<int> primes = {";
    for (size_t i = 0; i < prime_numbers.size(); ++i) {
        cout << prime_numbers[i];
        if (i < prime_numbers.size() - 1) {
            cout << ", ";
        }
    }
    cout << "};";

    return 0;
}
