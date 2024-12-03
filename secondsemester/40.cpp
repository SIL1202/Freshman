#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Point& other) const {
        return x < other.x;
    }
};

class MountainRange {
private:
    std::vector<Point> points;

public:
    void addPoint(int x, int y) {
        points.push_back(Point(x, y));
    }

    double calculateSunlitLength() {
        if (points.empty()) return 0.0;

        std::sort(points.begin(), points.end());

        double sum = 0.0;
        int maxH = points.back().y;  // Set the rightmost y coordinate as the highest point
        int rightest = points.back().x;

        for (int i = points.size() - 1; i > 0; --i) {
            if (points[i - 1].y > maxH) {
                double X = points[i - 1].x - static_cast<double>(points[i - 1].x - points[i].x) / (points[i - 1].y - points[i].y) * (points[i - 1].y - maxH);
                sum += std::sqrt(std::pow((points[i - 1].y - maxH), 2) + std::pow((points[i - 1].x - X), 2));
                maxH = points[i - 1].y;
            }
        }

        return sum;
    }
};

int main() {
    int n, m;
    std::cin >> n;

    while (n--) {
        std::cin >> m;
        MountainRange range;

        for (int i = 0; i < m; ++i) {
            int x, y;
            std::cin >> x >> y;
            range.addPoint(x, y);
        }

        std::cout << std::fixed << std::setprecision(2) << range.calculateSunlitLength() << std::endl;
    }

    return 0;
}

