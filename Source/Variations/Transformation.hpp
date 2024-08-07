#pragma once

#include "../Matrix/Definitions.hpp"
#include "../Vector/Definitions.hpp"
#include "../Utility/Naming.hpp"

Mat4x4f GetScale(const Vec3f& scaleVector) noexcept;

Mat4x4f GetTranslation(const Vec3f& translationVector) noexcept;

Mat4x4f GetRotation(const Angle angle, const Vec3f& rotAxis)
    noexcept;
