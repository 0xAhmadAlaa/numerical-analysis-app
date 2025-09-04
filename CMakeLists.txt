cmake_minimum_required(VERSION 3.10)
project(NumericalAnalysisApp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    main.cpp
    bisection.cpp
    newton_raphson.cpp
    secant.cpp
    fixed_point.cpp
    lagrange.cpp
    newton_divided_difference.cpp
    trapezoidal.cpp
    simpsons.cpp
)

# Create executable
add_executable(numerical_analysis ${SOURCES})
