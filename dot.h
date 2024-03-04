#ifndef DOT_H
#define DOT_H


class Dot
        //a class created for an object of type dot in which the parameters of the object and its methods are stored and processed
{
public:
    Dot(int _x,int _y,int _number,int _direction); //creator, method that creates a new object with initial parameters
    int getX(); //method that returns a private parameter x
    void setX(int _x); //method that stores the private parameter x
    int getY(); //method that returns a private parameter y
    void setY(int _y); //method that stores the private parameter y
    int getNumber(); //method that returns a private parameter number
    void setNumber(int _number); //method that stores the private parameter number
    int getDirection(); //method that returns a private parameter direction
    void setDirection(int _direction); //method that stores the private parameter direction
    float getLeftCoefficient(); //method that returns a private parameter angular coefficient of the line to the left of the coordinate axis
    void setLeftCoefficient(float _left_coefficient); //method that stores the private parameter angular coefficient of the line to the left of the coordinate axis
    float getRightCoefficient(); //method that returns a private parameter angular coefficient of the line to the right of the coordinate axis
    void setRightCoefficient(float _right_coefficient); //method that stores the private parameter angular coefficient of the line to the right of the coordinateт

private:
    int x; //coordinate of the dot along the x-axis
    int y; //coordinate of the dot along the y-axis
    int number; //serial number of dot (name)
    int direction; //the direction of the sector of visibility from the starting dot
    float left_coefficient; //angular coefficient of the line to the left of the coordinate axisт
    float right_coefficient; //angular coefficient of the line to the right of the coordinate axis
};

#endif // DOT_H
