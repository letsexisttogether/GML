#include "../Matrix.hpp"

#include "Defines.hpp"

#define Template template <class _Type, std::uint8_t _Columns, \
    std::uint8_t _Rows>
#define MatrixT Matrix<_Type, _Columns, _Rows>
#define MatrixTDef(returnType) Template returnType \
    MatrixT

MatrixTDef(const _Type*)::GetDataPointer() const noexcept
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

/*
MatrixTDef(MatrixT)::operator * (const Matrix& matrix) const noexcept
{
    Matrix result{};

    const Matrix& thisMatrix = *this;

    for (std::size_t row = 0; row < thisMatrix.GetRows(); ++row)
    {
        for (std::size_t column = 0; column < matrix.GetColumns(); ++column)
        {
            for (std::size_t i = 0; i < matrix.GetColumns(); ++i)
            {
                result[row][column] += (thisMatrix[row][i] * matrix[i][column]);
            }
        }
    }

    return result;
}
*/

DefineSqaureMatrixFamily(1);
DefineSqaureMatrixFamily(2);
DefineSqaureMatrixFamily(3);
DefineSqaureMatrixFamily(4);
