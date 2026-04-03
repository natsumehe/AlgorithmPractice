package geo

// 定义四个方向的字符映射表（简化演示）
var neighbors = map[string]map[string]string{
	"top":    {"even": "p0r21436x8zb9dcf5h7kjnmqesgutwvy", "odd": "bc01fg45238967deuvhjyznpkmstqrwx"},
	"bottom": {"even": "14365h7k9dcfesgutwvyb0r21436x8zb", "odd": "238967debc01fg45kmstqrwxuvhjyznp"},
	"right":  {"even": "bc01fg45238967deuvhjyznpkmstqrwx", "odd": "p0r21436x8zb9dcf5h7kjnmqesgutwvy"},
	"left":   {"even": "238967debc01fg45kmstqrwxuvhjyznp", "odd": "14365h7k9dcfesgutwvyb0r21436x8zb"},
}

// GetNeighbor 计算指定方向的一个邻居
func GetNeighbor(hash string, direction string) string {
	lastChar := string(hash[len(hash)-1])
	parent := hash[:len(hash)-1]

	// 判断当前位是奇数还是偶数（GeoHash 长度决定）
	isEven := len(hash)%2 == 0
	key := "odd"
	if isEven {
		key = "even"
	}

	// 从映射表中找到相邻字符
	// 注意：如果字符在当前层级溢出，需要递归处理父节点（此处略作简化）
	mapping := neighbors[direction][key]
	idx := -1
	const base32 = "0123456789bcdefghjkmnpqrstuvwxyz"
	for i, c := range base32 {
		if string(c) == lastChar {
			idx = i
			break
		}
	}

	return parent + string(mapping[idx])
}
