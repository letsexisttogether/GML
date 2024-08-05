#include <iostream>

#include "Matrix/MatrixDefenitions.hpp"
#include "Transformation/Transformation.hpp"
#include "Vector/VectorDefinitions.hpp"

std::int32_t main()
{
    std::cout << "Hello, GML" << std::endl;

    Vec3f vec{ 5.0f, 4.0f, 3.0f };

    std::cout << vec.X() << ' ' << vec.Y() << ' ' << vec.Z() << '\n';


    Vec3f normalizedVec{ vec.GetNormalized() };

    std::cout << normalizedVec.X() << ' ' << normalizedVec.Y() 
        << ' ' << normalizedVec.Z() << '\n';

    std::cout << normalizedVec.GetLength() << std::endl;

    return EXIT_SUCCESS;
}
