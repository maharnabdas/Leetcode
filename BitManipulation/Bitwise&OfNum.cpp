/*
  Brian Kernighan's Algorithm, https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
  Before doing this question I would recommend learning about Brian Kernighan's Algorithm which states that when we do bit wise and between n and n-1 , all the bits after the rightmost set bit (including the 
  rightmost set bit) flip. Now solve this question first. Coming to the current question. We have to do bit wise and for a given range. Since we know this algo we can just start at the right and go on 
  doing bitwise with n-1 element and make it new right until its lower than right. and then return the right. Now why does normal brute force doesn't work but this turns out to be 100% Faster? This is because Brian 
  Kernighan's Algorithm clears the rightmost set bit in each iteration, which typically requires fewer iterations compared to iterating through the entire range. In fact the time complexity is dependent on number of 
  bits. An integer n has log(n) bits, hence the worst case is O(log(n)).
  
  To get the result, you need to find the common prefix of left and right in their binary representation.
  0101 (left = 5)
  0111 (right = 7)
  0100 (result = 4, common prefix = 01)

  Leetcode link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=problem-list-v2&envId=bit-manipulation
*/

#include <iostream>
using std::cout;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};

int main() {
  Solution sol;
  int left = 5, right = 7;
  cout << sol.rangeBitwiseAnd(5, 7) << '\n';
}
  
