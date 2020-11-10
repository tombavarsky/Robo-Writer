class Point
{
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    Point(const int x, const int y) : x(x), y(y) {}

    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }
};
