#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc Point (tọa độ 2D)
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Định nghĩa cấu trúc Node (nút trong cây RRT)
struct Node {
    Point point;
    int parent; // Chỉ số của nút cha trong cây
    Node(Point p = Point(), int parent = -1) : point(p), parent(parent) {}
};

// Hàm tính khoảng cách Euclid giữa 2 điểm
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Kiểm tra va chạm với vật cản
bool isCollisionFree(Point a, Point b, Point obstacleMin, Point obstacleMax) {
    // Đơn giản: Kiểm tra đoạn thẳng a-b có giao với vật cản không
    // (Ứng dụng thực tế cần dùng thuật toán phức tạp hơn như Bresenham)
    if (max(a.x, b.x) < obstacleMin.x || min(a.x, b.x) > obstacleMax.x ||
        max(a.y, b.y) < obstacleMin.y || min(a.y, b.y) > obstacleMax.y) {
        return true; // Không va chạm
    }
    return false; // Va chạm
}

// Hàm sinh điểm ngẫu nhiên
Point randomSample(int spaceSize) {
    return Point(rand() % spaceSize, rand() % spaceSize);
}

// Thuật toán RRT cơ bản
vector<Node> rrt(Point start, Point goal, Point obstacleMin, Point obstacleMax, int spaceSize = 10, int maxIter = 1000) {
    vector<Node> tree;
    tree.push_back(Node(start, -1)); // Thêm nút gốc

    srand(time(0));

    for (int i = 0; i < maxIter; ++i) {
        // Bước 1: Lấy mẫu ngẫu nhiên
        Point q_rand = randomSample(spaceSize);

        // Bước 2: Tìm nút gần nhất
        int nearestIdx = 0;
        double minDist = distance(tree[0].point, q_rand);
        for (size_t j = 1; j < tree.size(); ++j) {
            double dist = distance(tree[j].point, q_rand);
            if (dist < minDist) {
                minDist = dist;
                nearestIdx = j;
            }
        }

        // Bước 3: Mở rộng cây (dịch 1 đơn vị về phía q_rand)
        Point q_near = tree[nearestIdx].point;
        Point direction(q_rand.x - q_near.x, q_rand.y - q_near.y);
        double dirLength = distance(q_near, q_rand);
        Point q_new(
            q_near.x + (direction.x / dirLength), // Bước tối đa = 1
            q_near.y + (direction.y / dirLength)
        );

        // Bước 4: Kiểm tra va chạm
        if (isCollisionFree(q_near, q_new, obstacleMin, obstacleMax)) {
            tree.push_back(Node(q_new, nearestIdx));

            // Bước 5: Kiểm tra đích
            if (distance(q_new, goal) < 1.0) { // Ngưỡng đạt đích
                tree.push_back(Node(goal, tree.size() - 1));
                cout << "Tim thay duong di sau " << i << " lan lap!" << endl;
                return tree;
            }
        }
    }

    cout << "Khong tim thay duong di!" << endl;
    return tree;
}

// Hàm in đường đi từ cuối về start
void printPath(const vector<Node>& tree) {
    if (tree.empty()) return;

    int current = tree.size() - 1;
    vector<Point> path;

    while (current != -1) {
        path.push_back(tree[current].point);
        current = tree[current].parent;
    }

    reverse(path.begin(), path.end());

    cout << "Duong di tu start den goal:" << endl;
    for (const auto& p : path) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
}

int main() {
    // Thiết lập bài toán
    Point start(1, 1);
    Point goal(9, 9);
    Point obstacleMin(4, 3); // Góc trái dưới vật cản
    Point obstacleMax(6, 7); // Góc phải trên vật cản

    // Chạy RRT
    vector<Node> tree = rrt(start, goal, obstacleMin, obstacleMax);

    // In đường đi nếu tìm thấy
    if (!tree.empty() && tree.back().point.x == goal.x && tree.back().point.y == goal.y) {
        printPath(tree);
    }

    return 0;
}

/*
10|          B (9,9)
  |          / 
  |        /
  |      /   
  |    /     
7 |   +-----+ 
  |   |     | 
6 |   |     | 
5 |   |     | 
4 |   |     | 
3 |   +-----+ 
  |  A (1,1)
  +-----------------
    1 2 3 4 5 6 7 8 9 10
*/