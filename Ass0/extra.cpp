/* 
Examples of :
1.Transpose matrix
2.Inverse matrix
3.Cross product
4.Normalized vector
*/
#include<eigen3/Eigen/Dense>
#include<iostream>

int main(){
    Eigen::Matrix3f M1;
    M1 << 4.0f, 7.0f, 2.0f,
          3.0f, 5.0f, 1.0f,
          2.0f, 8.0f, 6.0f;

    std::cout << "M1 :\n" << M1 << std::endl;
    
    std::cout << "\nTranspose of M1 :\n";
    std::cout << M1.transpose() << std::endl;
    
    // Cannot invert matrices of integer type, may lose precision
    std::cout << "\nInverse of M1 :\n";

    // For matrices smaller than 4x4, use computeInverseWithCheck
    // Matrix for storing the inverse matrix
    Eigen::Matrix3f inverse;
    bool invertible;
    M1.computeInverseWithCheck(inverse, invertible);

    std::cout << inverse << std::endl;

    Eigen::Vector3f v1(1.f, 2.f, 3.f);
    std::cout << "\nv1 :\n" << v1 << std::endl;
    
    std::cout << "\nv1.normalized() :\n" << v1.normalized() << std::endl;
    // normalized() dont change original vector and return normalized vector
    // but normalize() change original vector and return void
    std::cout << "\nv1 after v1.normalized():\n" << v1 << std::endl;
    std::cout << "\nv1 after v1.normalize() :\n"; 
    v1.normalize();
    std::cout << v1 << std::endl;
    
    Eigen::Vector3f v2 (0.f, 1.f, 2.f);
    std::cout << "\nv2 :\n" << v2 << std::endl;
    
    std::cout << "\nv1 x v2 :\n" << v1.cross(v2) << std::endl;
    std::cout << "\nv2 x v1 :\n" << v2.cross(v1) << std::endl;
    
    float norm1 = (v1.cross(v2)).norm();
    std::cout << "\nMagnitude of v1 x v2 : " << norm1 << std::endl;
    return 0;
}