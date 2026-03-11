package main

import "fmt"

func binarysearch_repead(nums []int, target int) int {
	left, right := 0, len(nums)-1
	ans := -1

	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			ans = mid
			right = mid - 1
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return ans
}

func main() {
	nums := []int{1, 3, 4, 5, 5, 6, 7, 7, 8, 9, 10}
	target := 7
	result := binarysearch_repead(nums, target)
	fmt.Printf("查找出%d第一个重复的数字的序列：%d \n", target, result)
}
