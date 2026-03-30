#include <iostream>

void bubble_sort(int arr[], int L , int R){
    if (L < R){
        int temp;
        for (int i = L; i< R-1; i++){
            if(arr[i] >arr[i+1]){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
        bubble_sort(arr,  L,  R-1);
    }
}

int bubble(int *arr, int L, int R){
    if (L < R){
        int temp;
        for (int i = L; i< R-1; i++){
            if(arr[i] >arr[i+1]){
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
        bubble_sort(arr,  L,  R-1);
    }
    return 0;
};

int main() {
    int arr[] = {6,2,3,9,4,5,2,5,1};
     for (int i; i < sizeof(arr)/sizeof(arr[0]); i++){
        std::cout<<"冒泡排序数组的结果："<<arr[i] 
        <<"size大小："<<sizeof(arr);
     }
}