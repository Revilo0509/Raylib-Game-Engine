#pragma once

#include <box2d/box2d.h>
#include <raylib.h>

namespace RRE::Types {

struct  Vector2 {
    float x, y;

    Vector2(float x = 0, float y = 0) : x(x), y(y) {}
    Vector2(const ::Vector2 &v) : x(v.x), y(v.y) {}
    Vector2(const b2Vec2 &v) : x(v.x), y(v.y) {}

    operator ::Vector2() const { return ::Vector2{x, y}; }
    operator b2Vec2() const { return b2Vec2{ x, y }; }

    Vector2 &operator+=(const Vector2 &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vector2 &operator-=(const Vector2 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    Vector2 &operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    Vector2 &operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    Vector2 operator+() const { return *this; }
    Vector2 operator-() const { return Vector2(-x, -y); }
};

inline Vector2 operator+(Vector2 lhs, const Vector2 &rhs) {
    lhs += rhs;
    return lhs;
}
inline Vector2 operator-(Vector2 lhs, const Vector2 &rhs) {
    lhs -= rhs;
    return lhs;
}
inline Vector2 operator*(Vector2 lhs, float scalar) {
    lhs *= scalar;
    return lhs;
}
inline Vector2 operator*(float scalar, Vector2 rhs) {
    rhs *= scalar;
    return rhs;
}
inline Vector2 operator/(Vector2 lhs, float scalar) {
    lhs /= scalar;
    return lhs;
}

struct  Vector3 {
    float x, y, z;

    Vector3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    Vector3(const ::Vector3 &v) : x(v.x), y(v.y), z(v.z) {}

    operator ::Vector3() const { return ::Vector3{x, y, z}; }

    Vector3 &operator+=(const Vector3 &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vector3 &operator-=(const Vector3 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    Vector3 &operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    Vector3 &operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    Vector3 operator+() const { return *this; }
    Vector3 operator-() const { return Vector3(-x, -y, -z); }
};

inline Vector3 operator+(Vector3 lhs, const Vector3 &rhs) {
    lhs += rhs;
    return lhs;
}
inline Vector3 operator-(Vector3 lhs, const Vector3 &rhs) {
    lhs -= rhs;
    return lhs;
}
inline Vector3 operator*(Vector3 lhs, float scalar) {
    lhs *= scalar;
    return lhs;
}
inline Vector3 operator*(float scalar, Vector3 rhs) {
    rhs *= scalar;
    return rhs;
}
inline Vector3 operator/(Vector3 lhs, float scalar) {
    lhs /= scalar;
    return lhs;
}

struct  Vector4 {
    float x, y, z, w;

    Vector4(float x = 0, float y = 0, float z = 0, float w = 0)
        : x(x), y(y), z(z), w(w) {}
    Vector4(const ::Vector4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

    operator ::Vector4() const { return ::Vector4{x, y, z, w}; }

    Vector4 &operator+=(const Vector4 &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }
    Vector4 &operator-=(const Vector4 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }
    Vector4 &operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }
    Vector4 &operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    Vector4 operator+() const { return *this; }
    Vector4 operator-() const { return Vector4(-x, -y, -z, -w); }
};

inline Vector4 operator+(Vector4 lhs, const Vector4 &rhs) {
    lhs += rhs;
    return lhs;
}
inline Vector4 operator-(Vector4 lhs, const Vector4 &rhs) {
    lhs -= rhs;
    return lhs;
}
inline Vector4 operator*(Vector4 lhs, float scalar) {
    lhs *= scalar;
    return lhs;
}
inline Vector4 operator*(float scalar, Vector4 rhs) {
    rhs *= scalar;
    return rhs;
}
inline Vector4 operator/(Vector4 lhs, float scalar) {
    lhs /= scalar;
    return lhs;
}
} // namespace RRE::Types