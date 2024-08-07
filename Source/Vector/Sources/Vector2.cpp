#include "../Vector2.hpp"

#include "Defines.hpp"

#define Template template <class _Type>
#define Vector2T Vector2<_Type>
#define Vector2TDef(returnType) Template returnType \
    Vector2T

Vector2TDef()::Vector2(const Base& vector)
    : Base{ vector }
{}

Vector2TDef()::Vector2(Base&& vector)
    : Base{ std::move(vector) }
{}

Vector2TDef()::Vector2(const _Type value)
    : Base{ value }
{}

Vector2TDef()::Vector2(const _Type x, const _Type y)
{
    this->m_Data[0] = x;
    this->m_Data[1] = y;
}

DefineGetMethod(Vector2TDef, X, 0);
DefineGetMethod(Vector2TDef, Y, 1);

Vector2TDef(Vector2T&)::operator = (const Base& vector) noexcept
{
    Base::operator = (vector);

    return *this;
}

Vector2TDef(Vector2T&)::operator = (Base&& vector) noexcept
{
    Base::operator = (std::move(vector));

    return *this;
}

DefineVectorFamily(2);
