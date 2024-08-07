#include "../Operations.hpp"

#include "../Variables.hpp"

Angle ConvertToRadians(const Angle degrees) noexcept
{
    return degrees * PI / 180.0f;
}

Angle ConvertToDegrees(const Angle radians) noexcept
{
    return radians * 180.0f / PI;
}
