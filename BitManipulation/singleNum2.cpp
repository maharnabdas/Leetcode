#include <vector>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/single-number-ii/solutions/6072211/0-ms-runtime-beats-100-user-code-idea-algorithm-solving-step/?envType=problem-list-v2&envId=bit-manipulation
// One correction for the XOR method: twos stores the number of bits occuring %3 = 2 times.

// Brute Force approach
class Solution1
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;

        for (auto x : nums)
        {
            m[x]++;
        }

        for (auto x : m)
        {
            if (x.second == 1)
            {
                return x.first;
            }
        }

        return -1;
    }
};

// Bit Manipulation approach, 100% beats: time
class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (int num : nums)
            {
                sum += (num >> i) & 1;
            }
            sum %= 3;
            ans |= (sum << i);
        }

        return ans;
    }
};

// Using XOR
class Solution3
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0, twos = 0;

        for (const int &num : nums)
        {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
    }
};

int main()
{
    vector<int> nums = {2, 1, 2, 2};
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    int ans1 = sol1.singleNumber(nums); // ans1 = 1;
    int ans2 = sol2.singleNumber(nums); // ans2 = 1;
    int ans3 = sol3.singleNumber(nums); // ans3 = 1;
    cout << "Answer using:\nmethod 1: " << ans1 << "\nmethod 2: " << ans2 << "\nmethod 3: " << ans3 << '\n';
}
