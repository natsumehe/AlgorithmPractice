#include <stdio.h>


int fib_Re(int n){
    if (n == 1 or n ==2)return 1;
    return fib_Re(n-1) + fib_Re(n-2);
}

int main(){
  printf("%d",fib_Re(4));
  
}