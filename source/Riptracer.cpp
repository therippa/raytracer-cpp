//
// Created by theri on 6/30/2024.
//

#include "Riptracer.h"
#include <spdlog/spdlog.h>

Riptracer::Riptracer() {
    spdlog::info("Riptracer class instanstiated");
}

auto Riptracer::create_point(float x, float y, float z) -> Tuple {
    return Tuple { x, y, z, 1.0 };
}


auto Riptracer::create_vector(float x, float y, float z) -> Tuple {
    return Tuple { x, y, z, 0.0 };
}
