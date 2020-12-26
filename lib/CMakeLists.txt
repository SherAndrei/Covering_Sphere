set(LIB_NAME geom)

add_library(${LIB_NAME} STATIC R2/circle.cpp
                               R2/point.cpp
                               R2/line.cpp
                               R2/segment.cpp
                               R2/vector.cpp)

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_options(${LIB_NAME} PUBLIC -W  -Wall 
                     -Werror        -pedantic
                     -Wextra        -Wfloat-equal   -pedantic-errors
                     -Wcast-align   -Wpointer-arith -Wformat-security
                     -Wformat       -Wwrite-strings -Wcast-align
                     -Wno-long-long -Wunused        -Wcast-qual
                     -Wmissing-declarations
                     -fstack-protector-all)
