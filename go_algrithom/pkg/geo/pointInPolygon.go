package geo

type Point struct {
	x, y float64
}

func isPointInPolygon(point Point, polygons []Point) bool {

	if len(polygons) < 3 {
		return false
	}

	inside := false

	// j 是 i 的前一个顶点
	j := len(polygons) - 1

	// 条件 A: 点 p 的 Y 坐标在边 p1p2 的 Y 轴范围之内
	// 条件 B: 射线（向右）与边 p1p2 有交点 (利用相似三角形原理求交点的 X 坐标)
	for i := 0; i < len(polygons); i++ {

		p1 := polygons[i]
		p2 := polygons[j]

		if (p1.y > point.y) != (p2.y > point.y) &&
			//相似三角形
			(point.x < (p1.x-p2.x)*(point.y-p1.y)/(p1.y-p2.y)+p1.x) {
			inside = !inside
		}
		j = i
	}
	return inside

}
