package geo

import (
	"bytes"
)

// Base32 字符表（去掉了容易混淆的 a, i, l, o）
const base32Custom = "0123456789bcdefghjkmnpqrstuvwxyz"

func EncodeGeoHash(lat, lng float64, precision int) string {
	var latRange = []float64{-90, 90}
	var lngRange = []float64{-180, 180}
	var bits []int
	var geoHash bytes.Buffer

	// 每个字符代表 5 位，所以总共需要 precision * 5 位
	for i := 0; i < precision*5; i++ {
		if i%2 == 0 {
			// 偶数位算经度
			mid := (lngRange[0] + lngRange[1]) / 2
			if lng > mid {
				bits = append(bits, 1)
				lngRange[0] = mid
			} else {
				bits = append(bits, 0)
				lngRange[1] = mid
			}
		} else {
			// 奇数位算纬度
			mid := (latRange[0] + latRange[1]) / 2
			if lat > mid {
				bits = append(bits, 1)
				latRange[0] = mid
			} else {
				bits = append(bits, 0)
				latRange[1] = mid
			}
		}
	}

	// 每 5 位转为一个 Base32 字符
	for i := 0; i < len(bits); i += 5 {
		var index int
		for j := 0; j < 5; j++ {
			index = (index << 1) | bits[i+j]
		}
		geoHash.WriteByte(base32Custom[index])
	}

	return geoHash.String()
}
