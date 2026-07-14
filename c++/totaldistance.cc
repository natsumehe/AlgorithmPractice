#include <iostream>
#include <vector>

// 一个球从 100 米高的自由落下，每次落地后反跳回原高度的一半。求第 10 次弹起的高度与途径的总路程

int reslut(int strat, int times) {
    int height = strat;
    int totalDistance = 0;

    for (int i = 0; i < times; i++) {
        totalDistance += height;
        height /=2;
        totalDistance += height;
    }

    return totalDistance;
}

int main() {
    int statrHeight = 100;
    int times = 10;
    int reslut = reslut(statrHeight, times);
    std::cout << "Total Distance: " << reslut << std::endl;
    return 0;
}