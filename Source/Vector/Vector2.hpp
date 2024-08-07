#pragma once

#include "Vector.hpp"

template <class _Type>
class Vector2 : public Vector<_Type, 2>
{
public:
    using Base = Vector<_Type, 2>;

public:
    Vector2() = default;
    Vector2(const Vector2&) = default; 
    Vector2(Vector2&&) = default; 

    Vector2(const Base& vector);
    Vector2(Base&& vector);

    Vector2(const _Type value);
    Vector2(const _Type x, const _Type y);

    ~Vector2() = default; 

    _Type& X() noexcept;
    _Type X() const noexcept;

    _Type& Y() noexcept;
    _Type Y() const noexcept;

    Vector2& operator = (const Vector2&) noexcept = default;
    Vector2& operator = (Vector2&&) noexcept = default;

    Vector2& operator = (const Base& vector) noexcept;
    Vector2& operator = (Base&& vector) noexcept;
};
