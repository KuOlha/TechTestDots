#include "dot.h"

Dot::Dot(int _x,int _y,int _number,int _direction)
{
    setX(_x);
    setY(_y);
    setNumber(_number);
    setDirection(_direction);
}

int Dot::getX()
{
    return x;
}

void Dot::setX(int _x)
{
    x = _x;
}

int Dot::getY()
{
    return y;
}

void Dot::setY(int _y)
{
    y = _y;
}

int Dot::getNumber()
{
    return number;
}

void Dot::setNumber(int _number)
{
    number = _number;
}

int Dot::getDirection()
{
    return direction;
}

void Dot::setDirection(int _direction)
{
    direction = _direction;
}

float Dot::getLeftCoefficient()
{
    return left_coefficient;
}

void Dot::setLeftCoefficient(float _left_coefficient)
{
    left_coefficient = _left_coefficient;
}

float Dot::getRightCoefficient()
{
    return right_coefficient;
}

void Dot::setRightCoefficient(float _right_coefficient)
{
    right_coefficient = _right_coefficient;
}
