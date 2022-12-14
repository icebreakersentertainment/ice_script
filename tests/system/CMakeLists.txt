cmake_minimum_required(VERSION 3.1.0)

project(ice_script_system_tests)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

if(APPLE)
  find_library(BOOST_TIMER_LIBRARY NAMES
    ${BOOST_FILENAME_PREFIX}boost_timer${BOOST_FILENAME_POSTFIX}.dylib
    PATHS ${BOOST_LIBRARY_DIRS}
    NO_DEFAULT_PATH
  )
  find_library(BOOST_TIMER_LIBRARY NAMES
    ${BOOST_FILENAME_PREFIX}boost_timer${BOOST_FILENAME_POSTFIX}.dylib
    PATHS ${BOOST_LIBRARY_DIRS}
  )
endif()

if(WIN32)
#  configure_file(${freeimage_LIB_DIRS}/../bin/FreeImage.dll ./ COPYONLY)
elseif(UNIX)
#  configure_file(${FREEIMAGE_LIBRARY} ./libfreeimage.so.3 COPYONLY)
#  configure_file(${BOOST_SYSTEM_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_CHRONO_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_ATOMIC_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_PROGRAM_OPTIONS_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_FILESYSTEM_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_THREAD_LIBRARY_FILENAME} ./ COPYONLY)
#  configure_file(${BOOST_LOG_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_LOG_SETUP_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_DATE_TIME_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_REGEX_LIBRARY} ./ COPYONLY)
#  configure_file(${BOOST_UNIT_TEST_FRAMEWORK_LIBRARY} ./ COPYONLY)
#  configure_file(${ASSIMP_LIBRARY} ./ COPYONLY)
#  configure_file(${ENTITYX_LIBRARY} ./ COPYONLY)
endif()

file(COPY ../system/fixtures DESTINATION ./)

if(APPLE)
  configure_file(${BOOST_SERIALIZATION_LIBRARY} ./ COPYONLY)
  configure_file(${BOOST_TIMER_LIBRARY} ./ COPYONLY)
endif()

macro(create_test TEST_NAME EXECUTABLE_NAME SOURCE)
#  add_executable(${EXECUTABLE_NAME} "src/${SOURCE}" "../src/parser/Test.cpp" "../src/parser/rules/NumberRule.cpp")
  add_executable(${EXECUTABLE_NAME} "src/${SOURCE}")

  add_dependencies(${EXECUTABLE_NAME} ice_script)

#  target_link_options(${EXECUTABLE_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/WHOLEARCHIVE:ice_script.lib>)
#  SET_TARGET_PROPERTIES(${EXECUTABLE_NAME} PROPERTIES LINK_FLAGS_DEBUG "/WHOLEARCHIVE:ice_script.lib")
#  target_link_options(${EXECUTABLE_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/OPT:NOREF>)

  if(MSVC)
#    target_link_libraries(${EXECUTABLE_NAME} ../${CMAKE_BUILD_TYPE}/ice_script)
  else()
#    target_compile_definitions(${EXECUTABLE_NAME} PRIVATE -DBOOST_TEST_DYN_LINK)
#    target_link_libraries(${EXECUTABLE_NAME} ice_script)
  endif()

    target_link_libraries(${EXECUTABLE_NAME} PRIVATE ice_script)
    target_include_directories(${EXECUTABLE_NAME} PRIVATE include)

    target_link_libraries(${EXECUTABLE_NAME} PRIVATE Boost::unit_test_framework)

  if(UNIX AND NOT APPLE)
    # target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${X11_LIBRARIES})
    # target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${X11_Xext_LIB})
    # target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${X11_Xxf86vm_LIB})
    target_link_libraries(${EXECUTABLE_NAME} PUBLIC Threads::Threads)
    target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${CMAKE_DL_LIBS})
  endif()

  if(WIN32)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE winmm)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE imm32)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE version)
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE Psapi)
  endif()

  add_test(${TEST_NAME} ${EXECUTABLE_NAME})
endmacro()

create_test(IceScriptEngineTests IceScriptEngineTests IceScriptEngine.cpp)

#create_test(ScriptingEngineTests ScriptingEngineTests scripting/ScriptingEngine.cpp)
#create_test(ParameterTests ParameterTests scripting/Parameter.cpp)
#create_test(CPreProcessorTests CPreProcessorTests CPreProcessor.cpp)
#create_test(AngelscriptCPreProcessorTests AngelscriptCPreProcessorTests scripting/angel_script/AngelscriptCPreProcessor.cpp)
