set(mpi_test_srcs mpi_fun_test.cpp test_all.cpp)

add_executable(mpitest ${mpi_test_srcs})

target_link_libraries(mpitest mpihao)

install(TARGETS mpitest  DESTINATION test)
