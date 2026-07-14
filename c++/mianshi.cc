
#include <vector>
class Solution{
    public:
    int intersection(std::vector<int>& nums_a, std::vector<int>& nums_b){
        for(int i=0;  i < nums_a.size(); i++){
            for(int j =0; j < nums_b.size(); j++){
                if (nums_b[j] == nums_a[i]){
                    return nums_a[i];
                } 
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> Array_1 = {1,3,4,6,6,9};
    std::vector<int> Array_2 = {1,3,4,6,6,9};
    
    int reslut = sol.intersection(Array_1,Array_2);
    return 0;
}