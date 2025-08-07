#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//https://szkopul.edu.pl/problemset/problem/XadRhCgE-RTLh8RWE9-UFyvj/site/?key=statement


vector<long long> prefix_sum;
vector<int> arr;
int N;

bool validator(int index) {
 long long act_sum = arr[index];

 while (index > 0 && arr[index] == arr[index - 1]) index--;

 if (index > 0 && arr[index] > arr[index - 1]) {
   act_sum += prefix_sum[index - 1];
 }

 while (index < N - 1) {
   if (act_sum > arr[index + 1]) {
     act_sum += arr[index + 1];
   } else {
     return false;
   }
   index++;
 }
 return true;
}

int main() {
 cin >> N;
 arr.resize(N);
 vector<int> copyOfArr(N);
 for (int i = 0; i < N; i++) {
   cin >> arr[i];
   copyOfArr[i] = arr[i];
 }

 int res_val = -1337;
 sort(arr.begin(), arr.end());

 prefix_sum.resize(N);
 prefix_sum[0] = arr[0];

 for (int i = 1; i < N; i++) prefix_sum[i] = arr[i] + prefix_sum[i - 1];

 int l = 0, r = N - 1;
 string ress = "";
 while (l <= r) {
   int mid = (l + r) / 2;
   if (validator(mid)) {
     if (res_val == -1337) {
       res_val = arr[mid];
     } else
       res_val = min(res_val, arr[mid]);
     r = mid - 1;
   } else {
     l = mid + 1;
   }
 }

 string res = "";
 if (res_val == -1337) {
   for (int i = 0; i < N; i++) res += "N";
 } else {
   for (int i = 0; i < N; i++) {
     if (copyOfArr[i] >= res_val) {
       res += "T";
     } else
       res += "N";
   }
 }
 cout << res << "\n";
 return 0;
}
