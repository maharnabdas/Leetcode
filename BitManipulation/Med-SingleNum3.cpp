// https://leetcode.com/problems/single-number-iii/solutions/1561852/c-easy-clean-solution-fastest-all-4-methods-detailed-explanation-comments/?envType=problem-list-v2&envId=bit-manipulation
// Learnt something new: num ^ -num gives the rightmost bit which is 1 in num, with remaining bits 0
// if x ^ y = z, then z ^ y = x

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int firstXorSec = 0, mask = 1, first = 0;

        // get xor of first and sec
        for (auto &num : nums)
            firstXorSec ^= num;

        // get rightmost set bit in above xor
        while (not(firstXorSec & mask))
            mask <<= 1;

        // get one of the distinct numbers
        for (auto &num : nums)
            if (num & mask)
                first ^= num;

        // return ans
        return {first, firstXorSec ^ first};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 4, 5, 5, 6};
    vector<int> res = sol.singleNumber(nums);
    cout << res[0] << " " << res[1] << '\n'; // Output: 6 4
}
