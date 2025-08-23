/*
 * Vectors taken from Raylib-cpp wrapper 
 * PS: They have been modified to fit in a single header
 */

#pragma once

#ifndef RRE_NO_MATH
#include <cmath>
#endif

#include <string>
#include <utility>

#include "CBU.hpp"
#include "raylib.h"
#include "raymath.h"

namespace RRE::Types {

// Vector2 wrapper
class Vec2 : public ::Vector2 {
  public:
    Vec2(const ::Vector2 &vec) : ::Vector2{vec.x, vec.y} {}
    Vec2(float x, float y) : ::Vector2{x, y} {}
    Vec2(float x) : ::Vector2{x, 0} {}
    Vec2() : ::Vector2{0, 0} {}

    GETTERSETTER(float, X, x)
    GETTERSETTER(float, Y, y)

    Vec2 &operator=(const ::Vector2 &v) {
        set(v);
        return *this;
    }
    bool operator==(const ::Vector2 &o) const { return x == o.x && y == o.y; }
    bool operator!=(const ::Vector2 &o) const { return !(*this == o); }

    std::string ToString() const { return TextFormat("Vector2(%f, %f)", x, y); }
    operator std::string() const { return ToString(); }

#ifndef RRE_NO_MATH
    Vec2 Add(const ::Vector2 &v) const { return Vector2Add(*this, v); }
    Vec2 operator+(const ::Vector2 &v) const { return Vector2Add(*this, v); }
    Vec2 &operator+=(const ::Vector2 &v) {
        set(Vector2Add(*this, v));
        return *this;
    }

    Vec2 Subtract(const ::Vector2 &v) const {
        return Vector2Subtract(*this, v);
    }
    Vec2 operator-(const ::Vector2 &v) const {
        return Vector2Subtract(*this, v);
    }
    Vec2 &operator-=(const ::Vector2 &v) {
        set(Vector2Subtract(*this, v));
        return *this;
    }

    Vec2 Negate() const { return Vector2Negate(*this); }
    Vec2 operator-() const { return Vector2Negate(*this); }

    Vec2 Multiply(const ::Vector2 &v) const {
        return Vector2Multiply(*this, v);
    }
    Vec2 operator*(const ::Vector2 &v) const {
        return Vector2Multiply(*this, v);
    }
    Vec2 &operator*=(const ::Vector2 &v) {
        set(Vector2Multiply(*this, v));
        return *this;
    }

    Vec2 Scale(float s) const { return Vector2Scale(*this, s); }
    Vec2 operator*(float s) const { return Vector2Scale(*this, s); }
    Vec2 &operator*=(float s) {
        set(Vector2Scale(*this, s));
        return *this;
    }

    Vec2 Divide(const ::Vector2 &v) const { return Vector2Divide(*this, v); }
    Vec2 operator/(const ::Vector2 &v) const {
        return Vector2Divide(*this, v);
    }
    Vec2 &operator/=(const ::Vector2 &v) {
        set(Vector2Divide(*this, v));
        return *this;
    }

    Vec2 Divide(float d) const { return {x / d, y / d}; }
    Vec2 operator/(float d) const { return Divide(d); }
    Vec2 &operator/=(float d) {
        x /= d;
        y /= d;
        return *this;
    }

    Vec2 Normalize() const { return Vector2Normalize(*this); }
    Vec2 Transform(::Matrix m) const { return Vector2Transform(*this, m); }
    Vec2 Lerp(const ::Vector2 &v, float a) const {
        return Vector2Lerp(*this, v, a);
    }
    Vec2 Reflect(const ::Vector2 &n) const {
        return Vector2Reflect(*this, n);
    }
    Vec2 Rotate(float a) const { return Vector2Rotate(*this, a); }
    Vec2 MoveTowards(const ::Vector2 &t, float d) const {
        return Vector2MoveTowards(*this, t, d);
    }
    Vec2 Invert() const { return Vector2Invert(*this); }
    Vec2 Clamp(::Vector2 min, ::Vector2 max) const {
        return Vector2Clamp(*this, min, max);
    }
    Vec2 Clamp(float min, float max) const {
        return Vector2ClampValue(*this, min, max);
    }

