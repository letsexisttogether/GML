#include <ios>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

#include "Matrix/MatrixDefenitions.hpp"
#include "Utility/Operations.hpp"
#include "Variations/Projection.hpp"
#include "Variations/Transformation.hpp"
#include "Vector/VectorDefinitions.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"

template <class _Matrix>
void PrintMatrix(const _Matrix& matrix) noexcept;

template <class _FMatrix, class _SMatrix>
bool CompareMatrices(const _FMatrix& firstMatrix,
    const _SMatrix secondMatrix) noexcept;

std::int32_t main()
{
    std::cout << "Hello, GML" << std::endl;

    const Mat4x4f myMatrix{ GetRotation(ConvertToRadians(55.0f),
        Vec3f{ 0.0f, 0.5f, 1.0f }) };

    const glm::mat4 libMatrix{ glm::rotate(glm::mat4{ 1.0f },
        glm::radians(55.0f), glm::vec3{ 0.0f, 0.5f, 1.0f }) };

    PrintMatrix(myMatrix);
    PrintMatrix(libMatrix);

    std::cout << std::boolalpha << CompareMatrices(myMatrix, libMatrix);

    std::cout << std::endl;


    return EXIT_SUCCESS;
}

template <class _Matrix>
void PrintMatrix(const _Matrix& matrix) noexcept
{
    for (std::size_t i = 0; i < 4; ++i)
    {
        for (std::size_t j = 0; j < 4; ++j)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}

template <class _FMatrix, class _SMatrix>
bool CompareMatrices(const _FMatrix& firstMatrix,
    const _SMatrix secondMatrix) noexcept
{
    for (std::size_t i = 0; i < 4; ++i)
    {
        for (std::size_t j = 0; j < 4; ++j)
        {
            if (firstMatrix[i][j] != secondMatrix[i][j])
            {

                std::cout << "They differ at " << i << ' ' << j << '\n'
                    << "The values are: " << firstMatrix[i][j] 
                    << ' ' << secondMatrix[i][j] << std::endl;

                return false;
            }
        }
    }

    return true;
}
