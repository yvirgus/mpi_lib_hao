set(mpi_srcs mpi_fun.cpp)

add_library(mpihao STATIC ${mpi_srcs})

install(TARGETS mpihao  DESTINATION lib)
