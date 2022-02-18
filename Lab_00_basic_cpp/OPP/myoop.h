#include <iostream>

class Box
{
private:
    double height;
    double width;
    double depth;
public:
    Box(int h, int w, int d) {
        height = h;
        width = w;
        depth = d;
    }

    void printArea() {
        std::cout << "Volume: " << height * width * depth;
    }
};


