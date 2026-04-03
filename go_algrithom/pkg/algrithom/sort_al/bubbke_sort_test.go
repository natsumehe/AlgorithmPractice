package sort_al

import (
	"sort"
	"testing"
)

func TestBubbleSort(t *testing.T) {
	cases := [][]int{
		{},
		{1},
		{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5},
		{5, 4, 3, 2, 1}, // 逆序
		{1, 2, 3, 4, 5}, // 已排序
	}

	for _, original := range cases {
		// 创建一个副本进行排序，避免修改原切片
		arrToSort := make([]int, len(original))
		copy(arrToSort, original)

		BubbleSort(arrToSort)

		t.Logf("冒泡排序前：%v, 冒泡排序后：%v", original, arrToSort)
		// 检查是否已排序
		if !sort.IntsAreSorted(arrToSort) {
			t.Errorf("BubbleSort(%v) = %v, want sorted", original, arrToSort)
		}
	}
}
