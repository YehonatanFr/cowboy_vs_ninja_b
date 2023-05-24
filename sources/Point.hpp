#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>

namespace ariel{
    class Point{
        private:
            double Xco;
            double Yco;

        public:
            Point();
            
            Point(double Xco, double Yco);

            double distance(const Point& other);
            
            static Point moveTowards(Point current, Point target, double distance);
            
            double getX() const{
                return Xco;
            }

            double getY() const{
                return Yco;
            }


            void setX(double Newx){
                Xco = Newx;
            }

            void setY(double Newy){
                Yco = Newy;
            }

            bool operator==(const Point& other) const;

            std::string print();
    };
}

#endif