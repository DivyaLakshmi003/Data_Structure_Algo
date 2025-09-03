/*
1291. Sequential Digits
Solved
Medium
Topics
premium lock icon
Companies
Hint
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        vector<int> result;
        
        for(int i = 1; i <= 8; i++){
            que.push(i);
        }

        while(!que.empty()){
            int tmp = que.front();
            que.pop();

            if(tmp>= low && tmp <= high) result.push_back(tmp);

            int lastDigit = tmp%10;
            if(lastDigit + 1 <= 9){
                tmp = tmp*10 + (lastDigit+1);
                if(tmp<=high) que.push(tmp);
            }
        }

        return result;
    }
};