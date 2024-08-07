#include "../Vector.hpp"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <functional>

#define Template template <class _Type, std::uint8_t _Size>
#define VectorT Vector<_Type, _Size>
#define VectorTDef(returnType) Template returnType \
    VectorT

VectorTDef()::Vector(const _Type value)
{
    std::fill(m_Data, m_Data + _Size, value);
}

VectorTDef(typename VectorT::Length)::GetLength() const noexcept
{
    if (!m_Length)
    {
        CalculateLength();
    }

    return m_Length.value();
}

VectorTDef(void)::Normalize() noexcept
{
    const Length length = GetLength();

    for (std::size_t i = 0; i < _Size; ++i)
    {
        m_Data[i] /= length;
    }

    CalculateLength();
}

VectorTDef(VectorT)::GetNormalized() const noexcept
{
    Vector vector{ *this };
    vector.Normalize();

    return vector;
}

VectorTDef(void)::CalculateLength() const noexcept
{
    m_Length = Length{};

    for (std::size_t i = 0; i < _Size; ++i)
    {
        m_Length.value() += (m_Data[i] * m_Data[i]);
    }

    m_Length.value() = std::sqrt(m_Length.value());
}

VectorTDef(VectorT)::operator + (const _Type value) const noexcept
{
    return DoOperation(value, std::plus<_Type>{}); 
}

VectorTDef(VectorT)::operator + (const Vector& vector) const noexcept
{
    return DoOperation(vector, std::plus<_Type>{}); 
}

VectorTDef(VectorT)::operator - (const _Type value) const noexcept
{
    return DoOperation(value, std::minus<_Type>{}); 
}

VectorTDef(VectorT)::operator - (const Vector& vector) const noexcept
{
    return DoOperation(vector, std::minus<_Type>{}); 
}

VectorTDef(_Type)::Dot(const Vector& vector) const noexcept
{
    _Type result{};

    for (Index i = 0; i < _Size; ++i)
    {
        result += m_Data[i] * vector.m_Data[i];
    }

    return result;
}

VectorTDef(VectorT)::operator * (const _Type value) const noexcept
{
    return DoOperation(value, std::multiplies<_Type>{}); 
}

VectorTDef(VectorT)::operator * (const Vector& vector) const noexcept
{
    return DoOperation(vector, std::multiplies<_Type>{}); 
}

VectorTDef(VectorT)::operator / (const _Type value) const noexcept
{
    return DoOperation(value, std::divides<_Type>{}); 
}

VectorTDef(VectorT)::operator / (const Vector& vector) const noexcept
{
    return DoOperation(vector, std::divides<_Type>{}); 
}

VectorTDef(VectorT)::DoOperation(const _Type value, Operation operation)
    const noexcept
{
    Vector result{};

    for (Index i = 0; i < _Size; ++i)
    {
        result.m_Data[i] = operation(m_Data[i], value);
    }

    return result; 
}
VectorTDef(VectorT)::DoOperation(const Vector& vector, Operation operation)
    const noexcept
{
    Vector result{};

    for (Index i = 0; i < _Size; ++i)
    {
        result.m_Data[i] = operation(m_Data[i], vector.m_Data[i]);
    }

    return result; 
}

#define DefineVector(type, size) \
    template class Vector<type, size>;

#define DefineVectorByType(type) \
    DefineVector(type, 2); \
    DefineVector(type, 3); \
    DefineVector(type, 4)

DefineVectorByType(std::int8_t);
DefineVectorByType(std::uint8_t);

DefineVectorByType(std::int16_t);
DefineVectorByType(std::uint16_t);

DefineVectorByType(std::int32_t);
DefineVectorByType(std::uint32_t);

DefineVectorByType(std::int64_t);
DefineVectorByType(std::uint64_t);

DefineVectorByType(float);
DefineVectorByType(double);
