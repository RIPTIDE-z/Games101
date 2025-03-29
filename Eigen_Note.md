# Eigen

- Eigen (['eɪdʒən])是一个用于**线性代数**的 C++ 模板库：包含矩阵、向量、数值求解器和相关算法
- 官网[Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

# 调试可视化

- VS
  需要下载[eigen.natvis](https://gitlab.com/libeigen/eigen/-/blob/master/debug/msvc/eigen.natvis)并放置于 `%VS_INSTALL_DIR%\Common7\Packages\Debugger\Visualizers`
- VSC
  在 `launch.json`中配置
  ![img](image/Pasted%20image%2020241219201818.png)

# 矩阵类

## Matrix，Vector

```cpp
Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompileTime>
```

- `Scalar`是**标量类型**，即系数的类型。也就是说，如果你想要一个浮点矩阵，请在此处选择 `float`
- `RowsAtCompileTime`和 `ColsAtCompileTime`是编译时**已知的矩阵的行数和列数**

有很多方便的类型定义：

- `MatrixNt` 表示 Matrix<type, N, N>.

  - 如**MatrixXi** 表示 Matrix<int, Dynamic, Dynamic>
- `MatrixXNt` 表示 Matrix<type, Dynamic, N>.

  - 如**MatrixX3i** 表示 Matrix<int, Dynamic, 3>
- `MatrixNXt` 表示 Matrix<type, N, Dynamic>

  - 如**Matrix4Xd** 表示 Matrix<double, 4, Dynamic>
- `VectorNt` 表示 Matrix<type, N, 1>

  - 如**Vector2f** for Matrix<float, 2, 1>
- `RowVectorNt` 表示 Matrix<type, 1, N>

  - 如**RowVector3d** 表示 Matrix<double, 1, 3>
- `N`可以是2 、 3 、 4或X (意味着 `Dynamic`) 
- t可以是i (表示int )、 f (表示float )、 d (表示double )、 cf (表示 `complex<float>` )或cd (表示 `complex<double>` )

---

## 动态大小(Dynamic)

`RowsAtCompileTime`和 `ColsAtCompileTime`模板参数可以采用特殊值 `Dynamic` ，这表示大小在编译时未知，因此必须作为运行时变量处理。这样的尺寸被称为**动态尺寸**；而在编译时已知的大小称为固定大小_

```cpp
typedef Matrix<double, Dynamic, Dynamic> MatrixXd;

typedef Matrix<int, Dynamic, 1> VectorXi;

// 也可以行固定，列动态
Matrix<float, 3, Dynamic>
```

---

## 构造函数

### 默认构造函数

默认构造函数

- **不执行任何动态内存分配**
- **不初始化矩阵系数**

如

```cpp
Matrix3f a;  
MatrixXf b;  

// a是一个 3×3 矩阵，带有未初始化系数的普通 float[9] 数组
// b是一个动态大小矩阵，其大小当前为 0×0，并且其系数数组尚未分配
```

---

### 带数值的构造函数

- 对于矩阵，**先传递行数**
- 对于向量，只需传递**向量大小**
- 分配给定大小的系数数组，但**不初始化系数本身**

如

```cpp
MatrixXf a(10,15);  
// 相当于float *a = new float[10 * 15];
VectorXf b(30);  

// a是一个 10x15 动态大小矩阵，具有已分配但当前未初始化的系数。
// b是大小为 30 的动态大小向量，具有已分配但当前未初始化的系数
```

---

#### 列表初始化

```cpp
Vector2i a(1, 2); 
// 包含元素 {1, 2} 的列向量

Matrix<int, 5, 1> b {1, 2, 3, 4, 5};  
// 包含元素 {1, 2, 3, 4, 5} 的行向量

Matrix<int, 1, 5> c = {1, 2, 3, 4, 5}; 
// 包含元素 {1, 2, 3, 4, 5} 的列向量
```

- 初始化具有固定大小或运行时大小的矩阵和向量的时候，系数必须**按行分组**传递

```cpp
MatrixXi a {    
  {1, 2},     // 第一行
  {3, 4}      // 第二行
};

Matrix<double, 2, 3> b {
  {2, 3, 4},
  {5, 6, 7},
};
```

- 对于列向量或行向量，允许隐式转置。这意味着可以**从单行初始化列向量**

```cpp
VectorXd a {{1.5, 2.5, 3.5}};           
// 具有 3 个系数的列向量

RowVectorXd b {{1.0, 2.0, 3.0, 4.0}};   
// 具有 4 个系数的行向量
```

---

#### 逗号初始化

```cpp
Matrix3f m;
m << 1, 2, 3,
     4, 5, 6,
     7, 8, 9;
```

---

## 系数访问器

```cpp
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << "这是矩阵 m:\n" << m << std::endl;
  Eigen::VectorXd v(2);
  v(0) = 4;
  v(1) = v(0) - 1;
  std::cout << "这是向量 v:\n" << v << std::endl;
}

// 输出：
这是矩阵 m:
  3  -1
2.5 1.5
这是向量 v:
4
3

// 向量也可以用[ ]访问，但不能用于一般矩阵
v[1]
```

---

## 大小访问与重分配

### 访问

- `rows()`
- `cols()`
- `size()`

```cpp
	Eigen::Matrix<int, 3, 5> a;
	std::cout << a.rows() << std::endl;
	std::cout << a.cols() << std::endl;
	std::cout << a.size() << std::endl;

	Eigen::Vector<int, 5> b;
	std::cout << b.rows() << std::endl;
	std::cout << b.cols() << std::endl;
	std::cout << b.size() << std::endl;

// 输出：
	3
	5
	15
	5
	1
	5
```

---

### 重新分配

```cpp
	Eigen::MatrixXd m(2,5);
	std::cout << m.rows() << "x" << m.cols() << std::endl;
	m.resize(4,3);
	std::cout << m.rows() << "x" << m.cols() << std::endl;

// 输出
2x5
4x3
```

- **无法调整大小固定的矩阵**，如 `Eigen::Matrix4d`
- `resize`会**覆盖原矩阵**的元素
- 要保留原矩阵元素要用 `conservativeResize()`
- `conservativeResize()`将原矩阵**置于左上角保留**

---

### 赋值

`=`将右边矩阵复制到左边，且会**自动调整左侧矩阵的大小**，使其与右侧矩阵的大小相匹配

```cpp
MatrixXf a(2,2);
std::cout << "a is of size " << a.rows() << "x" << a.cols() << std::endl;
MatrixXf b(3,3);
a = b;
std::cout << "a is now of size " << a.rows() << "x" << a.cols() << std::endl;

// 输出：

a is of size 2x2
a is now of size 3x3
```

---

## 可选参数

Matrix的完整模版为：

```cpp
Matrix<typename Scalar,
       int RowsAtCompileTime,
       int ColsAtCompileTime,
       int Options = 0,
       int MaxRowsAtCompileTime = RowsAtCompileTime,
       int MaxColsAtCompileTime = ColsAtCompileTime>
```

- `Options`是一个位域(bit field)。在这里，我们只讨论一点： `RowMajor` 。它**指定该类型的矩阵使用行优先存储顺序**；默认情况下，存储顺序是列优先
- `MaxRowsAtCompileTime` 和 `MaxColsAtCompileTime`为**编译时最大行/列**

---

# 矩阵和向量算术

## 加减

`+` `-`  `+=` `-=` 以及负号 `-`

```cpp
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix2d a;
  a << 1, 2,
       3, 4;
  Eigen::MatrixXd b(2,2);
  b << 2, 3,
       1, 4;
  std::cout << "a + b =\n" << a + b << std::endl;
  std::cout << "a - b =\n" << a - b << std::endl;
  std::cout << "Doing a += b;" << std::endl;
  a += b;
  std::cout << "Now a =\n" << a << std::endl;
  Eigen::Vector3d v(1,2,3);
  Eigen::Vector3d w(1,0,0);
  std::cout << "-v + w - v =\n" << -v + w - v << std::endl;
}

// 输出：

a + b =
3 5
4 8
a - b =
-1 -1
 2  0
Doing a += b;
Now a =
3 5
4 8
-v + w - v =
-1
-4
-6
```

---

## 标量乘除

`*` `/` `*=` `/=`

```cpp
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix2d a;
  a << 1, 2,
       3, 4;
  Eigen::Vector3d v(1,2,3);
  std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;
  std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;
  std::cout << "Doing v *= 2;" << std::endl;
  v *= 2;
  std::cout << "Now v =\n" << v << std::endl;
}

// 输出：

a * 2.5 =
2.5   5
7.5  10
0.1 * v =
0.1
0.2
0.3
Doing v *= 2;
Now v =
2
4
6
```

---

## 转置和共轭

- 求转置矩阵$A^{T}$，`transpose()`
- 求共轭矩阵$\bar{A}$，`conjugate()`
- 求伴随矩阵$A^{*}$，`adjoint()`

```cpp
#include <iostream>
#include <Eigen/Dense>

int main()
{
  Eigen::MatrixXcf a = Eigen::MatrixXcf::Random(2,2);
  std::cout << "Here is the matrix a\n" << a << std::endl;

  std::cout << "Here is the matrix a^T\n" << a.transpose() << std::endl;

  std::cout << "Here is the conjugate of a\n" << a.conjugate() << std::endl;

  std::cout << "Here is the matrix a^*\n" << a.adjoint() << std::endl;
}

// 输出：

Here is the matrix a
 (0.127171,-0.997497) (-0.0402539,0.170019)
 (0.617481,-0.613392)  (0.791925,-0.299417)
Here is the matrix a^T
 (0.127171,-0.997497)  (0.617481,-0.613392)
(-0.0402539,0.170019)  (0.791925,-0.299417)
Here is the conjugate of a
   (0.127171,0.997497) (-0.0402539,-0.170019)
   (0.617481,0.613392)    (0.791925,0.299417)
Here is the matrix a^*
   (0.127171,0.997497)    (0.617481,0.613392)
(-0.0402539,-0.170019)    (0.791925,0.299417)
```

- 关于基本的算术运算符，`transpose()` 和 `adjoint()` 只是返回一个代理对象，并不会实际进行转置操作
- 如果执行 `b = a.transpose()`，那么转置操作会在结果写入 b 的**同时进行计算**
- 如果执行 `a = a.transpose()`，那么 Eigen 会在转置操作计算完成之前就开始将结果写入 a。因此，指令 `a = a.transpose()` 并不会像预期那样将 a 替换为它的转置

要对矩阵本身直接转置，使用 `transposeInPlace()`

```cpp
#include <iostream>
#include <Eigen/Dense>

int main()
{
  Eigen::MatrixXf a(2,3); a << 1, 2, 3, 4, 5, 6;
  std::cout << "Here is the initial matrix a:\n" << a << std::endl;

  a.transposeInPlace();
  std::cout << "and after being transposed:\n" << a << std::endl;
}


Here is the initial matrix a:
1 2 3
4 5 6
and after being transposed:
1 4
2 5
3 6
```

## 矩阵与矩阵/向量乘法

`*` `*=`

```cpp
#include <iostream>
#include <Eigen/Dense>

int main()
{
  Eigen::Matrix2d mat;
  mat <<1, 2,
        3, 4;
  Eigen::Vector2d u(-1,1), v(2,0);
  std::cout << "Here is mat*mat:\n" << mat*mat << std::endl;
  std::cout << "Here is mat*u:\n" << mat*u << std::endl;
  std::cout << "Here is u^T*mat:\n" << u.transpose()*mat << std::endl;
  std::cout << "Here is u^T*v:\n" << u.transpose()*v << std::endl;
  std::cout << "Here is u*v^T:\n" << u*v.transpose() << std::endl;
  std::cout << "Let's multiply mat by itself" << std::endl;
  mat = mat*mat;
  std::cout << "Now mat is :\n" << mat << std::endl;
}


Here is mat*mat:
 7 10
15 22
Here is mat*u:
1
1
Here is u^T*mat:
2 2
Here is u^T*v:
-2
Here is u*v^T:
-2 -0
 2  0
Let's multiply mat by itself
Now mat is :
 7 10
15 22
```

## 点积和叉积

- 点积 `dot()`
- 叉积 `cross()`

```cpp
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Vector3d v(1,2,3);
  Eigen::Vector3d w(0,1,2);
 
  std::cout << "Dot product: " << v.dot(w) << std::endl;
  double dp = v.adjoint()*w; // automatic conversion of the inner product to a scalar
  std::cout << "Dot product via a matrix product: " << dp << std::endl;
  std::cout << "Cross product:\n" << v.cross(w) << std::endl;
}


Dot product: 8
Dot product via a matrix product: 8
Cross product:
 1
-2
 1
```

## 归约操作

- 求和 `sum()`
- 求积 `prod()`
- 求平均值 `mean()`
- 求最大/小值 `max/minCoeff()`

```cpp
#include <iostream>
#include <Eigen/Dense>
 
using namespace std;
int main()
{
  Eigen::Matrix2d mat;
  mat << 1, 2,
         3, 4;
  cout << "Here is mat.sum():       " << mat.sum()       << endl;
  cout << "Here is mat.prod():      " << mat.prod()      << endl;
  cout << "Here is mat.mean():      " << mat.mean()      << endl;
  cout << "Here is mat.minCoeff():  " << mat.minCoeff()  << endl;
  cout << "Here is mat.maxCoeff():  " << mat.maxCoeff()  << endl;
  cout << "Here is mat.trace():     " << mat.trace()     << endl;
}


Here is mat.sum():       10
Here is mat.prod():      24
Here is mat.mean():      2.5
Here is mat.minCoeff():  1
Here is mat.maxCoeff():  4
```
