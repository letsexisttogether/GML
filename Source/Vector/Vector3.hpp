#pragma once

#include "Vector.hpp"

template <class _Type>
class Vector3 : public Vector<_Type, 3>
{
public:
    using Base = Vector<_Type, 3>;

public:
    Vector3() = default;
    Vector3(const Vector3&) = default; 
    Vector3(Vector3&&) = default; 

    Vector3(const Base& vector);
    Vector3(Base&& vector);

    Vector3(const _Type value);
    Vector3(const _Type x, const _Type y, const _Type z);

    ~Vector3() = default; 

    Vector3 Cross(const Vector3& vector) const noexcept;

    _Type& X() noexcept;
    _Type X() const noexcept;

    _Type& Y() noexcept;
    _Type Y() const noexcept;

    _Type& Z() noexcept;
    _Type Z() const noexcept;

    Vector3& operator = (const Vector3&) noexcept = default;
    Vector3& operator = (Vector3&&) noexcept = default;

    Vector3& operator = (const Base& vector) noexcept;
    Vector3& operator = (Base&& vector) noexcept;
};
