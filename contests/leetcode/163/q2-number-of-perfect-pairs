#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        // bierzemy wartości bezwględne
        for(int &x : nums) x = abs(x);
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 0; i < n; i++){
            int a = nums[i];
            // przypadek 1: b >= a -> b ∈ [a, 2a]
            auto L_b_ge_a = lower_bound(nums.begin(), nums.end(), a);
            auto R_b_ge_a = upper_bound(nums.begin(), nums.end(), 2*a);
            res += distance(L_b_ge_a, R_b_ge_a);

            // przypadek 2: b < a -> b ∈ [ceil(a/2),a)
            auto L_b_lt_a = lower_bound(nums.begin(), nums.end(), (a+1)/2);
            auto R_b_lt_a = lower_bound(nums.begin(), nums.end(), a);
            res += distance(L_b_lt_a, R_b_lt_a);
        }
        // odejmujemy pary (a,a) i dzielimy na pół (bo liczone sa (i, j) i (j, i))
        return (res - n) / 2;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 2, 3};
    cout << "res : " << sol.perfectPairs(nums1) << endl;
    cout << "---" << endl;

    vector<int> nums2 = {-3, -2, -1, 4};
    cout << "res: " << sol.perfectPairs(nums2) << endl;
    cout << "---" << endl;


    return 0;
}
