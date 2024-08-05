#include "Matrix/MatrixDefenitions.hpp"
#include "Transformation.hpp"

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

Mat4x4f GetRotation(const Vec3f::Angle& angle, const Vec3f& rotAxis)
    noexcept
{
    Mat4x4f matrix{};

    const float cos = std::cos(angle);
    const float sin = std::sin(angle);

    const float cosDiff = 1.0f - cos;

    const float xyCosDiff = rotAxis.X() * rotAxis.Y() * cosDiff;
    const float xzCosDiff = rotAxis.X() * rotAxis.Z() * cosDiff;
    const float yzCosDiff = rotAxis.Y() * rotAxis.Z() * cosDiff;

    const float xSin = rotAxis.X() * sin;
    const float ySin = rotAxis.Y() * sin;
    const float zSin = rotAxis.Z() * sin;

    const float xPowCosDiff = rotAxis.X() * rotAxis.X() * cosDiff;
    const float yPowCosDiff = rotAxis.Y() * rotAxis.Y() * cosDiff;
    const float zPowCosDiff = rotAxis.Z() * rotAxis.Z() * cosDiff;

    // We do hard code the values

    matrix[0][0] = cos + xPowCosDiff;
    matrix[0][1] = xyCosDiff - zSin;
    matrix[0][2] = xzCosDiff + ySin;

    matrix[1][0] = xyCosDiff + zSin;
    matrix[1][1] = cos + yPowCosDiff;
    matrix[1][2] = yzCosDiff - xSin;

    matrix[2][0] = xzCosDiff - ySin;
    matrix[2][1] = yzCosDiff + xSin;
    matrix[2][2] = cos + zPowCosDiff;

    matrix[3][3] = 1;

    return matrix;
}
