#include <iostream>

#include "Matrix/MatrixDefenitions.hpp"
#include "Variations/Transformation.hpp"
#include "Vector/VectorDefinitions.hpp"

std::int32_t main()
{
    std::cout << "Hello, GML" << std::endl;

    Vec3f vec{ 1.0f, 0.8f, 0.0f };

    std::cout << vec.X() << ' ' << vec.Y() << ' ' << vec.Z() << '\n';

    return EXIT_SUCCESS;
}
