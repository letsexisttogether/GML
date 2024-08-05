#pragma once

#include "../Matrix/MatrixDefenitions.hpp"

Mat4x4f GetOrthogonal(const float left, const float right, 
    const float bottom, const float top, const float near, const float far)
    noexcept;

Mat4x4f GetPerspective(const float yFov, const float aspectRatio,
    const float near,const float far) noexcept;

Mat4x4f GetPerspectiveExperimental(const float yFov, const float aspectRatio,
    const float near, const float far) noexcept;
