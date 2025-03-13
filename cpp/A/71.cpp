#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    int i = 0;
    while(n--) {
      string str;
      cin>>str;
      if(str.length() > 10) {
        string new_str;
        new_str = str[0];
        new_str += to_string((str.length()-2));
        new_str += str[str.length()-1];
        cout << new_str << "\n";
        continue;
      }
        i++;
      cout << str << "\n";
    }

    return 0;
}