    int Equals(::Vector2 q) const { return Vector2Equals(*this, q); }
    float Length() const { return Vector2Length(*this); }
    float LengthSqr() const { return Vector2LengthSqr(*this); }
    float DotProduct(const ::Vector2 &v) const {
        return Vector2DotProduct(*this, v);
    }
    float Distance(const ::Vector2 &v) const {
        return Vector2Distance(*this, v);
    }
    float DistanceSqr(::Vector2 v) const {
        return Vector2DistanceSqr(*this, v);
    }
    float Angle(const ::Vector2 &v) const { return Vector2Angle(*this, v); }

    static Vec2 Zero() { return Vector2Zero(); }
    static Vec2 One() { return Vector2One(); }
#endif

    void DrawPixel(::Color c = {0, 0, 0, 255}) const { DrawPixelV(*this, c); }
    void DrawLine(::Vector2 end, ::Color c = {0, 0, 0, 255}) const {
        DrawLineV(*this, end, c);
    }
    void DrawLine(::Vector2 end, float thick,
                  ::Color c = {0, 0, 0, 255}) const {
        DrawLineEx(*this, end, thick, c);
    }
    void DrawLineBezier(::Vector2 end, float thick,
                        ::Color c = {0, 0, 0, 255}) const {
        ::DrawLineBezier(*this, end, thick, c);
    }
    void DrawCircle(float r, ::Color c = {0, 0, 0, 255}) const {
        DrawCircleV(*this, r, c);
    }
    void DrawRectangle(::Vector2 size, ::Color c = {0, 0, 0, 255}) const {
        DrawRectangleV(*this, size, c);
    }
    void DrawPoly(int sides, float r, float rot,
                  ::Color c = {0, 0, 0, 255}) const {
        ::DrawPoly(*this, sides, r, rot, c);
    }

    bool CheckCollisionCircle(float r1, ::Vector2 c2, float r2) const {
        return CheckCollisionCircles(*this, r1, c2, r2);
    }
    bool CheckCollisionCircle(float r, ::Rectangle rec) const {
        return CheckCollisionCircleRec(*this, r, rec);
    }
    bool CheckCollision(::Rectangle rec) const {
        return CheckCollisionPointRec(*this, rec);
    }
    bool CheckCollision(::Vector2 c, float r) const {
        return CheckCollisionPointCircle(*this, c, r);
    }
    bool CheckCollision(::Vector2 p1, ::Vector2 p2, ::Vector2 p3) const {
        return CheckCollisionPointTriangle(*this, p1, p2, p3);
    }
    bool CheckCollisionLines(::Vector2 e1, ::Vector2 s2, ::Vector2 e2,
                             ::Vector2 *cp) const {
        return ::CheckCollisionLines(*this, e1, s2, e2, cp);
    }
    bool CheckCollisionPointLine(::Vector2 p1, ::Vector2 p2, int th = 1) const {
        return ::CheckCollisionPointLine(*this, p1, p2, th);
    }

  protected:
    void set(const ::Vector2 &v) {
        x = v.x;
        y = v.y;
    }
};

// Vector3 wrapper
class Vec3 : public ::Vector3 {
  public:
    Vec3() = default;
    Vec3(float x, float y, float z) : ::Vector3{x, y, z} {}

    explicit Vec3(const ::Vector3 &v) : ::Vector3{v} {}
    explicit Vec3(const ::Vector2 &v, float z = 0.0f)
        : ::Vector3{v.x, v.y, z} {}
    explicit Vec3(const ::Vector4 &v) : ::Vector3{v.x, v.y, v.z} {}

