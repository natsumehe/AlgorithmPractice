package main

import "fmt"

// / Binary Search Algorithm
// / Time Complexity: O(log n)
// / Space Complexity: O(1)
func binarysearch(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}
	return -1
}

func main() {
	nums := []int{1, 2, 4, 5, 7, 14, 18}
	target := 7
	fmt.Print(binarysearch(nums, target))
}
