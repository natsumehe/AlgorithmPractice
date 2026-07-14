package main

import "fmt"

func inter(arr1 []int, arr2 []int) int {
	result := []int{}
	for _, v1 := range arr1 {
		for _, v2 := range arr2 {
			if v1 == v2 {
				result = append(result, v1)
		}
	}
	return result
}

func main() {
	a :=[]int{1,2,3,4,5,6}
	b := []int {2,3,4,5}
	fmt.Println("暴力法结果:", inter(a, b))
}
