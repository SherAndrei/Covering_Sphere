#include <cmath>
#include "R2/intersection.h"
#include "geomerr.h"

#define PI M_PI

static inline double det(double a11, double a12, double a21, double a22) {
    return (a11 * a22 - a21 * a12);
}

std::shared_ptr<geom::ShapeR2> geom::intersect(const LineR2& A, const LineR2& B) {
    if (is_parallel(A, B))
        return std::make_shared<EmptySetR2>();

    double x, y;
    PointR2 a1 = A.a(), b1 = B.a();
    PointR2 a2 = A.a() + A.v(),
            b2 = B.a() + B.v();
    x = det(det(a1.x(), a1.y(), a2.x(), a2.y()), det(a1.x(), 1., a2.x(), 1.),
            det(b1.x(), b1.y(), b2.x(), b2.y()), det(b1.x(), 1., b2.x(), 1.)) /
        det(det(a1.x(), 1., a2.x(), 1.), det(a1.y(), 1., a2.y(), 1.),
            det(b1.x(), 1., b2.x(), 1.), det(b1.y(), 1., b2.y(), 1.));
    y = det(det(a1.x(), a1.y(), a2.x(), a2.y()), det(a1.y(), 1., a2.y(), 1.),
            det(b1.x(), b1.y(), b2.x(), b2.y()), det(b1.y(), 1., b2.y(), 1.)) /
        det(det(a1.x(), 1., a2.x(), 1.), det(a1.y(), 1., a2.y(), 1.),
            det(b1.x(), 1., b2.x(), 1.), det(b1.y(), 1., b2.y(), 1.));
    return std::make_shared<PointR2>(x, y);
}

static double discriminant(double a, double b, double c) {
    return sqrt(pow(b, 2.) - a * c);
}

static double sgn(double val) {
    return (val > GEOM_EPSILON) - (val < -GEOM_EPSILON);
}

std::shared_ptr<geom::ShapeR2> geom::intersect(const CircleR2& C, const LineR2& A) {
    PointR2 a1 = A.a(), a2 = A.a() + A.v();
    double dx = a2.x() - a1.x(),
           dy = a2.y() - a1.y();
    double dr = sqrt(pow(dx, 2.) + pow(dy, 2.)),
           D = det(a1.x(), a2.x(), a1.y(), a2.y());
    double d = pow(C.radius(), 2.) * pow(dr, 2.) - pow(D, 2.);

    if (d < 0) {
        return std::make_shared<EmptySetR2>();
    } else if (d < GEOM_EPSILON) {
        return std::make_shared<PointR2>(D * dy / pow(dr, 2.), - D * dx / pow(dr, 2.));
    } else {
        PointR2 a, b;
        a.set_x((+D * dy - sgn(dy) * dx * sqrt(d)) / pow(dr, 2.));
        a.set_y((-D * dx - fabs(dy) * sqrt(d)) / pow(dr, 2.));

        b.set_x((+D * dy + sgn(dy) * dx * sqrt(d)) / pow(dr, 2.));
        b.set_y((-D * dx + fabs(dy) * sqrt(d)) / pow(dr, 2.));

        return std::make_shared<SegmentR2>(a, b);
    }
}

// Segment operator&(const Circle& a,const Circle& b)
// {
//     Segment A;
//     Point aa,bb,j;
//     double t,h,d;
//     d=sqrt((a.a.GetX()-b.a.GetX())*(a.a.GetX()-b.a.GetX()) + (a.a.GetY()-b.a.GetY())*(a.a.GetY()-b.a.GetY()));
//     if (d>fabs(a.GetR()+b.GetR()))
//     {
//         A.SetZ(-1);
//         return A;
//     }
//     if (d<fabs(a.GetR()-b.GetR()))
//     {
//         A.SetZ(-1);
//         return A;
//     }
//     t=(a.GetR()*a.GetR()-b.GetR()*b.GetR()+d*d)/(2*d);
//     if (fabs(d-(a.GetR()+b.GetR()))<0.00000000001)
//     {
//         t=a.GetR();
//     }
//     h=sqrt(a.GetR()*a.GetR()-t*t);
//     j.setpoint(a.a.GetX()+t*(b.a.GetX()-a.a.GetX())/d, a.a.GetY()+t*(b.a.GetY()-a.a.GetY())/d, true);
//     aa.SetX(j.GetX()+h*(b.a.GetY()-a.a.GetY())/d);
//     aa.SetY(j.GetY()-h*(b.a.GetX()-a.a.GetX())/d);
//     bb.SetX(j.GetX()-h*(b.a.GetY()-a.a.GetY())/d);
//     bb.SetY(j.GetY()+h*(b.a.GetX()-a.a.GetX())/d);
//     A.SetS(aa,bb,1);
//     return A;
// }
