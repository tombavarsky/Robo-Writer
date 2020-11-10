class Point
{
    int x;
    int y;

public:
    Point(const int x, const int y)
    {
        this->x = x;
        this->y = y;
    }

    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }
};
