//
// Created by theri on 6/30/2024.
//

#ifndef RAYTRACER_CPP_RIPTRACER_H
#define RAYTRACER_CPP_RIPTRACER_H

struct Tuple {
    float x, y, z, w;

    Tuple(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
            : x(x), y(y), z(z), w(w) {}

    auto operator == (const Tuple& a) const -> bool {
        return a.x == x && a.y == y && a.z == z && a.w == w;
    }

    auto operator + (const Tuple& a) const -> Tuple {
        return Tuple { x + a.x, y + a.y, z + a.z, w + a.w };
    }

    auto operator - (const Tuple& a) const -> Tuple {
        return Tuple { x - a.x, y - a.y, z - a.z, w - a.w };
    }

    auto operator - () const -> Tuple {
        return Tuple { -x, -y, -z, -w };
    }

    auto operator * (float scalar) const -> Tuple {
        return Tuple { x * scalar, y * scalar, z * scalar, w * scalar};
    }

    auto operator / (float scalar) const -> Tuple {
        return Tuple { x / scalar, y / scalar, z / scalar, w / scalar};
    }
};

struct Vector : Tuple {
    Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f)
            : Tuple(x, y, z, 0.0f) {}

    // Vector-specific operations can be added here
};

struct Point : Tuple {
    Point(float x = 0.0f, float y = 0.0f, float z = 0.0f)
            : Tuple(x, y, z, 1.0f) {}

    // Point-specific operations can be added here
};

class Riptracer {
public:
    Riptracer();
    static auto create_point(float x, float y, float z) -> Tuple;
    static auto create_vector(float x, float y, float z) -> Tuple;
};


#endif //RAYTRACER_CPP_RIPTRACER_H
