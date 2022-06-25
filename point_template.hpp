#pragma once
#include<complex>
#include<iostream>

template<typename T> struct Point
{
    T x,y;
    Point() : x(0),y(0){}
    Point (T x_, T y_) : x(x_),y(y_){}
    template<typename U> explicit Point(const Point<U> &p): x(p.x),y(p.y){}
    Point(const std::pair<T,T>&p):x(p.first),y(p.second){}
    Point(const std::complex<T> &p):x(real(p)),y(imag(p)){}
    explicit operator std::pair<T,T> () const {return std::pair<T,T> (x,y);}
    explicit operator std::complex<T> () const {return std::complex<T>(x,y);}
    friend std::ostream & operator<<(std::ostream & o, const Point &p)
    {
        return o <<'('<<p.x<<','<<p.y<<')';
    }
    friend std::istream & operator >> (std::istream &i, Point&p){return i>>p.x>>p.y;}
    friend bool operator == (const Point & a, const Point &b) {return a.x ==b.x && a.y==b.y;}
    friend bool operator !=(const Point &a, const Point &b){return !(a==b);}

    Point operator +() const {return Point(+x,+y);}
    Point operator -() const {return Point(-x,-y);}
    Point & operator += (const Point&p) {x+= p.x,y+= p.y;return *this;}
    Point & operator -=(const Point &p) {x-= p.x,y-=p.x; return *this;}
    Point & operator *= (const Point &p) {x*= p.x, y*=p.y;return *this;}
    Point & operator /=(const Point &p) {x/= p.x, y/= p.y; return *this;}

    friend Point operator + (const Point &a, const Point &b) {return Point(a.x+b.x, a.y+b.y);}
    friend Point operator - (const Point &a, const Point &b) {return Point(a.x-b.x,a.y-b.y);}
    friend Point operator * (const Point &a, const Point &b) {return Point(a.x*b.x, a.y*b.y);}
    friend Point operator / (const Point &a, const Point &b) {return Point(a.x/b.x, a.y/b.y);}


    T dist2() const {return x*x+y*y;}
    auto dist() const {return std::sqrt(dist2());}
    Point unit() const {return *this/this->dist();}
    auto  angle() const {return std::atan2(y,x);}


    T int_normal() const {return __gcd(x,y);}
    Point int_unit() const { if (!x &&!y)return *this; return *this/this->int_norm();}

    // convenient free-functions, mostly for generic interop
    friend auto norm( const Point &a) {return a.dist2();}
    friend auto abs(const Point &a) {return a.dist();}
    friend auto unit(const Point &a) {return a.unit();}
    friend auto arg(const Point &a) {return a.angle();}
    friend auto int_norm(const Point &a){return a.int_norm();}
    friend auto int_unit(const Point &a) { return a.int_unit();}

    Point perp_cw() const {return Point(y,-x);}
    Point perp_ccw() const {return Point(-y,x);}


    friend T dot (const Point &a, const Point &b) {return a.x*b.x+a.y*b.y;}




};
