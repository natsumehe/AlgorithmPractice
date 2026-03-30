#include <stdio.h>
#include <stdbool.h> 

bool subset(int arr[], int i, int s){
    if (s == 0){
        return true;
    }else if(i < 0){
        return false;
    }else if(arr[i] > s ){
        return subset(arr, i-1,s);
    }else{
        bool A = subset(arr, i-1, s-arr[i]);
        bool B = subset(arr, i-1, s);
        return A || B;
    }

}

int main() {
    int arr[] = {3,34,4,12,5,2};
    printf("%s",subset(arr, (sizeof(arr)/sizeof(arr[0])) - 1, 9) ? "true" : "false");
}