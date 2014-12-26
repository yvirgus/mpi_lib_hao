#ifndef MPI_FUN_HAO
#define MPI_FUN_HAO

#ifdef MPI_HAO
#include <mpi.h>
#include <complex>

void MPIInit(int& argc,char** & argv);
void MPIInitFunnel(int& argc,char** & argv);
int MPISize(const MPI_Comm& comm=MPI_COMM_WORLD);
int MPIRank(const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBarrier(const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIFinalize();

void MPIBcast(int                   & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(long                  & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(long long             & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(size_t                & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(float                 & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(double                & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(std::complex<float>   & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(std::complex<double>  & buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);


void MPIBcast(int N,             int* buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIBcast(int N,          double* buffer, int root=0,  const MPI_Comm& comm=MPI_COMM_WORLD);

int                  MPISum(int                  & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
long                 MPISum(long                 & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
long long            MPISum(long long            & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
float                MPISum(float                & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
double               MPISum(double               & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
std::complex<float>  MPISum(std::complex<float>  & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
std::complex<double> MPISum(std::complex<double> & sendbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);

void MPIGather(double& sendbuf, double* recvbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
void MPIGather(std::complex<double>& sendbuf, std::complex<double>* recvbuf, int root=0, const MPI_Comm& comm=MPI_COMM_WORLD);
#else
void MPIInit(int& argc,char** & argv);
void MPIInitFunnel(int& argc,char** & argv);
int MPISize();
int MPIRank();
void MPIBarrier();
void MPIFinalize();
#endif  //For MPI and Serial 


#endif
