#include <iostream>


using namespace std;


int sum_of_digits_in_base(int number, int base) {
    int sum = 0;
    while (number > 0) {
        sum += number % base;
        number /= base;
    }
    return sum;
}

int gcd(int x, int y)
    {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}


string reduct(int numerator, int denominator) {
    int gcd_value = gcd(numerator, denominator);
    numerator /= gcd_value;
    denominator /= gcd_value;
    return to_string(numerator) + "/" + to_string(denominator);
}

int main() {
    int A;
    cin >> A;

    int total_sum = 0;
    for (int base = 2; base < A; base++) {
        total_sum += sum_of_digits_in_base(A, base);
    }

    int numerator = total_sum;
    int denominator = A - 2;

    cout << reduct(numerator, denominator) << endl;
    return 0;
}
