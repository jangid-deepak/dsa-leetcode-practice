#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    int width, height, x1, y1, x2, y2;

    cout << "Enter graph width and height: ";
    cin >> width >> height;
    cout << "Enter rectangle coordinates (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 < 0 || y1 < 0 || x2 >= width || y2 >= height || x1 > x2 || y1 > y2) {
        cout << "Invalid rectangle coordinates!" << endl;
        return 1;
    }

    // Create a blank white image
    Mat graph(height * 50, width * 50, CV_8UC3, Scalar(255, 255, 255));

    // Draw X and Y axes
    line(graph, Point(50, height * 50 - 50), Point(width * 50 - 50, height * 50 - 50), Scalar(0, 0, 0), 2);
    line(graph, Point(50, height * 50 - 50), Point(50, 50), Scalar(0, 0, 0), 2);

    // Convert rectangle coordinates to OpenCV points
    Point topLeft(50 + x1 * 50, height * 50 - 50 - y2 * 50);
    Point bottomRight(50 + x2 * 50, height * 50 - 50 - y1 * 50);

    // Draw the rectangle
    rectangle(graph, topLeft, bottomRight, Scalar(0, 0, 255), 2);

    // Show the graph
    imshow("Graph with Rectangle", graph);
    waitKey(0);

    return 0;
}
