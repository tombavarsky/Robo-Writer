#include <point.h>

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

    const int get_digit() const
    {
        return digit;
    }

    const Point *get_draw_points() const
    {
        return draw_points;
    }

    virtual int get_digit_length() const = 0;

    virtual ~Digit() {}
};

class Zero : public Digit
{
    static const int digit_length = 5;

public:
    Zero() : Digit(0)
    {
        draw_points = new Point[digit_length];
        draw_points[0] = Point(0, top_y);          //top left
        draw_points[1] = Point(right_x, top_y);    //top right
        draw_points[2] = Point(right_x, bottom_y); //bottom right
        draw_points[3] = Point(0, bottom_y);       //bottom left
        draw_points[4] = Point(0, top_y);          //top left
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Zero()
    {
        delete[] draw_points;
    }
};

class One : public Digit
{
    static const int digit_length = 2;

public:
    One() : Digit(1)
    {
        draw_points = new Point[digit_length];
        draw_points[0] = Point(right_x, top_y);    //top right
        draw_points[1] = Point(right_x, bottom_y); //bottom right
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~One()
    {
        delete[] draw_points;
    }
};

class Two : public Digit
{
    static const int digit_length = 6;

public:
    Two() : Digit(2)
    {
        draw_points = new Point[digit_length];
        draw_points[0] = Point(0, top_y);          //top left
        draw_points[1] = Point(right_x, top_y);    //top right
        draw_points[2] = Point(right_x, middle_y); //middle right
        draw_points[3] = Point(0, middle_y);       //middle left
        draw_points[4] = Point(0, bottom_y);       //bottom left
        draw_points[5] = Point(right_x, bottom_y); //bottom right
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Two()
    {
        delete[] draw_points;
    }
};

class Three : public Digit
{
    static const int digit_length = 7;

public:
    Three() : Digit(3)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(0, top_y);          //top left
        draw_points[1] = Point(right_x, top_y);    //top right
        draw_points[2] = Point(right_x, middle_y); //middle right
        draw_points[3] = Point(0, middle_y);       //middle left
        draw_points[4] = Point(right_x, middle_y); //middle right
        draw_points[5] = Point(right_x, bottom_y); //bottom right
        draw_points[6] = Point(0, bottom_y);       //bottom left
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Three()
    {
        delete[] draw_points;
    }
};

class Four : public Digit
{
    static const int digit_length = 5;

public:
    Four() : Digit(4)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(0, top_y);          //top left
        draw_points[1] = Point(0, middle_y);       //middle left
        draw_points[2] = Point(right_x, middle_y); //middle right
        draw_points[3] = Point(right_x, top_y);    //top right
        draw_points[4] = Point(right_x, bottom_y); //bottom right
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Four()
    {
        delete[] draw_points;
    }
};

class Five : public Digit
{
    static const int digit_length = 6;

public:
    Five() : Digit(5)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(right_x, top_y);    //top right
        draw_points[1] = Point(0, top_y);          //top left
        draw_points[2] = Point(0, middle_y);       //middle left
        draw_points[3] = Point(right_x, middle_y); //middle right
        draw_points[4] = Point(right_x, bottom_y); //bottom right
        draw_points[5] = Point(0, bottom_y);       //bottom left
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Five()
    {
        delete[] draw_points;
    }
};

class Six : public Digit
{
    static const int digit_length = 6;

public:
    Six() : Digit(6)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(right_x, top_y);    //top right
        draw_points[1] = Point(0, top_y);          //top left
        draw_points[2] = Point(0, bottom_y);       //bottom left
        draw_points[3] = Point(right_x, bottom_y); //bottom right
        draw_points[4] = Point(right_x, middle_y); //middle right
        draw_points[5] = Point(0, middle_y);       //middle left
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Six()
    {
        delete[] draw_points;
    }
};

class Seven : public Digit
{
    static const int digit_length = 3;

public:
    Seven() : Digit(7)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(0, top_y);          //top left
        draw_points[1] = Point(right_x, top_y);    //top right
        draw_points[2] = Point(right_x, bottom_y); //bottom right
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Seven()
    {
        delete[] draw_points;
    }
};

class Eight : public Digit
{
    static const int digit_length = 8;

public:
    Eight() : Digit(8)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(0, middle_y);       //middle left
        draw_points[1] = Point(0, top_y);          //top left
        draw_points[2] = Point(right_x, top_y);    //top right
        draw_points[3] = Point(right_x, middle_y); //middle right
        draw_points[4] = Point(0, middle_y);       //middle left
        draw_points[5] = Point(0, bottom_y);       //bottom left
        draw_points[6] = Point(right_x, bottom_y); //bottom right
        draw_points[7] = Point(right_x, middle_y); //middle right
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Eight()
    {
        delete[] draw_points;
    }
};

class Nine : public Digit
{
    static const int digit_length = 6;

public:
    Nine() : Digit(9)
    {
        Point *draw_points = new Point[digit_length];
        draw_points[0] = Point(0, bottom_y);       //bottom left
        draw_points[1] = Point(right_x, bottom_y); //bottom right
        draw_points[2] = Point(right_x, top_y);    //top right
        draw_points[3] = Point(0, top_y);          //top left
        draw_points[4] = Point(0, middle_y);       //middle left
        draw_points[5] = Point(right_x, middle_y); //middle right
    }

    virtual int get_digit_length() const
    {
        return digit_length;
    }

    ~Nine()
    {
        delete[] draw_points;
    }
};
