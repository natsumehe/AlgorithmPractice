package geohashapp

import (
	"fmt"
	"go_algrithom/pkg/geo"
)

func main() {
	lat := 39.9042
	lng := 116.4074
	hash := geo.EncodeGeoHash(lat, lng, 5)
	fmt.Printf("Geohash: %s\n", hash)
}
