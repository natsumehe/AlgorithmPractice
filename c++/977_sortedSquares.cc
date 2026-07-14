#include<vector>
#include<iostream>

class Solution{
    public:
    std::vector<int> sortedSquares(std::vector<int>& A){
        int k = A.size() - 1;
        std::vector<int> result (A.size(),0);
        for(int i = 0, j = A.size() - 1; i <= j;){
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }

        }
        return result;
    }

};

int main() {
    Solution sol;
    std::vector<int> nums = {1,2,3,4,5,6};
    std::vector<int> miusnums = {-5, -2,1,2,3,4};

    std::vector<int> result = sol.sortedSquares(miusnums);
    for (int num : result) {
        std::cout << num << " ";
        }      
}