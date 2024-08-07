#pragma once

#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#define DefineVectorAbbr(size, abbreviation, type) \
    using Vec##size##abbreviation = Vector##size<type>

#define DefineVectorFamily(size) \
    DefineVectorAbbr(size, b, std::int8_t); \
    DefineVectorAbbr(size, ub, std::uint8_t); \
    \
    DefineVectorAbbr(size, s, std::int16_t); \
    DefineVectorAbbr(size, us, std::uint16_t); \
    \
    DefineVectorAbbr(size, i, std::int32_t); \
    DefineVectorAbbr(size, ui, std::uint32_t); \
    \
    DefineVectorAbbr(size, l, std::int64_t); \
    DefineVectorAbbr(size, ul, std::uint64_t); \
    \
    DefineVectorAbbr(size, f, float); \
    DefineVectorAbbr(size, d, double) \

DefineVectorFamily(2);
DefineVectorFamily(3);
DefineVectorFamily(4);

#undef DefineVectorFamily
#undef DefineVectorAbbr
