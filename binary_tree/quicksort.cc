#include <iostream>
#include <vector>

//严蔚敏版本--递归法--比较难理解--可以不理解
class Solution_yanweimin{
    public:
    int Paritition(int arr[], int low, int high){
        int pivot = arr[low];
        while(low < high){
            while (low < high && arr[high] >= pivot) {
                --high;
                    }
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot) {
                ++low;
            }
                arr[high] = arr[low];
            }
            arr[low] = pivot;
        return low;
    }
    void quickSort(int arr[], int low, int high){
        if (low < high) {
            int pivot = Paritition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
};

// class Solution{
//     public:
//     int Paritition(int arr[]){

//     }
// };

int main(){
    Solution_yanweimin sol;
    int arr[] = {1,3,4,6,7,8,4};
   
    
    sol.quickSort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    for(int num : arr){
        std::cout<<"排序后的数组地址："<< arr <<std::endl;
    }
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) { // 正确打印数组元素
        std::cout << arr[i] << " "<<std::endl;
    };
    

    std::vector<int> numbers = {1,2,3,4,5,8,3,2,1}; 

    return 0;
};