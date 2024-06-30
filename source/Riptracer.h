//
// Created by theri on 6/30/2024.
//

#ifndef RAYTRACER_CPP_RIPTRACER_H
#define RAYTRACER_CPP_RIPTRACER_H

struct Tuple {
    float x;
    float y;
    float z;
    float w;

    auto operator == (const Tuple& a) const -> bool {
        return a.x == x && a.y == y && a.z == z && a.w == w;
    }

    auto operator + (const Tuple& a) const -> Tuple {
        return Tuple(a.x + x, a.y + y, a.z + z, a.w + w);
    }
};

class Riptracer {
public:
    Riptracer();
    static auto create_point(float x, float y, float z) -> Tuple;
    static auto create_vector(float x, float y, float z) -> Tuple;
};


#endif //RAYTRACER_CPP_RIPTRACER_H
