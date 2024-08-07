#pragma once

#include <cstdint>
#include <functional>
#include <optional>
#include <type_traits>

template <class _Type, std::uint8_t _Size>
class Vector
{
static_assert(std::is_arithmetic_v<_Type>,
    "The vector type must be arithmetical");
static_assert(_Size >= 1 && _Size <= 4,
    "The size of vector is bound to the range of [1; 4]");

public:
    using Data = _Type[_Size];
    using Length = typename std::conditional_t<std::is_same_v<_Type, double>,
        double, float>;

private:
    using Index = decltype(_Size);
    
    using Operation = std::function<_Type(_Type, _Type)>;

public:
    Vector() = default;
    Vector(const Vector&) = default;
    Vector(Vector&&) = default;

    Vector(const _Type value);

    virtual ~Vector() = default;

    Length GetLength() const noexcept;
    
    void Normalize() noexcept;
    Vector GetNormalized() const noexcept;

    // TODO: remove this out 
    const Data& GetRawData() const noexcept { return m_Data; }

    Vector operator + (const _Type value) const noexcept;
    Vector operator + (const Vector& vector) const noexcept;

    Vector operator - (const _Type value) const noexcept;
    Vector operator - (const Vector& vector) const noexcept;

    _Type Dot(const Vector& vector) const noexcept;

    Vector operator * (const _Type value) const noexcept;
    Vector operator * (const Vector& vector) const noexcept;

    Vector operator / (const _Type value) const noexcept;
    Vector operator / (const Vector& vector) const noexcept;

    Vector& operator = (const Vector&) noexcept = default;
    Vector& operator = (Vector&&) noexcept = default;

private:
    void CalculateLength() const noexcept;

    Vector DoOperation(const _Type value, Operation operation)
        const noexcept;
    Vector DoOperation(const Vector& vector, Operation operation)
        const noexcept;

protected:
    Data m_Data{};
    mutable std::optional<Length> m_Length{};
};
