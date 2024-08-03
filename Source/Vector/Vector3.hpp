#pragma once

#include "Vector.hpp"

#define Template template <class _Type>
#define Vector3T Vector3<_Type>
#define Vector3TDef(returnType) Template returnType \
    Vector3T

Template
class Vector3 : public Vector<_Type, 3>
{
public:
    using Angle = float;

public:
    Vector3() = default;
    Vector3(const Vector3&) = default;
    Vector3(Vector3&&) = default;

    Vector3(const _Type x, const _Type y, const _Type z);

    ~Vector3() = default;

    DefineGetMethod(X, 0);
    DefineGetMethod(Y, 1);
    DefineGetMethod(Z, 2);

    // In degrees
    Angle CalculateAngleBetween(const Vector3& vector) const noexcept;

    Vector3 operator + (const _Type value) const noexcept;
    Vector3 operator + (const Vector3& vector) const noexcept;

    Vector3 operator - (const _Type value) const noexcept;
    Vector3 operator - (const Vector3& vector) const noexcept;

    _Type Dot(const Vector3& vector) const noexcept;

    Vector3 operator * (const _Type value) const noexcept;
    Vector3 operator * (const Vector3& vector) const noexcept;

    Vector3 Cross(const Vector3& vector) const noexcept;

    Vector3 operator / (const _Type value) const noexcept;
    Vector3 operator / (const Vector3& vector) const noexcept;

    Vector3& operator = (const Vector3&) noexcept = default;
    Vector3& operator = (Vector3&&) noexcept = default;
};

Vector3TDef()::Vector3(const _Type x, const _Type y, const _Type z)
{
    this->m_Data[0] = x;
    this->m_Data[1] = y;
    this->m_Data[2] = z;
}


Vector3TDef(typename Vector3T::Angle)::CalculateAngleBetween
    (const Vector3& vector) const noexcept
{
    const typename Vector3::Length thisLength = GetLength();
    const typename Vector3::Length otherLength = GetLength();

    const _Type dotProduct = Dot(vector);

    const float cos = (thisLength * otherLength) / dotProduct;

    return std::acos(cos);
}

Vector3TDef(Vector3T)::operator + (const _Type value) const noexcept
{
    return { X() + value, Y() + value, Z() + value };
}

Vector3TDef(Vector3T)::operator + (const Vector3& vector) const noexcept
{
    return { X() + vector.X(), Y() + vector.Y(), Z() + vector.Z() };
}

Vector3TDef(Vector3T)::operator - (const _Type value) const noexcept
{
    return { X() - value, Y() + value, Z() + value };
}

Vector3TDef(Vector3T)::operator - (const Vector3& vector) const noexcept
{
    return { X() - vector.X(), Y() - vector.Y(), Z() - vector.Z() };
}


Vector3TDef(_Type)::Dot(const Vector3& vector) const noexcept
{
    return X() * vector.X() + Y() * vector.Y() + Z() * vector.Z();
}

Vector3TDef(Vector3T)::operator * (const _Type value) const noexcept
{
    return { X() * value, Y() * value, Z() * value };
}

Vector3TDef(Vector3T)::operator * (const Vector3& vector) const noexcept
{
    return { X() * vector.X(), Y() * vector.Y(), Z() * vector.Z() };
}

Vector3TDef(Vector3T)::Cross(const Vector3& vector) const noexcept
{
    const _Type x = Y() * vector.Z() - Z() * vector.Y();
    const _Type y = Z() * vector.X() - X() * vector.Z();
    const _Type z = X() * vector.Y() - Y() * vector.X();

    return { x, y, z };
}

Vector3TDef(Vector3T)::operator / (const _Type value) const noexcept
{
    return { X() / value, Y() / value, Z() / value };
}

Vector3TDef(Vector3T)::operator / (const Vector3& vector) const noexcept
{
    return { X() / vector.X(), Y() / vector.Y(), Z() / vector.Z() };
}

#undef Vector3TDef
#undef Vector3T
#undef Template

#undef DefineGetMethod
