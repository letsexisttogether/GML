#include "../Transformation.hpp"

#include <cmath>

Mat4x4f GetScale(const Vec3f& scaleVector) noexcept
{
    Mat4x4f matrix{ Mat4x4f::GetIdentity() };

    matrix[0][0] = scaleVector.X();
    matrix[1][1] = scaleVector.Y();
    matrix[2][2] = scaleVector.Z();

    return matrix;
}

Mat4x4f GetTranslation(const Vec3f& translationVector) noexcept
{
    Mat4x4f matrix{ Mat4x4f::GetIdentity() };

    matrix[3][0] = translationVector.X();
    matrix[3][1] = translationVector.Y();
    matrix[3][2] = translationVector.Z();

    return matrix;
}

Mat4x4f GetRotation(const Angle angle, const Vec3f& rotAxis)
    noexcept
{
    Mat4x4f matrix{};

    const float cos = std::cos(angle);
    const float sin = std::sin(angle);

    const float cosDiff = 1.0f - cos;

    const Vec3f normalAxis{ std::move(rotAxis.GetNormalized()) };

    const float xyCosDiff = normalAxis.X() * normalAxis.Y() * cosDiff;
    const float xzCosDiff = normalAxis.X() * normalAxis.Z() * cosDiff;
    const float yzCosDiff = normalAxis.Y() * normalAxis.Z() * cosDiff;

    const float xSin = normalAxis.X() * sin;
    const float ySin = normalAxis.Y() * sin;
    const float zSin = normalAxis.Z() * sin;

    const float xPowCosDiff = normalAxis.X() * normalAxis.X() * cosDiff;
    const float yPowCosDiff = normalAxis.Y() * normalAxis.Y() * cosDiff;
    const float zPowCosDiff = normalAxis.Z() * normalAxis.Z() * cosDiff;

    // We do hard code the values

    matrix[0][0] = cos + xPowCosDiff;
    matrix[0][1] = xyCosDiff + zSin;
    matrix[0][2] = xzCosDiff - ySin;

    matrix[1][0] = xyCosDiff - zSin;
    matrix[1][1] = cos + yPowCosDiff;
    matrix[1][2] = yzCosDiff + xSin;

    matrix[2][0] = xzCosDiff + ySin;
    matrix[2][1] = yzCosDiff - xSin;
    matrix[2][2] = cos + zPowCosDiff;

    matrix[3][3] = 1.0f;

    return matrix;
}
