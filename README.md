Ice Script
--------

[![Build status](https://ci.appveyor.com/api/projects/status/r82l3k6hokfp4iar/branch/master?svg=true)](https://ci.appveyor.com/project/icebreakersentertainment/ice-script/branch/master)
<!-- [![Documentation Status](https://readthedocs.org/projects/ice-script/badge/?version=latest)](http://ice-script.readthedocs.io/en/latest/?badge=latest) -->

**Note**: This project is incredibly young, and isn't in any kind of production ready state.

<!-- Documentation is available at [http://ice-engine.readthedocs.io/en/latest/](http://ice-engine.readthedocs.io/en/latest/). -->

To clone:

    git clone https://github.com/icebreakersentertainment/ice_script.git

Get/build prerequisites:

    mkdir build
    cd build

    conan profile new default --detect
    conan profile update settings.compiler.libcxx=libstdc++11 default

    conan config set general.revisions_enabled=1
    conan remote add bincrafters https://bincrafters.jfrog.io/artifactory/api/conan/public-conan

    conan export ../conan/llvm-core llvm-core/13.0.0@icebreakersentertainment/stable
    
    conan install .. --build=missing

To build on Linux:

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="conan_paths.cmake" ..
    make

To test on Linux:

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="conan_paths.cmake" -DICESCRIPT_BUILD_TESTS=1 -DICESCRIPT_BUILD_AS_LIBRARY=1 ..
    make
    ctest

To build on Windows:

    mkdir build
    cd build

    cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="conan_paths.cmake" ..
    msbuild /p:Configuration=Release ice_script.sln

To test on Windows:

    mkdir build
    cd build

    cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="conan_paths.cmake" -DICESCRIPT_BUILD_TESTS=1 -DICESCRIPT_BUILD_AS_LIBRARY=1 ..
    msbuild /p:Configuration=Release ice_script.sln
    ctest
