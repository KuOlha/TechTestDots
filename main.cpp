#include <iostream>
#include <list>
#include <dot.h>
#include <vector>
#include <math.h>

using namespace std;
    enum direction
    {
        north,
        east,
        south,
        west
    };

    vector<Dot*> dots;
    const int degree = 60;
    const int visibleDistance = 10;
    const double PI = 3.141592653589793;

    float tan_degree(float degree_param) //method that converts degrees to radians and calculates the tangent of an angle
    {
        return tan(degree_param*PI/180);
    }

    void get_angle_coefficient(float* left_coefficient, float* right_coefficient, int degree_param, int direction_param)
    //a method that calculates the angular coefficient for constructing the sector of visibility depending on the direction
    {
        switch(direction_param)
        //we calculate the angles and get the angular coefficients depending on the direction
        {
        case north:
            *left_coefficient = tan_degree(90 + degree_param);
            *right_coefficient = tan_degree(90-degree_param);
            break;
        case east:
            *left_coefficient = tan_degree(degree_param);
            *right_coefficient = tan_degree(-degree_param);
            break;
        case south:
            *left_coefficient = tan_degree(270 + degree_param);
            *right_coefficient = tan_degree(270-degree_param);
            break;
        case west:
            *left_coefficient = tan_degree(180 + degree_param);
            *right_coefficient = tan_degree(180-degree_param);
            break;
        }
    }

    void output_dot(Dot* any_dot)
    //method that outputs the parameters of the dot, which is output to the console
    {
        cout << "x: " << any_dot->getX() << "  ";
        cout << "y: " << any_dot->getY() << "  ";
        cout << "number: " << any_dot->getNumber() << "  ";
        cout << "direction: ";
        switch(any_dot->getDirection())
        //converts the integer value of the direction into a string value
        {
        case north:
            cout << "north" << endl;
            break;
        case east:
            cout << "east" << endl;
            break;
        case south:
            cout << "south" << endl;
            break;
        case west:
            cout << "west" << endl;
            break;

        }
    }


    vector<Dot*> VisiblePoints(Dot* any_dot, int degree_f, int distance_f)
    //a method that checks for dots in a given sector
    {
        vector<Dot*> return_dots; //an array of points that are in the given sector
        float left_coefficient, right_coefficient; //angular coefficients for constructing boundary lines of a given sector
        get_angle_coefficient(&left_coefficient, &right_coefficient, degree_f, any_dot->getDirection()); //calculation of angular coefficients
        any_dot->setLeftCoefficient(left_coefficient);
        any_dot->setRightCoefficient(right_coefficient);
        for(auto i = dots.begin() ; i != dots.end(); ++i)
        //iterates through the array to determine which dot is in the given sector
        {
            Dot* current_dot = *i; //we get a pointer to the current dot
            bool current_dot_visability = false; //check the dot visibility check box
            if(current_dot == any_dot) //checking that the starting dot is not a dot in the visibility sector
            {
                continue;
            }
            switch(any_dot->getDirection())
            //checking whether the current dot is in the given sector depending on the direction
            {
            case north:
                if((current_dot->getY() - any_dot->getY() >= left_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&(current_dot->getY() - any_dot->getY() >= right_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&((current_dot->getX() - any_dot->getX()) * (current_dot->getX() - any_dot->getX())
                      + (current_dot->getY() - any_dot->getY()) * (current_dot->getY() - any_dot->getY())
                      <= distance_f * distance_f)
                        )
                {
                    current_dot_visability = true;
                };
                break;
            case east:
                if((current_dot->getY() - any_dot->getY() <= left_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&(current_dot->getY() - any_dot->getY() >= right_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&((current_dot->getX() - any_dot->getX()) * (current_dot->getX() - any_dot->getX())
                      + (current_dot->getY() - any_dot->getY()) * (current_dot->getY() - any_dot->getY())
                      <= distance_f * distance_f)
                        )
                {
                    current_dot_visability = true;
                };
                break;
            case south:
                if((current_dot->getY() - any_dot->getY() <= left_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&(current_dot->getY() - any_dot->getY() <= right_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&((current_dot->getX() - any_dot->getX()) * (current_dot->getX() - any_dot->getX())
                      + (current_dot->getY() - any_dot->getY()) * (current_dot->getY() - any_dot->getY())
                      <= distance_f * distance_f)
                        )
                {
                    current_dot_visability = true;
                };
                break;
            case west:
                if((current_dot->getY() - any_dot->getY() >= left_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&(current_dot->getY() - any_dot->getY() <= right_coefficient * (current_dot->getX() - any_dot->getX()))
                   &&((current_dot->getX() - any_dot->getX()) * (current_dot->getX() - any_dot->getX())
                      + (current_dot->getY() - any_dot->getY()) * (current_dot->getY() - any_dot->getY())
                      <= distance_f * distance_f)
                        )
                {
                    current_dot_visability = true;
                };
                break;

            }
            if(current_dot_visability == true)
            //if the dot is in the given sector, we add it to the array of visible points
            {
                return_dots.insert(return_dots.end(), current_dot);
            }
        }
        return return_dots;
    }

int main()
{
    //we fill the array of dots
    dots.insert(dots.end(),new Dot(28, 42, 1, north));
    dots.insert(dots.end(),new Dot(27, 46, 2, east));
    dots.insert(dots.end(),new Dot(16, 22, 3, south));
    dots.insert(dots.end(),new Dot(40, 50, 4, west));
    dots.insert(dots.end(),new Dot(8, 6, 5, north));
    dots.insert(dots.end(),new Dot(6, 19, 6, east));
    dots.insert(dots.end(),new Dot(28, 5, 7, south));
    dots.insert(dots.end(),new Dot(39, 36, 8, west));
    dots.insert(dots.end(),new Dot(12, 34, 9, north));
    dots.insert(dots.end(),new Dot(36, 20, 10, east));
    dots.insert(dots.end(),new Dot(22, 47, 11, south));
    dots.insert(dots.end(),new Dot(33, 19, 12, west));
    dots.insert(dots.end(),new Dot(41, 18, 13, north));
    dots.insert(dots.end(),new Dot(41, 34, 14, east));
    dots.insert(dots.end(),new Dot(14, 29, 15, south));
    dots.insert(dots.end(),new Dot(6, 49, 16, west));
    dots.insert(dots.end(),new Dot(46, 50, 17, north));
    dots.insert(dots.end(),new Dot(17, 40, 18, east));
    dots.insert(dots.end(),new Dot(28, 26, 19, south));
    dots.insert(dots.end(),new Dot(2, 12, 20, west));


    for(auto i = dots.begin() ; i != dots.end(); ++i)
    //iterates over an array to determine the sector of visibility for each dot
    {
        Dot* current_dot = *i; //we get a pointer to the current dot
        vector<Dot*> visible_points_ready = VisiblePoints(current_dot, degree, visibleDistance); //we get an array of dots that are in the given sector
        cout << endl << "Visible dots from the dot " << current_dot->getNumber() << "are: " << endl; //output to the console the number of the current dot
        for(auto j = visible_points_ready.begin() ; j != visible_points_ready.end(); ++j)
        //output to the console of dots that are in the visibility sector
        {
            output_dot(*j);
        }
    }

    return 0;
}
