class Point
{
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    Point(const int x, const int y) : x(x), y(y) {}

    const int get_x() const
    {
        return x;
    }

    const int get_y() const
    {
        return y;
    }
};
