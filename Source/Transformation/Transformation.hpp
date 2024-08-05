#pragma once

#include "../Matrix/MatrixDefenitions.hpp"
#include "../Vector/VectorDefinitions.hpp"

Mat4x4f GetScale(const Vec3f& scaleVector) noexcept;

Mat4x4f GetTranslation(const Vec3f& translationVector) noexcept;

Mat4x4f GetRotation(const Vec3f::Angle& angle, const Vec3f& rotAxis)
    noexcept;
