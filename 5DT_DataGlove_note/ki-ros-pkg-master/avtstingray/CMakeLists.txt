cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()
#rosbuild_include(cuda cuda)
#CUDA_ADD_LIBRARY(kernel src/kernel.cu)
find_package(OpenCV REQUIRED)

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})
rosbuild_add_executable(bridge src/cvbridge/main.cpp )
target_link_libraries(bridge  ${OpenCV_LIBS}  X11 m GL GLU glut)

rosbuild_add_executable(invisiblehand src/cvbridge/invisiblehand.cpp )
target_link_libraries(invisiblehand  ${OpenCV_LIBS}  X11 m GL GLU glut)

rosbuild_add_executable(stretch src/cvbridge/stretch.cpp )
target_link_libraries(stretch  ${OpenCV_LIBS}  X11 m GL GLU glut)

rosbuild_add_executable(stretch_mod src/cvbridge/stretch_mod.cpp )
target_link_libraries(stretch_mod  ${OpenCV_LIBS}  X11 m)

rosbuild_add_executable(stretchGPU src/cvbridge/stretchGPU.cpp )
target_link_libraries(stretchGPU ${OpenCV_LIBS}  X11 m)

rosbuild_add_executable(stretchGL src/cvbridge/stretchGL.cpp )
target_link_libraries(stretchGL  ${OpenCV_LIBS}  X11 m GL GLU glut)

rosbuild_add_executable(filter src/cvbridge/filter.cpp )
target_link_libraries(filter  ${OpenCV_LIBS}  X11 m GL GLU glut)

rosbuild_add_executable(keyboard_node src/cvbridge/keyboard.cpp )
target_link_libraries(keyboard_node)
