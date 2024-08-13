#include "../Vector4.hpp"

#include "Defines.hpp"

GMLSpaceStart

#define Template template <class _Type>
#define Vector4T Vector4<_Type>
#define Vector4TDef(returnType) Template returnType \
    Vector4T

Vector4TDef()::Vector4(const Base& vector)
    : Base{ vector }
{}

Vector4TDef()::Vector4(Base&& vector)
    : Base{ std::move(vector) }
{}

Vector4TDef()::Vector4(const _Type value)
    : Base{ value }
{}

Vector4TDef()::Vector4(const _Type x, const _Type y, const _Type z,
    const _Type w)
{
    this->m_Data[0] = x;
    this->m_Data[1] = y;
    this->m_Data[2] = z;
    this->m_Data[3] = w;
}

DefineGetMethod(Vector4TDef, X, 0);
DefineGetMethod(Vector4TDef, Y, 1);
DefineGetMethod(Vector4TDef, Z, 2);
DefineGetMethod(Vector4TDef, W, 3);

Vector4TDef(Vector4T&)::operator = (const Base& vector) noexcept
{
    Base::operator = (vector);

    return *this;
}

Vector4TDef(Vector4T&)::operator = (Base&& vector) noexcept
{
    Base::operator = (std::move(vector));

    return *this;
}

DefineVectorFamily(4);

GMLSpaceEnd
