/*
  In this problem, you have two decisions you can make. Pick the number at the current index, or skip that number.
  size_t is a system-dependent type that is used for defining something that holds size (hence by default leads to a non-negative integer), for ex: vector, string or int.
  For vec or str, more specifically: vector<int>::size_type, string::size_type or decltype(x.size()) i.
  In C++, the header file for size_t, header file: <cstddef>, for C <stddef.h> (pre-included in a lot of header files).
*/

#include <vector>
#include <iostream>

using std::cout;
using std::vector;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result = {{}};
        for (int num : nums)
        {
            int size = result.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> newSubset = result[i];
                newSubset.push_back(num);
                result.push_back(newSubset);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsetsResult = sol.subsets(nums);

    for (const auto &subset : subsetsResult)
    {
        cout << "[";
        for (vector<int>::size_type i = 0; i < subset.size(); i++)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    return 0;
}
