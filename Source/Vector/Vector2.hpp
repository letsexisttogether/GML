#pragma once

#include "Vector/Vector.hpp"

#define Template template <class _Type>
#define Vector2T Vector2<_Size>
#define Vector2TDef(returnType) Template returnType \
    Vector2T

Template
class Vector2 : public Vector<_Type, 2>
{
public:
    Vector2() = default;
    Vector2(const Vector2&) = default;
    Vector2(Vector2&&) = default;

    ~Vector2() = default;

    Vector2& operator = (const Vector2&) noexcept = default;
    Vector2& operator = (Vector2&&) noexcept = default;
};
