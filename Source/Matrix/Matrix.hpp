#pragma once

#include <cstddef>
#include <type_traits>

#define Template template <class _Type, std::size_t _Columns, \
    std::size_t _Rows>
#define MatrixT Matrix<_Type, _Columns, _Rows>
#define MatrixTDef(returnType) Template returnType \
    MatrixT

Template
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

    const _Type* GetRawData() const noexcept;

    static std::size_t GetColumns() noexcept;
    static std::size_t GetRows() noexcept;

    _Type* operator [] (const std::size_t column) noexcept;
    const _Type* operator [] (const std::size_t column) const noexcept;

    Matrix& operator = (const Matrix&) noexcept = default;
    Matrix& operator = (Matrix&&) noexcept = default;

public:
    static Matrix GetIdentity() noexcept;

private:
    Data m_Data{};
};


MatrixTDef(const _Type*)::GetRawData() const noexcept
{
    return &m_Data[0][0];
}


MatrixTDef(std::size_t)::GetColumns() noexcept
{
    return _Columns;
}

MatrixTDef(std::size_t)::GetRows() noexcept
{
    return _Rows;
}

MatrixTDef(_Type*)::operator [] (const std::size_t column) noexcept
{
    return m_Data[column];
}

MatrixTDef(const _Type*)::operator [] (const std::size_t column)
    const noexcept
{
    return m_Data[column];
}

MatrixTDef(MatrixT)::GetIdentity() noexcept
{
    Matrix matrix{};

    if (_Columns != _Rows)
    {
        return matrix;
    }

    for (std::size_t i = 0; i < _Columns; ++i)
    {
        matrix[i][i] = static_cast<_Type>(1);
    }

    return matrix;
}

#undef MatrixTDef
#undef MatrixT
#undef Template
