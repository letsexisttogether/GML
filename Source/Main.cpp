#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <optional>

#include "Matrix/Definitions.hpp"
#include "Vector/Definitions.hpp"

template <class _Matrix>
void PrintMatrix(const _Matrix& matrix) noexcept;

template <class _FMatrix, class _SMatrix>
bool CompareMatrices(const _FMatrix& firstMatrix,
    const _SMatrix& secondMatrix) noexcept;

std::int32_t main()
{
    std::cout << "Hello, GML" << std::endl;

    GML::Vec2f vec{ 2.0f, 3.0f };

    {
        GML::Vec2f arr[3]
        {
            { 1.0f, 2.0f },
            { 3.0f, 4.0f },
            { 5.0f, 6.0f },
        };

        for (float* i = (float*)arr; i < (float*)arr + 3 * 2; 
            i += 2)
        {
            std::cout << "X: " << *i << " Y: " << *(i + 1) << std::endl;
        }
    }

    std::cout << vec.GetLength() << std::endl;


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
    const _SMatrix& secondMatrix) noexcept
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
