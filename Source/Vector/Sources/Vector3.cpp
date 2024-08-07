#include "../Vector3.hpp"

#include "Defines.hpp"

#define Template template <class _Type>
#define Vector3T Vector3<_Type>
#define Vector3TDef(returnType) Template returnType \
    Vector3T

Vector3TDef()::Vector3(const Base& vector)
    : Base{ vector }
{}

Vector3TDef()::Vector3(Base&& vector)
    : Base{ std::move(vector) }
{}

Vector3TDef()::Vector3(const _Type value)
    : Base{ value }
{}

Vector3TDef()::Vector3(const _Type x, const _Type y, const _Type z)
{
    this->m_Data[0] = x;
    this->m_Data[1] = y;
    this->m_Data[2] = z;
}

Vector3TDef(Vector3T)::Cross(const Vector3& vector) const noexcept
{
    const _Type x = Y() * vector.Z() - Z() * vector.Y();
    const _Type y = Z() * vector.X() - X() * vector.Z();
    const _Type z = X() * vector.Y() - Y() * vector.X();

    return { x, y, z };
}

DefineGetMethod(Vector3TDef, X, 0);
DefineGetMethod(Vector3TDef, Y, 1);
DefineGetMethod(Vector3TDef, Z, 2);

Vector3TDef(Vector3T&)::operator = (const Base& vector) noexcept
{
    Base::operator = (vector);

    return *this;
}

Vector3TDef(Vector3T&)::operator = (Base&& vector) noexcept
{
    Base::operator = (std::move(vector));

    return *this;
}

DefineVectorFamily(3);
