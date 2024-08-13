#pragma once

#include "Vector.hpp"

GMLSpaceStart

template <class _Type>
class Vector4 : public Vector<_Type, 4>
{
public:
    using Base = Vector<_Type, 4>;

public:
    Vector4() = default;
    Vector4(const Vector4&) = default; 
    Vector4(Vector4&&) = default; 

    Vector4(const Base& vector);
    Vector4(Base&& vector);

    Vector4(const _Type value);
    Vector4(const _Type x, const _Type y, const _Type z,
        const _Type w);

    ~Vector4() = default; 

    _Type& X() noexcept;
    _Type X() const noexcept;

    _Type& Y() noexcept;
    _Type Y() const noexcept;

    _Type& Z() noexcept;
    _Type Z() const noexcept;

    _Type& W() noexcept;
    _Type W() const noexcept;

    Vector4& operator = (const Vector4&) noexcept = default;
    Vector4& operator = (Vector4&&) noexcept = default;

    Vector4& operator = (const Base& vector) noexcept;
    Vector4& operator = (Base&& vector) noexcept;
};

GMLSpaceEnd
