#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double squaredDistance(int x1, int y1, int x2, int y2) {
    return pow(x2 - x1, 2) + pow(y2 - y1, 2);
}

double dotProduct(int x1, int y1, int x2, int y2) {
    return x1 * x2 + y1 * y2;
}

bool hasCommonEndpoint(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return (x1 == x3 && y1 == y3) || (x1 == x4 && y1 == y4) ||
           (x2 == x3 && y2 == y3) || (x2 == x4 && y2 == y4);
}

bool isA(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6) {
    if (!hasCommonEndpoint(x1, y1, x2, y2, x3, y3, x4, y4)) {
        return false;
    }

    int cx, cy;
    if (x1 == x3 && y1 == y3) { cx = x1; cy = y1; }
    else if (x1 == x4 && y1 == y4) { cx = x1; cy = y1; }
    else if (x2 == x3 && y2 == y3) { cx = x2; cy = y2; }
    else if (x2 == x4 && y2 == y4) { cx = x2; cy = y2; }
    else { return false; }


    int v1x = x1 - cx, v1y = y1 - cy;
    int v2x = x2 - cx, v2y = y2 - cy;

    double dot = dotProduct(v1x, v1y, v2x, v2y);
    double mag1 = sqrt(squaredDistance(0, 0, v1x, v1y));
    double mag2 = sqrt(squaredDistance(0, 0, v2x, v2y));
    double angle = acos(dot / (mag1 * mag2)) * 180.0 / M_PI;

    if (angle <= 0 || angle >= 90) {
        return false;
    }

    double d1 = sqrt(squaredDistance(x5, y5, x6, y6));
    double d2 = sqrt(squaredDistance(x1, y1, x2, y2));
    double d3 = sqrt(squaredDistance(x3, y3, x4, y4));
    double minLength = min(d2, d3);
    double maxLength = max(d2, d3);

    return minLength / maxLength >= 0.25;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, x2, y2;
        int x3, y3, x4, y4;
        int x5, y5, x6, y6;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        cin >> x5 >> y5 >> x6 >> y6;

        if (isA(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
