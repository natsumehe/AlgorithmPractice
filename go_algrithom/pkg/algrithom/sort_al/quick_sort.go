package sort_al

import "go_algrithom/pkg/algrithom/internal"

// QuickSort 对一个整数切片进行快速排序
func QuickSort(arr []int) {
	if len(arr) <= 1 {
		return
	}
	pivotIndex := partition(arr)
	QuickSort(arr[:pivotIndex])
	QuickSort(arr[pivotIndex+1:])
}

func partition(arr []int) int {
	pivot := arr[len(arr)-1]
	i := 0
	for j := 0; j < len(arr)-1; j++ {
		if arr[j] <= pivot {
			internal.Swap(arr, i, j)
			i++
		}
	}
	internal.Swap(arr, i, len(arr)-1)
	return i
}
