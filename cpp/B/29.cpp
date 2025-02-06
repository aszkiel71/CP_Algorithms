#include <iostream>

using namespace std;

int main() {
    int l, d, v, g, r;
    cin >> l >> d >> v >> g >> r;

    int d1 = l - d;

    float time_to_lights = (float)d / v;
    float cycle_time = g + r;
    float remainder = time_to_lights - ((int)(time_to_lights / cycle_time) * cycle_time);

    cout.precision(10);

    if (remainder <= g) {
        cout << (float)l / v << endl;
    } else {
        float wait_time = cycle_time - remainder;
        float total_time = time_to_lights + wait_time + (float)d1 / v;
        cout << total_time << endl;
    }

    return 0;
}
