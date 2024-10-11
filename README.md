# Cpp-3d-renderer

## Introduction

**WeakRayCasting** is a new or revisited method of raycasting. Unlike classical raycasting, where rays are rendered for each pixel, WeakRayCasting optimizes runtime by rendering rays for each vertex of the 3D objects. This method can be used in 3D rendering on webpages and can sometimes be faster than classical raycasting. The project is still in development, and contributions are welcome.

## How to Use the Library

1. **Clone the Repository**
    ```sh
    git clone https://github.com/yourusername/Cpp-3d-renderer.git
    cd Cpp-3d-renderer
    ```

2. **Build the Project**
    Ensure you have a C++ compiler installed. Then, run:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Renderer**
    ```sh
    ./renderer
    ```

4. **Integrate with Your Project**
    Include the necessary headers and link against the library in your project. Example:
    ```cpp
    #include "weakeraycasting.h"

    int main() {
         // Your code to initialize and use the renderer
    }
    ```

Feel free to explore the code, suggest improvements, and contribute to the project!

## Contributing

We welcome contributions from the community. Please fork the repository, create a new branch, and submit a pull request with your changes. Make sure to follow the coding standards and include tests for any new features.

## Features

- **Optimized Raycasting**: Renders rays for each vertex instead of each pixel, improving performance.
- **Cross-Platform**: Compatible with multiple operating systems including Windows, macOS, and Linux.
- **Easy Integration**: Simple API for integrating the renderer into your existing projects.
- **Open Source**: Contributions are welcome to enhance the functionality and performance.

## Requirements

- **C++ Compiler**: Ensure you have a modern C++ compiler installed (e.g., GCC, Clang, MSVC).
- **CMake**: Required for building the project.
- **OpenGL**: Used for rendering the 3D objects.

## Getting Started

To get started with WeakRayCasting, follow the steps in the "How to Use the Library" section. Additionally, you can refer to the examples provided in the `examples` directory of the repository to see how to integrate and use the renderer in different scenarios.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.


## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Contact

For any questions or support, feel free to open an issue on GitHub or contact the maintainers directly.
## Dependencies

This project uses the following libraries:

- **OpenGL**: Used for rendering the 3D objects.
- **SDL**: Simple DirectMedia Layer is used for handling window creation and input.

Make sure to have these dependencies installed on your system before building the project.