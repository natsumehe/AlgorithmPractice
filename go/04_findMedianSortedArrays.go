package main

import (
	"fmt"
	"math"
)

// / 二分查找的方法(这里最重要的是处理边界的问题)
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	// 确保 nums1 是较短的数组，减少二分次数
	if len(nums1) > len(nums2) {
		return findMedianSortedArrays(nums2, nums1)
	}

	n, m := len(nums1), len(nums2)
	low, high := 0, n
	halfLen := (n + m + 1) / 2

	for low <= high {
		i := (low + high) / 2 // nums1 的切分点
		j := halfLen - i      // nums2 的切分点

		// 边界处理：如果切到了最左或最右，用无穷大/小代替
		var aLeft, aRight, bLeft, bRight float64
		if i == 0 {
			aLeft = math.Inf(-1)
		} else {
			aLeft = float64(nums1[i-1])
		}
		if i == n {
			aRight = math.Inf(1)
		} else {
			aRight = float64(nums1[i])
		}
		if j == 0 {
			bLeft = math.Inf(-1)
		} else {
			bLeft = float64(nums2[j-1])
		}
		if j == m {
			bRight = math.Inf(1)
		} else {
			bRight = float64(nums2[j])
		}

		if aLeft <= bRight && bLeft <= aRight {
			// 满足条件！开始计算中位数
			if (n+m)%2 == 1 {
				return math.Max(aLeft, bLeft)
			}
			return (math.Max(aLeft, bLeft) + math.Min(aRight, bRight)) / 2.0
		} else if aLeft > bRight {
			// nums1 左边太大了，切分点左移
			high = i - 1
		} else {
			// nums1 左边太小了，切分点右移
			low = i + 1
		}
	}
	return 0.0
}

func main() {
	nums1 := []int{1, 2, 3, 4, 4, 6, 6, 7, 8, 9}
	nums2 := []int{2, 3, 4, 5, 6, 7, 8, 9}

	result := findMedianSortedArrays(nums1, nums2)
	fmt.Printf("两个有序数组的中位是：%0.1f", result)
}
