package search

import "testing"

func TestBinarySearch(t *testing.T) {
	cases := []struct {
		nums   []int
		target int
		want   int
	}{
		{nums: []int{1, 2, 3, 4, 5}, target: 3, want: 2},
		{nums: []int{1, 2, 3, 4, 5}, target: 6, want: -1},
		{nums: []int{}, target: 1, want: -1},
	}

	for _, c := range cases {
		got := BinarySearch(c.nums, c.target)

		t.Logf("输入数组：%v, 目标值：%d, 返回索引：%d", c.nums, c.target, got)
		if got != c.want {
			t.Errorf("BinarySearch(%v, %d) = %d, want %d", c.nums, c.target, got, c.want)
		}
	}
}
