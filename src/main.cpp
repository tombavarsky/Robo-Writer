#include <Arduino.h>
#include <Servo.h>
#include <coordinate.h>
#include <digit.h>

int number[4] = {0};

Servo s1;
Servo s2;
Servo s3;

int get_num_length(const int num)
{
    return num < 10 ? 1 : floor(log10(num)) + 1;
}

void set_angle(const float x, const float y)
{
    static const float B_ARM = 140.50611; // mm
    static const float A_ARM = 105.38731; // mm

    static const byte X1 = 55;  // mm
    static const byte X2 = 145; // mm
    static const byte BASE = X2 - X1;

    const float diagonal1 = sqrt(pow(X1 - x, 2) + pow(y, 2));
    const float diagonal2 = sqrt(pow(X2 - x, 2) + pow(y, 2));

    const float s1_val = (acos((pow(diagonal1, 2) + pow(BASE, 2) - pow(diagonal2, 2)) / (2 * BASE * diagonal1)) * 180 / M_PI) +
                         (acos((pow(A_ARM, 2) + pow(diagonal1, 2) - pow(B_ARM, 2)) / (2 * diagonal1 * A_ARM)) * 180 / M_PI);
    //one of them should probably be 180 - answer
    const float s2_val = (acos((pow(diagonal2, 2) + pow(BASE, 2) - pow(diagonal1, 2)) / (2 * BASE * diagonal2)) * 180 / M_PI) +
                         (acos((pow(diagonal2, 2) + pow(A_ARM, 2) - pow(B_ARM, 2)) / (2 * A_ARM * diagonal2)) * 180 / M_PI);

    s1.write(s1_val);
    s2.write(s2_val);
}

void draw_digit(const byte digit, byte position)
{
    static const byte PLACE_CONSTANT = 50;
    static const byte UP_POSTION = 0;   //set later
    static const byte DOWN_POSTION = 0; //set later
    Digit *digit_to_draw = nullptr;

    switch (digit)
    {
    default:
    case 0:
    {
        digit_to_draw = new Zero();
        break;
    }
    case 1:
    {
        digit_to_draw = new One();
        break;
    }
    case 2:
    {
        digit_to_draw = new Two();
        break;
    }
    case 3:
    {
        digit_to_draw = new Three();
        break;
    }
    case 4:
    {
        digit_to_draw = new Four();
        break;
    }
    case 5:
    {
        digit_to_draw = new Five();
        break;
    }
    case 6:
    {
        digit_to_draw = new Six();
        break;
    }
    case 7:
    {
        digit_to_draw = new Seven();
        break;
    }
    case 8:
    {
        digit_to_draw = new Eight();
        break;
    }
    case 9:
    {
        digit_to_draw = new Nine();
        break;
    }
    }

    const Point *draw_points = (Point *)digit_to_draw->get_draw_points();
    for (int i = 0; i < digit_to_draw->get_digit_length(); i++)
    {
        set_angle(draw_points[i].get_x() + position * PLACE_CONSTANT, draw_points[i].get_y());
        s3.write(DOWN_POSTION);
        delay(50);
    }

    s3.write(UP_POSTION);

    delete digit_to_draw;
}

void setup()
{
    static const byte S1_PIN = 3;
    static const byte S2_PIN = 5;
    static const byte S3_PIN = 6;

    s1.attach(S1_PIN);
    s2.attach(S2_PIN);
    s3.attach(S3_PIN);

    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0)
    {
        int num = Serial.parseInt();
        const int num_len = get_num_length(num);
        for (int i = 0; i < num_len; i++)
        {
            draw_digit(num % 10, i);
            num /= 10;
        }
    }

    delay(1000);
}
