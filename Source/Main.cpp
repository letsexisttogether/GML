#include <iostream>

#include "Matrix/MatrixDefenitions.hpp"
#include "Vector/VectorsDefinitions.hpp"

std::int32_t main()
{
    std::cout << "Hello, GML" << std::endl;

    const Vec3f firstVec{ 2.0f, -3.0f, 1.0f };
    const Vec3f secondVec{ 4.0f, -1.0f, 5.0f };
    
    const Vec3f result{ firstVec.Cross(secondVec) };

    std::cout << result.X() << ' ' << result.Y() << ' ' << result.Z();

    std::cout << sizeof(result) << std::endl;

    return EXIT_SUCCESS;
}
