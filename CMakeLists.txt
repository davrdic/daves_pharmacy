# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name and version
project(PharmacyDemo VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate all source files in the src folder
file(GLOB SOURCES "src/*.cpp")

# Specify the include directory for header files
include_directories(${CMAKE_SOURCE_DIR}/src)

# Find libpqxx and set it as a dependency
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

# Add the executable to build
add_executable(daves_pharmacy ${SOURCES})

# Link the libpqxx library to your executable
target_link_libraries(daves_pharmacy ${LIBPQXX_LIBRARIES} pq)

# If you are using other libraries, add them here
target_include_directories(daves_pharmacy PRIVATE ${LIBPQXX_INCLUDE_DIRS})

# Specify the folder to place compiled binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Install the executable (optional step)
install(TARGETS daves_pharmacy DESTINATION bin)