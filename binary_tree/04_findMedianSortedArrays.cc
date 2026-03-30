#include<iostream>

class Solution{
    public:
    int findMedianSortedArrays(int *nums1, int *nums2){
        int a = sizeof(nums1);
        int b = sizeof(nums2);

        if (a > b){
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0;
        int right = a;
        int halflen = (a+b+1) / 2;

        return 0;
    }

};

int mian() {
    Solution sol;
    int nums1[] = {1, 2, 3, 4, 4, 6, 6, 7, 8, 9};
    int nums2[] = {2, 3, 4, 5, 6, 7, 8, 9};
    
    int result = sol.findMedianSortedArrays(nums1, nums2);

    std::cout<<"有序数组中位数的值："<< result <<std::endl;
    return 0;
}
