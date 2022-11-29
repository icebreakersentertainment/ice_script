cmake_minimum_required(VERSION 3.1.0)

project (ice_script)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Custom options
#option(ICESCRIPT_BUILD_AS_LIBRARY "ICESCRIPT_BUILD_AS_LIBRARY" FALSE)
option(ICESCRIPT_BUILD_TESTS "ICESCRIPT_BUILD_TESTS" FALSE)
option(ICESCRIPT_BUILD_BENCHMARKS "ICESCRIPT_BUILD_BENCHMARKS" FALSE)
option(ICESCRIPT_ENABLE_DEBUG_LOGGING "ICESCRIPT_ENABLE_DEBUG_LOGGING" FALSE)
option(ICESCRIPT_ENABLE_TRACE_LOGGING "ICESCRIPT_ENABLE_TRACE_LOGGING" FALSE)

# Dependencies
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED)
find_package(range-v3 REQUIRED)

if(MSVC)
  # find_package(llvm-core REQUIRED)
  find_package(LLVM REQUIRED)
else()
  find_package(LLVM REQUIRED)
endif()

if(UNIX AND NOT APPLE)
  # find_package(X11 REQUIRED)
  find_package(Threads REQUIRED)
elseif(APPLE)
  find_library(QUARTZCORE_LIBRARY QuartzCore REQUIRED)
  find_library(METAL_LIBRARY Metal REQUIRED)
  find_library(APPKIT_LIBRARY AppKit REQUIRED)
  find_library(APPSERV_LIBRARY ApplicationServices REQUIRED)
  find_library(CARBON_LIBRARY Carbon REQUIRED)
  find_library(COREAUDIO_LIBRARY CoreAudio REQUIRED)
  find_library(FORCEFEEDBACK_LIBRARY ForceFeedback REQUIRED)
  find_library(IOK_LIBRARY IOKit REQUIRED)
  find_library(AUDIOTOOLBOX_LIBRARY AudioToolbox REQUIRED)
  find_library(ICONV_LIBRARY iconv REQUIRED)
endif()

# Set our runtime library locations
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$ORIGIN")
if(APPLE)
  set(CMAKE_INSTALL_RPATH "./")
  set(CMAKE_MACOSX_RPATH ON)
endif()

# Source
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Generate library
#if(ICESCRIPT_BUILD_AS_LIBRARY)
  list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp")
#  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
#  add_library(ice_script SHARED ${SOURCES})
  add_library(ice_script OBJECT ${SOURCES})
#else()
#  add_executable(ice_script ${SOURCES})
#endif()

# Headers
target_include_directories(ice_script PUBLIC include)
#target_include_directories(ice_script PUBLIC ${LLVM_INCLUDE_DIRS})

#separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
#target_compile_definitions(ice_script PUBLIC ${LLVM_DEFINITIONS})

target_compile_options(ice_script PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/EHsc>)
target_compile_options(ice_script PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/MP16>)
target_compile_options(ice_script PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/bigobj>)
target_compile_options(ice_script PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/Od>)
#target_compile_options(ice_script PRIVATE $<$<AND:$<CONFIG:DEBUG>,$<CXX_COMPILER_ID:MSVC>>: /bigobj>)

if(CMAKE_BUILD_TYPE MATCHES Debug OR CMAKE_BUILD_TYPE MATCHES RelWithDebInfo OR ICESCRIPT_ENABLE_DEBUG_LOGGING)
  target_compile_definitions(ice_script PRIVATE -D ICESCRIPT_ENABLE_DEBUG_LOGGING=1)
endif()

if(ICESCRIPT_ENABLE_TRACE_LOGGING)
  target_compile_definitions(ice_script PRIVATE -D ICESCRIPT_ENABLE_TRACE_LOGGING=1)
endif()

target_precompile_headers(ice_script PRIVATE include/pch.hpp)

#llvm_map_components_to_libnames(llvm_libs support core irreader)

target_link_libraries(ice_script PUBLIC Boost::system)
target_link_libraries(ice_script PUBLIC Boost::chrono)
target_link_libraries(ice_script PUBLIC Boost::atomic)
target_link_libraries(ice_script PUBLIC Boost::thread)
target_link_libraries(ice_script PUBLIC Boost::program_options)
target_link_libraries(ice_script PUBLIC Boost::filesystem)
target_link_libraries(ice_script PUBLIC Boost::log)
target_link_libraries(ice_script PUBLIC Boost::log_setup)
target_link_libraries(ice_script PUBLIC Boost::date_time)
target_link_libraries(ice_script PUBLIC Boost::regex)
target_link_libraries(ice_script PUBLIC Boost::serialization)
target_link_libraries(ice_script PUBLIC Boost::wave)
target_link_libraries(ice_script PUBLIC range-v3::range-v3)
target_link_libraries(ice_script PUBLIC llvm-core::interpreter)
target_link_libraries(ice_script PUBLIC llvm-core::orcjit)
target_link_libraries(ice_script PUBLIC llvm-core::x86asmparser)
target_link_libraries(ice_script PUBLIC llvm-core::x86codegen)
target_link_libraries(ice_script PUBLIC llvm-core::core)

target_link_libraries(ice_script PUBLIC llvm-core::support)
target_link_libraries(ice_script PUBLIC llvm-core::core)
target_link_libraries(ice_script PUBLIC llvm-core::irreader)

if(APPLE)
  target_link_libraries(ice_script PUBLIC ${QUARTZCORE_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${METAL_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${APPKIT_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${APPSERV_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${CARBON_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${COREAUDIO_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${FORCEFEEDBACK_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${IOK_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${AUDIOTOOLBOX_LIBRARY})
  target_link_libraries(ice_script PUBLIC ${ICONV_LIBRARY})
endif()

if (ICESCRIPT_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if (ICESCRIPT_BUILD_BENCHMARKS)
  enable_testing()
  add_subdirectory(benchmarks)
endif()

# Disable Position Independent Executable - this is starting to be enabled by default,
# which is causing issues
#target_link_libraries(test PUBLIC $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -no-pie>)

# Set install dir
install(TARGETS ice_script DESTINATION /usr/lib)
