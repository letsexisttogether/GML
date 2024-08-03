#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <optional>
#include <type_traits>

#define Template template <class _Type, std::size_t _Size>
#define VectorT Vector<_Type, _Size>
#define VectorTDef(returnType) Template returnType \
    VectorT

#define CtorParam(exactValue, variableName) \
    std::enable_if_t<_Size == exactValue, const _InternalType> variableName

#define DeclareGetMethod(startValue, methodName, index) \
    template <std::size_t _InternalSize = _Size> \
    typename std::enable_if<_InternalSize >= startValue, _Type&>::type \
    methodName() noexcept \
    { \
        return m_Data[index]; \
    } \
    \
    template <std::size_t _InternalSize = _Size> \
    typename std::enable_if<_InternalSize >= startValue, _Type>::type \
    methodName() const noexcept \
    { \
        return m_Data[index]; \
    }

Template
class Vector
{
static_assert(std::is_arithmetic_v<_Type>,
    "The matrix type must be arithmetical");
static_assert(_Size >= 1 && _Size <= 4,
    "The size of vector is bound to the range of [1; 4]");

public:
    using Data = _Type[_Size];
    using Length = float;

public:
    Vector() = default;
    Vector(const Vector&) = default;
    Vector(Vector&&) = default;

    Vector(const _Type value);

    // Forgive me God for this
    template <class _InternalType = _Type>
    Vector(CtorParam(2, x), CtorParam(2, y))
        : m_Data{ x, y }
    {}

    template <class _InternalType = _Type>
    Vector(CtorParam(3, x), CtorParam(3, y), CtorParam(3, z))
        : m_Data{ x, y, z }
    {}

    template <class _InternalType = _Type>
    Vector(CtorParam(4, x), CtorParam(4, y), CtorParam(4, z), CtorParam(4, w))
        : m_Data{ x, y, z, w }
    {}

    ~Vector() = default;

    DeclareGetMethod(1, X, 0)
    DeclareGetMethod(2, Y, 1)
    DeclareGetMethod(3, Z, 2)
    DeclareGetMethod(4, W, 3)

    Length GetLength() const noexcept;

    Vector& operator = (const Vector&) noexcept = default;
    Vector& operator = (Vector&&) noexcept = default;

private:
    Data m_Data{};
    mutable std::optional<Length> m_Length{};
};


VectorTDef()::Vector(const _Type value)
{
    for (std::size_t i = 0; i < _Size; ++i)
    {
        m_Data[i] = value;
    }
}

VectorTDef(typename VectorT::Length)::GetLength() const noexcept
{
    if (m_Length)
    {
        return m_Length.value();
    }

    Length length{};
    for (std::size_t i = 0; i < _Size; ++i)
    {
        length += std::pow((m_Data[i], 2));
    }

    m_Length = std::sqrt(length);

    return m_Length.value();
}


#undef VectorT
#undef VectorTDef
#undef Template

#undef DeclareGetMethod
