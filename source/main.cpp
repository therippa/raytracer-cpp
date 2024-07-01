#include <iostream>
#include <spdlog/spdlog.h>
#include "boost/ut.hpp"
#include "Riptracer.h"

using namespace boost::ut;
using namespace boost::ut::spec;

constexpr auto sum(auto... values) { return (values + ...); }

auto main() -> int {
    spdlog::info("Hello world");

    Riptracer riptracer;

    Tuple a1, a2;
    Point p1, p2;
    Vector v1, v2;

    // a point is a tuple with w=1
    const Point point = { 4, -4, 3 };
    expect(Tuple { 4, -4, 3, 1 } == point) << "epsilon=0.1";

    // a vector is a tuple with w=0
    const Vector vector = { 4, -4, 3 };
    expect(Tuple { 4, -4, 3, 0 } == vector) << "epsilon=0.1";

    // adding two tuples
    a1 = { 3, -2, 5, 1 };
    a2 = { -2, 3, 1, 0 };
    expect((a1 + a2) == Tuple { 1, 1, 6, 1 });

    // subtracting two tuples
    p1 = { 3, 2, 1 };
    p2 = { 5, 6, 7 };
    expect((p1 - p2) == Vector { -2, -4, -6 });

    // subtracting a vector from a point
    p1 = { 3, 2, 1 };
    v1 = { 5, 6, 7 };
    expect((p1 - v1) == Point { -2, -4, -6 });

    // subtracting two vectors
    v1 = { 3, 2, 1 };
    v2 = { 5, 6, 7 };
    expect((v1 - v2) == Vector { -2, -4, -6 });

    // subtracting a vector from the zero vector
    v1 = { 0, 0, 0 };
    v2 = { 1, -2, 3 };
    expect((v1 - v2) == Vector { -1, 2, -3 });

    // negating a tuple
    a1 = { 1, -2, 3, -4 };
    expect(-a1 == Tuple { -1, 2, -3, 4 });

    // multiplying a tuple by a scalar
    a1 = { 1, -2, 3, -4 };
    expect((a1 * 3.5) == Tuple { 3.5, -7, 10.5, -14 });

    // multiplying a tuple by a fraction
    a1 = { 1, -2, 3, -4 };
    expect((a1 * 0.5) == Tuple { 0.5, -1, 1.5, -2 });

    // dividing a tuple by a scalar
    a1 = { 1, -2, 3, -4 };
    expect((a1 / 2) == Tuple { 0.5, -1, 1.5, -2 });

    // exit
    return 0;
}
