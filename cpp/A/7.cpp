#include <algorithm>
#include <iostream>
#include <vector>
//cos tu jest zle
// poprawie kiedys
using namespace std;

int main() {
    vector<int> rows;
    vector<int> columns;
    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 8; j++) {
            if (row[j] == 'B') {
                rows.push_back(i);
                columns.push_back(j);
            }
        }
    }

    int counter = 0;
    vector<int> painted_rows;
    vector<int> painted_columns;

    for (int i = 0; i < 8; i++) {
        bool is_full_row = true;
        for (int j = 0; j < 8; j++) {
            if (find(rows.begin(), rows.end(), i) == rows.end() ||
                find(columns.begin(), columns.end(), j) == columns.end()) {
                is_full_row = false;
                break;
            }
        }
        if (is_full_row) {
            painted_rows.push_back(i);
            counter++;
        }
    }

    for (int j = 0; j < 8; j++) {
        bool is_column_painted = false;
        for (int i = 0; i < 8; i++) {
            if (find(rows.begin(), rows.end(), i) != rows.end() &&
                find(columns.begin(), columns.end(), j) != columns.end() &&
                find(painted_rows.begin(), painted_rows.end(), i) == painted_rows.end()) {
                is_column_painted = true;
                break;
            }
        }
        if (is_column_painted) {
            painted_columns.push_back(j);
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}