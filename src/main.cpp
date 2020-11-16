#include <Arduino.h>
#include <Servo.h>
#include <coordinate.h>
#include <digit.h>

int number[4] = {0};

const float B_ARM = 140.50611; // mm
const float A_ARM = 105.38731; // mm

Servo s1;
Servo s2;
Servo s3;

const byte X1 = 55;  // mm
const byte X2 = 145; // mm
const byte BASE = X2 - X1;

int get_num_length(const int num)
{
    if (num < 10)
    {
        return 1;
    }
    else
    {
        return floor(log10(num)) + 1;
    }
}

void set_angle(const float x, const float y)
{
    const float diagonal1 = sqrt(pow(X1 - x, 2) + pow(y, 2));
    const float diagonal2 = sqrt(pow(X2 - x, 2) + pow(y, 2));

    const float s1_val = (acos((pow(diagonal1, 2) + pow(BASE, 2) - pow(diagonal2, 2)) / (2 * BASE * diagonal1)) * 180 / M_PI) + (acos((pow(A_ARM, 2) + pow(diagonal1, 2) - pow(B_ARM, 2)) / (2 * diagonal1 * A_ARM)) * 180 / M_PI);
    //one of them should probably be 180 - answer
    const float s2_val = (acos((pow(diagonal2, 2) + pow(BASE, 2) - pow(diagonal1, 2)) / (2 * BASE * diagonal2)) * 180 / M_PI) + (acos((pow(diagonal2, 2) + pow(A_ARM, 2) - pow(B_ARM, 2)) / (2 * A_ARM * diagonal2)) * 180 / M_PI);

    s1.write(s1_val);
    s2.write(s2_val);
}

// void draw_number()
// {
//     for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
//     {
//         Coordinate coordinate(number[i], i + 1);
//         //get digit "length"
//         const int digit_length = coordinate.digit_to_length();
//         //loop through number's length and set angle
//         for (int j = 0; j < digit_length; j++)
//         {
//             continue;
//         }
//     }
// }

void draw_digit(const byte digit, byte position)
{
    static const byte place_constant = 50;
    static const byte UP_POSTION = 0;   //set later
    static const byte DOWN_POSTION = 0; //set later
    switch (digit)
    {
    case 0:
    {
        Zero zero;
        Point *draw_points = (Point *)zero.get_draw_points();

        for (int i = 0; i < zero.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 1:
    {
        One one;
        Point *draw_points = (Point *)one.get_draw_points();

        for (int i = 0; i < one.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 2:
    {
        Two two;
        Point *draw_points = (Point *)two.get_draw_points();

        for (int i = 0; i < two.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 3:
    {
        Three three;
        Point *draw_points = (Point *)three.get_draw_points();

        for (int i = 0; i < three.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 4:
    {
        Four four;
        Point *draw_points = (Point *)four.get_draw_points();

        for (int i = 0; i < four.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 5:
    {
        Five five;
        Point *draw_points = (Point *)five.get_draw_points();

        for (int i = 0; i < five.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 6:
    {
        Six six;
        Point *draw_points = (Point *)six.get_draw_points();

        for (int i = 0; i < six.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 7:
    {
        Seven seven;
        Point *draw_points = (Point *)seven.get_draw_points();

        for (int i = 0; i < seven.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 8:
    {
        Eight eight;
        Point *draw_points = (Point *)eight.get_draw_points();

        for (int i = 0; i < eight.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    case 9:
    {
        Nine nine;
        Point *draw_points = (Point *)nine.get_draw_points();

        for (int i = 0; i < nine.get_digit_length(); i++)
        {
            set_angle(draw_points[i].get_x() + position * place_constant, draw_points[i].get_y());
            s3.write(DOWN_POSTION);
            delay(50);
        }

        s3.write(UP_POSTION);

        break;
    }
    default:
        break;
    }
}

void setup()
{
    s1.attach(3);
    s2.attach(5);
    s3.attach(6);

    Serial.begin(9600);
}

void read_number()
{
    if (Serial.available() > 0)
    {
        int num = Serial.parseInt();
        const int numLen = get_num_length(num);
        for (int i = numLen - 1; i >= 0; i--)
        {
            number[i] = num % 10;
            num /= 10;
        }
    }
}
void loop()
{
    read_number();
    for (int i = 0; i < sizeof(number) / sizeof(number[0]); i++)
    {
        draw_digit(number[i], i);
    }

    delay(1000);
}
