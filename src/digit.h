#include <point.h>

static const int place_constant = 50;
static const int bottom_y = 90;
static const int middle_y = 140;
static const int top_y = 190;
static const int right_x = 50;

const int const digit_lengths[10] = {5, 2, 6, 7, 5, 6, 6, 3, 8, 6};

class Digit
{
    int digit;

protected:
    Point *draw_points;

public:
    Digit(const int digit) : digit(digit) {}

    int get_digit()
    {
        return digit;
    }

    const Point *get_draw_points()
    {
        return draw_points;
    }

    virtual int get_digit_length() = 0;

    virtual ~Digit() {}
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

class One : Digit
{
    static const int digit_length = 2;

    One() : Digit(1)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(right_x + place_constant, top_y);    //top right  do we need place constant here?
        draw_points[1] = Point(right_x + place_constant, bottom_y); //bottom right  do we need place constant here?
    }

    virtual int get_digit_length()
    {
        return digit_length;
    }

    ~One()
    {
        delete[] draw_points;
    }
};
