#include <iostream>
#include "mpi_fun.h"
using namespace std;

void mpi_fun_test();

int main(int argc, char** argv)
{
 //MPIInit(argc,argv);
 MPIInitFunnel(argc,argv);

#ifdef MPI_HAO
 if(MPIRank()==0) cout<<"Testing mpi_lib_hao mpi version......\n"<<endl;
#else
 if(MPIRank()==0) cout<<"Testing mpi_lib_hao serial version......\n"<<endl;
#endif

 mpi_fun_test();

 MPIBarrier();
 if(MPIRank()==0) cout<<"\n\nIf these is no warning, we have passed all the test!"<<endl;

 MPIFinalize();
 return 0;
}