    Vec3 Add(const Vec3 &v) const {
        return Vec3(::Vector3Add(*this, v));
    }
    Vec3 Subtract(const Vec3 &v) const {
        return Vec3(::Vector3Subtract(*this, v));
    }
    Vec3 Multiply(float scalar) const {
        return Vec3(::Vector3Scale(*this, scalar));
    }
    Vec3 Divide(float scalar) const {
        return Vec3(::Vector3Scale(*this, 1.0f / scalar));
    }

    float Dot(const Vec3 &v) const { return ::Vector3DotProduct(*this, v); }
    Vec3 Cross(const Vec3 &v) const {
        return Vec3(::Vector3CrossProduct(*this, v));
    }
    float Length() const { return ::Vector3Length(*this); }
    Vec3 Normalize() const { return Vec3(::Vector3Normalize(*this)); }
    Vec3 Negate() const { return Vec3(::Vector3Negate(*this)); }

    Vec3 Lerp(const Vec3 &v, float t) const {
        return Vec3(::Vector3Lerp(*this, v, t));
    }

    // Operators
    Vec3 operator+(const Vec3 &v) const { return Add(v); }
    Vec3 operator-(const Vec3 &v) const { return Subtract(v); }
    Vec3 operator*(float scalar) const { return Multiply(scalar); }
    Vec3 operator/(float scalar) const { return Divide(scalar); }

    Vec3 &operator+=(const Vec3 &v) {
        *this = Add(v);
        return *this;
    }
    Vec3 &operator-=(const Vec3 &v) {
        *this = Subtract(v);
        return *this;
    }
    Vec3 &operator*=(float scalar) {
        *this = Multiply(scalar);
        return *this;
    }
    Vec3 &operator/=(float scalar) {
        *this = Divide(scalar);
        return *this;
    }
};

// Vector4 wrapper
class Vec4 : public ::Vector4 {
  public:
    Vec4() = default;
    Vec4(float x, float y, float z, float w) : ::Vector4{x, y, z, w} {}

    explicit Vec4(const ::Vector4 &v) : ::Vector4{v} {}
    explicit Vec4(const ::Vector2 &v, float z = 0.0f, float w = 0.0f)
        : ::Vector4{v.x, v.y, z, w} {}
    explicit Vec4(const ::Vector3 &v, float w = 0.0f)
        : ::Vector4{v.x, v.y, v.z, w} {}

    Vec4 Add(const Vec4 &v) const {
        return Vec4(::Vector4Add(*this, v));
    }
    Vec4 Subtract(const Vec4 &v) const {
        return Vec4(::Vector4Subtract(*this, v));
    }
    Vec4 Multiply(float scalar) const {
        return Vec4(::Vector4Scale(*this, scalar));
    }
    Vec4 Divide(float scalar) const {
        return Vec4(::Vector4Scale(*this, 1.0f / scalar));
    }

    float Dot(const Vec4 &v) const { return ::Vector4DotProduct(*this, v); }
    float Length() const { return ::Vector4Length(*this); }
    Vec4 Normalize() const { return Vec4(::Vector4Normalize(*this)); }

    Vec4 Lerp(const Vec4 &v, float t) const {
        return Vec4(::Vector4Lerp(*this, v, t));
    }

    // Operators
    Vec4 operator+(const Vec4 &v) const { return Add(v); }
    Vec4 operator-(const Vec4 &v) const { return Subtract(v); }
    Vec4 operator*(float scalar) const { return Multiply(scalar); }
    Vec4 operator/(float scalar) const { return Divide(scalar); }

    Vec4 &operator+=(const Vec4 &v) {
        *this = Add(v);
        return *this;
    }
    Vec4 &operator-=(const Vec4 &v) {
        *this = Subtract(v);
        return *this;
    }
    Vec4 &operator*=(float scalar) {
        *this = Multiply(scalar);
        return *this;
    }
    Vec4 &operator/=(float scalar) {
        *this = Divide(scalar);
        return *this;
    }
};

} // namespace raylib
