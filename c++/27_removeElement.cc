#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    /// 快慢指针
    int removeElement(vector<int>& nums, int val){
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(nums[fastIndex] != val){
                cout  << "慢指针前:" << slowIndex <<endl;
                nums[slowIndex++] = nums[fastIndex];

                cout  << "慢指针后:" << slowIndex  << endl;
            }
        }
        return slowIndex;
    }
};

int main() {
    Solution sol;
    vector<int> Array = {1, 3, 3, 4,6, 8};
    int reslut = sol.removeElement(Array, 8);
    cout << reslut << endl;
    
    for (int i = 0; i < reslut; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;

    return 0;
}