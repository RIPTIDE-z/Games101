#include<cmath>
#include<eigen3/Eigen/Dense>
#include<iostream>

int main(){
    // Example of vector
    std::cout << "1. Example of vector \n";
    // vector definition
    Eigen::Vector3i v1(1, 2, 3);
    Eigen::Vector3f v2(1.f,2.f,3.f);
    Eigen::Vector3f v3(1.0f,0.0f,0.0f);
    // vector output
    std::cout << "Example of output \n";
    std::cout << "v1 = \n" << v1 << std::endl
              << "v2 = \n" << v2 << std::endl
              << "v3 = \n" << v3 << std::endl;

    std::cout << std::endl;

    // vector add
    std::cout << "Example of add \n";
    std::cout << "v2 + v3 = \n" << v2 + v3 << std::endl;

    std::cout << std::endl;

    // vector scalar multiply
    std::cout << "Example of scalar multiply \n";
    std::cout << "v1 * 3 = \n" << v1 * 3 << std::endl;
    std::cout << "v2 * 2 = \n" << 2.0f * v2 << std::endl;

    std::cout << std::endl;

    // Example of matrix
    std::cout << "2. Example of matrix \n\n";
    // matrix definition
    Eigen::Matrix3f i,j;
    i << 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0;
    j << 2.0, 3.0, 1.0, 4.0, 6.0, 5.0, 9.0, 7.0, 8.0;
    // matrix output
    std::cout << "Example of output \ni = \n";
    std::cout << i << std::endl;
    std::cout << "j =\n" << j << std::endl;
    // matrix add i + j
    std::cout << "\nExample of add \n";
    std::cout << "i + j =\n" << i + j << std::endl;
    // matrix scalar multiply i * 2.0
    std::cout << "\nExample of scalar multiply \n";
    std::cout << "i * 2.0 =\n" << i * 2.0 << std::endl;

    // matrix multiply i * j
    std::cout << "\nExample of multiply \n";
    std::cout << "i * j =\n" << i * j << std::endl;

    // matrix multiply vector i * v
    std::cout << "\nExample of multiply vector\n";
    std::cout << "i * v2 =\n" << i * v2 << std::endl;

    return 0;
}