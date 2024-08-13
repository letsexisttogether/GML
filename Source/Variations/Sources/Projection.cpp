#include "../Projection.hpp"

#include <cmath>

GMLSpaceStart

Mat4x4f GetOrthogonal(const float left, const float right, 
    const float bottom, const float top, const float near, const float far)
    noexcept
{
    Mat4x4f matrix{};

    const float range = 2.0f;

    const float horizontalRange = right - left;
    const float verticalRange = top - bottom;
    const float depthRange = far - near;

    matrix[0][0] = range / horizontalRange;
    matrix[1][1] = range / verticalRange;
    matrix[2][2] = -range / depthRange;

    matrix[3][0] = -(left + right) / horizontalRange;
    matrix[3][1] = -(bottom + top) / verticalRange;
    matrix[3][2] = -(near + far) / depthRange;

    matrix[3][3] = 1.0f;

    return matrix;
}

Mat4x4f GetPerspective(const float yFov, const float aspectRatio,
    const float near, const float far) noexcept
{
    Mat4x4f matrix{};

    const float tanHalfFov = std::tan(yFov / 2.0f);

    const float range = 2.0f;
    const float depthRange = far - near;

    matrix[0][0] = 1.0f / (aspectRatio * tanHalfFov);
    matrix[1][1] = 1.0f / tanHalfFov;
    matrix[2][2] = -(far + near) / depthRange;
    matrix[2][3] = -1.0f;
    matrix[3][2] = -range * near * far / depthRange;

    return matrix;
}

Mat4x4f GetPerspectiveExperimental(const float yFov, const float aspectRatio,
    const float near, const float far) noexcept
{
    Mat4x4f matrix{};

    const float tanHalfFov = std::tan(yFov / 2.0f);

    const float depthRange = far - near;

    matrix[0][0] = 1.0f / (aspectRatio * tanHalfFov);
    matrix[1][1] = 1.0f / tanHalfFov;
    matrix[2][2] = far / depthRange;
    matrix[2][3] = 1.0f;
    matrix[3][2] = -(near * far) / depthRange;

    return matrix;
}

GMLSpaceEnd
