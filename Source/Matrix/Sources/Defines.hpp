#pragma once

#include "../../Utility/Namespace.hpp"

GMLSpaceStart

#define DefineSquareMatrix(size, type) \
    template class Matrix<type, size, size>

#define DefineSqaureMatrixFamily(size) \
    DefineSquareMatrix(size, std::int8_t); \
    DefineSquareMatrix(size, std::uint8_t); \
    \
    DefineSquareMatrix(size, std::int16_t); \
    DefineSquareMatrix(size, std::uint16_t); \
    \
    DefineSquareMatrix(size, std::int32_t); \
    DefineSquareMatrix(size, std::uint32_t); \
    \
    DefineSquareMatrix(size, std::int64_t); \
    DefineSquareMatrix(size, std::uint64_t); \
    \
    DefineSquareMatrix(size, float); \
    DefineSquareMatrix(size, double) \

GMLSpaceEnd
