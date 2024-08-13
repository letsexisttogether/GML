#pragma once

#include <cstddef>
#include <type_traits>

#include "../Utility/Namespace.hpp"

GMLSpaceStart

// Matrix class does not force you to create a square matrix.
// But good luck trying to do something else with it.
// Uses a column-major order 
template <class _Type, std::uint8_t _Columns, std::uint8_t _Rows>
class Matrix
{
static_assert(std::is_arithmetic_v<_Type>,
    "The matrix type must be arithmetical");

public:
    using Data = _Type[_Columns][_Rows]; 

public:
    Matrix() = default;
    Matrix(const Matrix&) = default;
    Matrix(Matrix&&) = default;

    ~Matrix() = default;

    const _Type* GetDataPointer() const noexcept;

    static std::size_t GetColumns() noexcept;
    static std::size_t GetRows() noexcept;

    _Type* operator [] (const std::size_t column) noexcept;
    const _Type* operator [] (const std::size_t column) const noexcept;

    // Matrix operator * (const Matrix& matrix) const noexcept;

    Matrix& operator = (const Matrix&) noexcept = default;
    Matrix& operator = (Matrix&&) noexcept = default;

public:
    static Matrix GetIdentity() noexcept;

private:
    Data m_Data{};
};

GMLSpaceEnd
