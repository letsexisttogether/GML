#include "Transformation.hpp"

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

Mat4x4f GetRotation(const Vec3f::Angle& angle, const Vec3f& rotateAround)
    noexcept
{
    // const float 

    return {};
}
