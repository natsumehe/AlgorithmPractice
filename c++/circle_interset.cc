#include <iostream>
#include <cmath>

struct circle {
    double x;
    double y;
    double radius;
};

//相交、相切、相离
bool isIntersect(const circle& c1, const circle& c2) {
    double distance = std::sqrt(std::pow(c1.x - c2.x, 2) + std::pow(c1.y - c2.y, 2));
    return distance <= (c1.radius + c2.radius);
}

int main() {
    circle c1 = {0.0, 0.0, 5.0};
    circle c2 = {3.0, 4.0, 5.0};

    if (isIntersect(c1, c2)) {
        std::cout << "The circles intersect or are tangent." << std::endl;
    } else {
        std::cout << "The circles are separate." << std::endl;
    }

    return 0;
}