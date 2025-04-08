# Games101_ASS

- This is a record of my personal assignments while taking the [GAMES101 course](https://www.bilibili.com/video/BV1X7411F744/?spm_id_from=333.1387.homepage.video_card.click)
- Platform
  - `Windows`+`vsc`/`VS`(MSVC编译）+ `Cmake `+`Ninja`
- Environment

  1. [Eigen](https://gitlab.com/libeigen/eigen)、`MinGW`或`MSVC`编译的[OpenCV](https://github.com/opencv/opencv) 库（视你编译源代码所使用的编译器而定），个人做法是将库文件路径配置为windows系统环境变量，在顶层`CMakelists.txt`中指定并在子文件夹使用
  ![](image/Snipaste2025-04-08-14-33-22.png)
  ![](image/Snipaste2025-04-08-14-33-39.png)
  ![](image/code1.png)
  ![](image/code2.png)

---

  2. 作业5按给出的CMakelists可能报错 `ld.exe: cannot find -lubsan: No such file or directory`
  - ubsan（Undefined Behavior Sanitizer，未定义行为检测工具）是 GCC/Clang 提供的一种 **运行时检测工具**，用于在程序运行时捕获 **未定义行为**（UB, Undefined Behavior）
  - MinGW-w64里的GCC并不带有ubsan
  - 去掉`-fsanitize=undefined`可正常运行
  ```cmake
  # target_compile_options(RayTracing PUBLIC -Wall -Wextra -pedantic -Wshadow -Wreturn-type)
  # target_compile_options(RayTracing PUBLIC -Wall -Wextra -pedantic -Wshadow -Wreturn-type -fsanitize=undefined)
  # target_compile_features(RayTracing PUBLIC cxx_std_17)
  # target_link_libraries(RayTracing PUBLIC -fsanitize=undefined)
  ```
  3. 作业8需要的`RandR`库不支持windows，必须在linux系统完成
- Notice

  1. Eigen库在调试时的可视化需要`eigen.natvis`文件支持，详细参考[Eigen_Note](Eigen_Note.md)


---

# ASS0

- 实际上头文件只需要包含`<Eigen/Dense>`，`Core`是被包含在`Dense`里的
- `extra.cpp` 演示额外的Eigen操作，包括求逆，求转置，叉积，归一化向量

---

# ASS1

![](image/Snipaste2025-04-08-14-37-55.png)
![](image/Snipaste2025-04-08-14-38-11.png)

---

# ASS2

![](image/Pasted%20image%2020250408111021.png)
![](image/Pasted%20image%2020250408111627.png)