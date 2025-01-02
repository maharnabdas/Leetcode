// for reference on graycodes: https://www.geeksforgeeks.org/what-is-gray-code/
// leetcode problem: https://leetcode.com/problems/gray-code/description/?envType=problem-list-v2&envId=bit-manipulation
#include <vector>
#include <iostream>

using std::cout;
using std::vector;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        // base cases
        if (n == 1)
        {
            return {0, 1};
        }

        // recursive cases

        // get the grayCode for n-1

        vector<int> temp = grayCode(n - 1);
        int prevSize = temp.size();

        // now using the temp vector having gray code for n-1 we will construct the gray code for n
        vector<int> ans;

        // the first half of the 2^(n-1) elements of gray code for n will have 0 before the MSB of graycodes of n-1 which is same as all graycodes of n-1.
        for (int num : temp)
        {
            ans.push_back(num);
        }
        // the next half of the 2^(n-1) elements of gray code for n will have 1 before the MSB of graycodes of n-1 but in reverse order
        for (int i = prevSize - 1; i >= 0; i--)
        {
            int newGrayCode = (temp[i] | (1 << (n - 1)));
            ans.push_back(newGrayCode);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> ans = sol.grayCode(2); // ans should be 00 01 | 11 10; grayCode(1) yields 0 1
    for (int i = 0; i < 4; i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    // Output is 0 1 3 2
}
