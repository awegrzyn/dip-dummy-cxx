cmake_minimum_required(VERSION 3.10)
project(DipClientCxx LANGUAGES CXX)

find_package(dip CONFIG REQUIRED)

add_executable(main main.cxx)
set_target_properties(main PROPERTIES OUTPUT_NAME "dip-dummy-client")
target_link_libraries(main dip::dip)
