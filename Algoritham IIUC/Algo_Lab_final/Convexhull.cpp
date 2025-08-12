#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    int x, y;
    Point(int x=0, int y=0) : x(x), y(y) {}
};

Point P0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool compare(Point a, Point b) {
    int o = orientation(P0, a, b);
    if (o == 0)
        return distSq(P0, a) < distSq(P0, b);
    return o == 2;
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};

    int minIndex = 0;
    for (int i=1; i<n; i++) {
        if (points[i].y < points[minIndex].y || 
            (points[i].y == points[minIndex].y && points[i].x < points[minIndex].x))
            minIndex = i;
    }
    swap(points[0], points[minIndex]);
    P0 = points[0];

    sort(points.begin()+1, points.end(), compare);

    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for (int i=3; i<n; i++) {
        while (s.size() >= 2) {
            Point top = s.top(); s.pop();
            Point nextToTop = s.top();
            if (orientation(nextToTop, top, points[i]) == 2) {
                s.push(top);
                break;
            }
        }
        s.push(points[i]);
    }

    vector<Point> hull;
    while (!s.empty()) {
        hull.push_back(s.top());
        s.pop();
    }
    reverse(hull.begin(), hull.end());
    return hull;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i=0; i<n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);
    for (auto p : hull) {
        cout << p.x << " " << p.y << "\n";
    }
    return 0;
}
