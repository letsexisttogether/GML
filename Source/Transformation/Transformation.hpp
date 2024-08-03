#pragma once

#include "../Matrix/MatrixDefenitions.hpp"
#include "../Vector/VectorsDefinitions.hpp"

Mat4x4f GetScale(const Vec3f& scaleVector) noexcept
{
    Mat4x4f matrix{ Mat4x4f::GetIdentity() };

    matrix[0][0] = scaleVector.X();
    matrix[1][1] = scaleVector.Y();
    matrix[2][2] = scaleVector.Z();

    return matrix;
}

Mat4x4f GetTranslation(const Vec3f& scaleVector) noexcept;
