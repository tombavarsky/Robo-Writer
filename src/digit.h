#include <point.h>

class Digit
{
    int digit;
    static const int const digit_lengths[10];

protected:
    Point *draw_points;

public:
    Digit(const int digit)
    {
        this->digit = digit;
    }

    int get_digit_length()
    {
        return digit_lengths[digit];
    }
};

class Zero : public Digit
{
    static const int digit_length = 5;

public:
    Zero() : Digit(0)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(place_constant, top_y);              //top left
        draw_points[1] = Point(right_x + place_constant, top_y);    //top right
        draw_points[2] = Point(right_x + place_constant, bottom_y); //bottom right
        draw_points[3] = Point(place_constant, bottom_y);           //bottom left
        draw_points[4] = Point(place_constant, top_y);              //top left
    }

    virtual int get_digit_length()
    {
        return digit_length;
    }

    ~Zero()
    {
        delete[] draw_points;
    }
};
