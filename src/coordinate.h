#include <point.h>

class Coordinate
{
    static const int place_constant = 50;
    static const int bottom_y = 90;
    static const int middle_y = 140;
    static const int top_y = 190;
    static const int right_x = 50;
    int digit;
    int position;

    Point top_left;

    static const Point top_right(right_x + place_constant * position, top_y);
    static const Point bottom_right(right_x + place_constant * position, bottom_y)
        Point zero[5] = {

            {place_constant * (position), top_y},              //top left
            {right_x + place_constant * (position), top_y},    //top right
            {right_x + place_constant * (position), bottom_y}, //bottom right
            {place_constant * (position), bottom_y},           //bottom left
            {place_constant * (position), top_y}               //top left
    };

    int one[2][2] = {
        {right_x + place_constant * (position), top_y},   //top right
        {right_x + place_constant * (position), bottom_y} //bottom right
    };

    int two[6][2] = {
        {place_constant * (position), top_y},              //top left
        {right_x + place_constant * (position), top_y},    //top right
        {right_x + place_constant * (position), middle_y}, //middle right
        {place_constant * (position), middle_y},           //middle left
        {place_constant * (position), bottom_y},           //bottom left
        {right_x + place_constant * (position), bottom_y}  //bottom right
    };

    int three[7][2] = {
        {place_constant * (position), top_y},              //top left
        {right_x + place_constant * (position), top_y},    //top right
        {right_x + place_constant * (position), middle_y}, //middle right
        {place_constant * (position), middle_y},           //middle left
        {right_x + place_constant * (position), middle_y}, //middle right
        {right_x + place_constant * (position), bottom_y}, //bottom right
        {place_constant * (position), bottom_y}            //bottom left
    };

    int four[5][2] = {
        {place_constant * (position), top_y},              //top left
        {place_constant * (position), middle_y},           //middle left
        {right_x + place_constant * (position), middle_y}, //middle right
        {right_x + place_constant * (position), top_y},    //top right
        {right_x + place_constant * (position), bottom_y}  //bottom right
    };

    int five[6][2] = {
        {right_x + place_constant * (position), top_y},    //top right
        {place_constant * (position), top_y},              //top left
        {place_constant * (position), middle_y},           //middle left
        {right_x + place_constant * (position), middle_y}, //middle right
        {right_x + place_constant * (position), bottom_y}, //bottom right
        {place_constant * (position), bottom_y},           //bottom left
    };

    int six[6][2] = {
        {right_x + place_constant * (position), top_y},    //top right
        {place_constant * (position), top_y},              //top left
        {place_constant * (position), bottom_y},           //bottom left
        {right_x + place_constant * (position), bottom_y}, //bottom right
        {right_x + place_constant * (position), middle_y}, //middle right
        {place_constant * (position), middle_y}            //middle left
    };

    int seven[3][2] = {
        {place_constant * (position), top_y},             //top left
        {right_x + place_constant * (position), top_y},   //top right
        {right_x + place_constant * (position), bottom_y} //bottom right
    };

    int eight[8][2] = {
        {place_constant * (position), middle_y},           //middle left
        {place_constant * (position), top_y},              //top left
        {right_x + place_constant * (position), top_y},    //top right
        {right_x + place_constant * (position), middle_y}, //middle right
        {place_constant * (position), middle_y},           //middle left
        {place_constant * (position), bottom_y},           //bottom left
        {right_x + place_constant * (position), bottom_y}, //bottom right
        {right_x + place_constant * (position), middle_y}, //middle right
    };

    int nine[6][2] = {
        {place_constant * (position), bottom_y},           //bottom left
        {right_x + place_constant * (position), bottom_y}, //bottom right
        {right_x + place_constant * (position), top_y},    //top right
        {place_constant * (position), top_y},              //top left
        {place_constant * (position), middle_y},           //middle left
        {right_x + place_constant * (position), middle_y}, //middle right
    };

public:
    Coordinate(const int digit, const int position) : top_left(place_constant * position, top_y)
    {
        this->digit = digit;
        this->position = position;

        Point top_left(place_constant * position, top_y);
    }

    int digit_to_length()
    {

        switch (digit)
        {
        case 0:
            return 5;
            break;
        case 1:
            return 2;
            break;
        case 2:
            return 7;
            break;
        case 3:
            return 7;
            break;
        case 4:
            return 5;
            break;
        case 5:
            return 6;
            break;
        case 6:
            return 6;
            break;
        case 7:
            return 3;
            break;
        case 8:
            return 8;
            break;
        case 9:
            return 6;
            break;

        default:
            break;
        }
    }
};
