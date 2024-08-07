#pragma once

#define DefineVector(size, type) \
    template class Vector##size<type>

#define DefineVectorFamily(size) \
    DefineVector(size, std::int8_t); \
    DefineVector(size, std::uint8_t); \
    \
    DefineVector(size, std::int16_t); \
    DefineVector(size, std::uint16_t); \
    \
    DefineVector(size, std::int32_t); \
    DefineVector(size, std::uint32_t); \
    \
    DefineVector(size, std::int64_t); \
    DefineVector(size, std::uint64_t); \
    \
    DefineVector(size, float); \
    DefineVector(size, double) \


#define DefineGetMethod(vectorName, name, index) \
    vectorName(_Type&)::name() noexcept \
    { \
        return this->m_Data[index]; \
    } \
    \
    vectorName(_Type)::name() const noexcept \
    { \
        return this->m_Data[index]; \
    }
