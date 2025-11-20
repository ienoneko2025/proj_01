cmake_minimum_required(VERSION 4.1.2)
project(AniMilk LANGUAGES C CXX)

# as per Qt 6 documentation
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(INIParser REQUIRED IMPORTED_TARGET iniparser)
pkg_check_modules(LibVLC REQUIRED IMPORTED_TARGET libvlc)
find_package(X11)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets WebChannel WebEngineCore WebEngineWidgets)

qt_add_resources(QT_RCC_SRCS
  animilk.qrc)
qt_wrap_cpp(QT_MOC_SRCS
  first.h)
add_executable(animilk
  ${QT_RCC_SRCS}
  ${QT_MOC_SRCS}
  first.cc
  animilk.cc)
if(X11_FOUND)
  target_compile_definitions(animilk PRIVATE
    -DWITH_X11)
  target_link_libraries(animilk PRIVATE
    X11::X11)
endif()
if(WIN32)
  set_target_properties(animilk PROPERTIES WIN32_EXECUTABLE ON)
endif()
if(APPLE)
  set_target_properties(animilk PROPERTIES MACOSX_BUNDLE ON)
endif()
target_link_libraries(animilk PRIVATE
  PkgConfig::INIParser
  PkgConfig::LibVLC
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::WebChannel
  Qt6::WebEngineCore
  Qt6::WebEngineWidgets)
