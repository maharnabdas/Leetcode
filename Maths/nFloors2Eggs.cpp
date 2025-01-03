// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/solutions/1248560/simple-math-problem-with-intuition-explained-o-1-time-o-1-space-python/
#include <iostream>

using std::cout;

class Solution {
public:
    int twoEggDrop(int n) {
        int count = 1;
        while (n > 0) {
            n = n-(count++);
        }
        return count-1;
    }
};

int main() {
  Solution sol;  
  cout << sol.twoEggDrop(100) << '\n'; // Output: 14;
}
