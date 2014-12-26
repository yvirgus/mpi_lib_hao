#include <iostream>
#include <complex>
#include "mpi_fun.h"
using namespace std;


#ifdef MPI_HAO

void MPIBcast_int_test()
{
 int i=0;
 if(MPIRank()==0) i=2;
 MPIBcast(i);
 if(i!=2) cout<<"Warning!!!!MPIBcast failed the int test! rank: "<<MPIRank()<<endl; 
}

void MPIBcast_long_test()
{
 long int i=0;
 if(MPIRank()==0) i=2;
 MPIBcast(i);
 if(i!=2) cout<<"Warning!!!!MPIBcast failed the long test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_long_long_test()
{
 long long int i=0;
 if(MPIRank()==0) i=2;
 MPIBcast(i);
 if(i!=2) cout<<"Warning!!!!MPIBcast failed the long long test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_sizet_test()
{
 size_t i=0;
 if(MPIRank()==0) i=2;
 MPIBcast(i);
 if(i!=2) cout<<"Warning!!!!MPIBcast failed the size_t test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_float_test()
{
 float i=0.0;
 if(MPIRank()==0) i=2.1;
 MPIBcast(i);
 if(abs(i-2.1)>1e-5) cout<<"Warning!!!!MPIBcast failed the float test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_double_test()
{
 double i=0.0;
 if(MPIRank()==0) i=2.1;
 MPIBcast(i);
 if(abs(i-2.1)>1e-12) cout<<"Warning!!!!MPIBcast failed the double test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_complex_float_test()
{
 complex<float> i={0,0};
 if(MPIRank()==0) i=complex<float>(2.0,2.2);
 MPIBcast(i);
 if(abs(i-complex<float>(2.0,2.2))>1e-5) cout<<"Warning!!!!MPIBcast failed the complex float test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_complex_double_test()
{
 complex<double> i={0,0};
 if(MPIRank()==0) i=complex<double>(2.0,2.2);
 MPIBcast(i);
 if(abs(i-complex<double>(2.0,2.2))>1e-12) cout<<"Warning!!!!MPIBcast failed the complex double test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_int_pointer_test()
{
 int a[3]={};
 if(MPIRank()==0) {for(int i=0; i<3; i++) a[i]=i;}
 MPIBcast(3,a);

 size_t flag=0;
 for(int i=0; i<3; i++) {if(a[i]!=i) flag++;}
 if(flag!=0) cout<<"Warning!!!!MPIBcast failed the int pointer test! rank: "<<MPIRank()<<endl;
}

void MPIBcast_double_pointer_test()
{
 double a[3]={};
 if(MPIRank()==0) {for(int i=0; i<3; i++) a[i]=i+1.2;}
 MPIBcast(3,a);

 size_t flag=0;
 for(int i=0; i<3; i++) {if(abs(a[i]-i-1.2)>1e-12) flag++;}
 if(flag!=0) cout<<"Warning!!!!MPIBcast failed the double pointer test! rank: "<<MPIRank()<<endl;
}

void MPISum_int_test()
{
 int i=2;
 int sum=MPISum(i);
 if(MPIRank()==0) {if(sum!=i*MPISize()) cout<<"Warning!!!!MPISum failed the int test! rank: "<<0<<endl;}
 else             {if(sum!=0) cout<<"Warning!!!!MPISum failed the int test! rank: "<<MPIRank()<<endl;}
}

void MPISum_long_test()
{
 long i=2;
 long sum=MPISum(i);
 if(MPIRank()==0) {if(sum!=i*MPISize()) cout<<"Warning!!!!MPISum failed the long test! rank: "<<0<<endl;}
 else             {if(sum!=0) cout<<"Warning!!!!MPISum failed the long test! rank: "<<MPIRank()<<endl;}
}

void MPISum_long_long_test()
{
 long long i=2;
 long long sum=MPISum(i);
 if(MPIRank()==0) {if(sum!=i*MPISize()) cout<<"Warning!!!!MPISum failed the long long test! rank: "<<0<<endl;}
 else             {if(sum!=0) cout<<"Warning!!!!MPISum failed the long long test! rank: "<<MPIRank()<<endl;}
}

void MPISum_float_test()
{
 float i=2;
 float sum=MPISum(i);
 if(MPIRank()==0) {if(abs(sum-i*MPISize())>1e-5) cout<<"Warning!!!!MPISum failed the float test! rank: "<<0<<endl;}
 else             {if(abs(sum)>1e-5) cout<<"Warning!!!!MPISum failed the float test! rank: "<<MPIRank()<<endl;}
}


void MPISum_double_test()
{
 double i=2;
 double sum=MPISum(i);
 if(MPIRank()==0) {if(abs(sum-i*MPISize())>1e-12) cout<<"Warning!!!!MPISum failed the double test! rank: "<<0<<endl;}
 else             {if(abs(sum)>1e-12) cout<<"Warning!!!!MPISum failed the double test! rank: "<<MPIRank()<<endl;}
}

void MPISum_complex_float_test()
{
 complex<float> i={2,3};
 complex<float> sum=MPISum(i);
 if(MPIRank()==0) 
   {if(abs(sum-i*static_cast<float>(MPISize()))>1e-5) cout<<"Warning!!!!MPISum failed the complex float test! rank: "<<0<<endl;}
 else             
   {if(abs(sum)>1e-5) cout<<"Warning!!!!MPISum failed the complex float test! rank: "<<MPIRank()<<endl;}
}

void MPISum_complex_double_test()
{
 complex<double> i={2,3};
 complex<double> sum=MPISum(i);
 if(MPIRank()==0)
   {if(abs(sum-i*static_cast<double>(MPISize()))>1e-12) cout<<"Warning!!!!MPISum failed the complex double test! rank: "<<0<<endl;}
 else
   {if(abs(sum)>1e-12) cout<<"Warning!!!!MPISum failed the complex double test! rank: "<<MPIRank()<<endl;}
}

void MPIGather_double_test()
{
 double i=MPIRank();
 double* v=nullptr;
 if(MPIRank()==0) v=new double[MPISize()];

 MPIGather(i,v);
 if(MPIRank()==0) 
 {
  for(int index=0; index<MPISize(); index++) 
  {
   if(abs(v[index]-index)>1e-12) cout<<"Warning!!!!MPIGather failed the double test! index: "<<index<<endl;
  }
 }

 if(MPIRank()==0) delete[] v;
}

void MPIGather_complex_double_test()
{
 complex<double>  i={MPIRank()*1.0,MPIRank()*2.0};
 complex<double>* v=nullptr;
 if(MPIRank()==0) v=new complex<double>[MPISize()];
 
 MPIGather(i,v);
 if(MPIRank()==0)
 {
  for(int index=0; index<MPISize(); index++)
  {
   if(abs(v[index]-complex<double>(index*1.0,index*2.0))>1e-12) 
     cout<<"Warning!!!!MPIGather failed the complex double test! index: "<<index<<endl;
  }
 }
  
 if(MPIRank()==0) delete[] v;
}

void mpi_fun_test()
{
 MPIBcast_int_test();
 MPIBcast_long_test();
 MPIBcast_long_long_test();
 MPIBcast_sizet_test();
 MPIBcast_float_test();
 MPIBcast_double_test();
 MPIBcast_complex_float_test();
 MPIBcast_complex_double_test();

 MPIBcast_int_pointer_test();
 MPIBcast_double_pointer_test();

 MPISum_int_test();
 MPISum_long_test();
 MPISum_long_long_test();
 MPISum_float_test();
 MPISum_double_test();
 MPISum_complex_float_test();
 MPISum_complex_double_test();

 MPIGather_double_test();
 MPIGather_complex_double_test();
}

#else
void mpi_fun_test()
{
 if(MPISize()!=1) cout<<"Warning!!!!MPISize failed the serial test!"<<endl;
 if(MPIRank()!=0) cout<<"Warning!!!!MPIRank failed the serail test!"<<endl;
}
#endif 
