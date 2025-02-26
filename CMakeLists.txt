cmake_minimum_required(VERSION 3.16)  # Minimum CMake version
project(MemorySprout C)              # Specify that this is a C project

# Set the C standard
set(CMAKE_C_STANDARD 99)             # Use C99 standard
set(CMAKE_C_STANDARD_REQUIRED ON)    # Ensure the standard is required

# Include header files
include_directories(include)

# Add source files
set(SOURCES
        src/main.c
        src/garden.c
        src/plant.c
        src/tile.c
        src/inventory.c
        src/weather.c
        src/ui.c
)

# Create the executable
add_executable(MemorySprout ${SOURCES})