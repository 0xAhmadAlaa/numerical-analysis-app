# Numerical Analysis Application (C++)

A command-line application implementing **classical numerical methods** in C++.  
Includes algorithms for **root finding, interpolation, and numerical integration**, wrapped in a simple text-based menu interface.

This repository serves as an archive of my applied math and programming work.

---

##  Features

### Root Finding
- Bisection Method  
- Newton-Raphson Method  
- Secant Method  
- Fixed Point Iteration  

### Interpolation
- Lagrange Interpolation  
- Newton’s Divided Difference Interpolation  

### Numerical Integration
- Trapezoidal Rule  
- Simpson’s 1/3 Rule  

---

##  Project Structure
```

numerical-analysis-app/
├── README.md
├── CMakeLists.txt
├── main.cpp
├── bisection.cpp
├── newton\_raphson.cpp
├── secant.cpp
├── fixed\_point.cpp
├── newton\_divided\_difference.cpp
├── lagrange.cpp
├── curve.cpp
├── trapezoidal.cpp
├── simpsons.cpp
├── numerical\_analysis.h
├── root\_finding.h
├── interpolation.h
└── integration.h

````

---

##  Build Instructions

This project uses **CMake** for building.

```bash
# Clone the repo
git clone https://github.com/0xAhmadAlaa/numerical-analysis-app.git
cd numerical-analysis-app

# Create a build directory
mkdir build && cd build

# Run CMake and build
cmake ..
make

# Run the app and enjoy your math
./numerical_app
````

---

##  Example Run

```
=======================================
   Numerical Analysis Application
=======================================
             0xAhmadAlaa
=======================================

Main Menu:
1. Root Finding Methods
2. Interpolation Methods
3. Numerical Integration Methods
4. About
0. Exit

Enter your choice (0-4):

```

---

##  Notes

* Each numerical method uses example functions, but you can adapt it for your own equations.
* The program is modular: methods are separated into `.cpp` files with reusable headers.

---

##  Author


**Ahmad Alaa**

```
