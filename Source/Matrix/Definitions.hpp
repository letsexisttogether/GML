#pragma once

#include "Matrix.hpp"

GMLSpaceStart

#define DefineSquareMatrixAbbr(size, abbreviation, type) \
    using Mat##size##x##size##abbreviation = Matrix<type, size, size>

#define DefineSquareMatrixFamily(size) \
    DefineSquareMatrixAbbr(size, b, std::int8_t); \
    DefineSquareMatrixAbbr(size, ub, std::uint8_t); \
    \
    DefineSquareMatrixAbbr(size, s, std::int16_t); \
    DefineSquareMatrixAbbr(size, us, std::uint16_t); \
    \
    DefineSquareMatrixAbbr(size, i, std::int32_t); \
    DefineSquareMatrixAbbr(size, ui, std::uint32_t); \
    \
    DefineSquareMatrixAbbr(size, l, std::int64_t); \
    DefineSquareMatrixAbbr(size, ul, std::uint64_t); \
    \
    DefineSquareMatrixAbbr(size, f, float); \
    DefineSquareMatrixAbbr(size, d, double) \

DefineSquareMatrixFamily(1);
DefineSquareMatrixFamily(2);
DefineSquareMatrixFamily(3);
DefineSquareMatrixFamily(4);

#undef DefineSquareMatrixFamily
#undef DefineSquareMatrixAbbr

GMLSpaceEnd
