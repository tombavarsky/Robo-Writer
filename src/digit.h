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
public:
    Zero() : Digit(0)
    {
        const int digit_length = get_digit_length();
        Point *draw_points = (Point *)malloc(digit_length * sizeof(Point));
        draw_points[0] = Point(place_constant * position, top_y);
    }
};
