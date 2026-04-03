package main

import (
	"fmt"
	"go_algrithom/pkg/algrithom/sort_al"
)

func main() {

	unsorted := []int{64, 34, 25, 12, 22, 11, 90}
	fmt.Printf("Unsorted: %v\n", unsorted)
	sorted := make([]int, len(unsorted))
	copy(sorted, unsorted)
	sort_al.QuickSort(sorted)
	// sort_al.BubbleSort(sorted)
	fmt.Printf("Quick Sorted: %v\n,", sorted)
}
