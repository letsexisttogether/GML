#pragma once

#include <cmath>
#include <cstddef>
#include <optional>
#include <type_traits>

#define Template template <class _Type, std::size_t _Size>
#define VectorT Vector<_Type, _Size>
#define VectorTDef(returnType) Template returnType \
    VectorT

#define DefineGetMethod(name, index) \
    _Type& name() noexcept \
    { \
        return this->m_Data[index]; \
    } \
    \
    _Type name() const noexcept \
    { \
        return this->m_Data[index]; \
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

    virtual ~Vector() = default;

    Length GetLength() const noexcept;

    Vector& operator = (const Vector&) noexcept = default;
    Vector& operator = (Vector&&) noexcept = default;

protected:
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
