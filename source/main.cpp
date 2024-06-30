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
    
    const Tuple point = Riptracer::create_point(4, -4, 3);
    expect(point.w == 1.0) << "epsilon=0.1";

    const Tuple vector = Riptracer::create_vector(4, -4, 3);
    expect(vector.w == 0.0) << "epsilon=0.1";

    const Tuple a1 = { 3, -2, 5, 1 };
    const Tuple a2 = { -2, 3, 1, 0 };
    expect((a1 + a2) == Tuple { 1, 1, 6, 1 });

    return 0;
}
