视觉SLAM十四讲代码

在MacOS BigSur上可运行

踩坑记录：

- Eigen正常brew install就好，需要把CMakeLists的路径改为/usr/local/include
- Pangolin没整明白，编译问题挺多的，目前可行的方法是把pangolin-0.6放到要编译的文件夹下，CMakeLists加入add_subdirectory(pangolin)可以
- Sophus正在尝试......