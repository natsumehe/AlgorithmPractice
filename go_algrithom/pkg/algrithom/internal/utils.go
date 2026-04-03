package internal

func Swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

// IsSorted 检查一个整数切片是否已经排序
func IsSorted(arr []int) bool {
	for i := 1; i < len(arr); i++ {
		if arr[i] < arr[i-1] {
			return false
		}
	}
	return true
}
