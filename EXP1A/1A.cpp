#include <iostream>
#include <math.h>
#include<fstream>
using namespace std;

double ncube(int n){
  return pow(n,3);
}
double threebytwon(int n){
  return pow((3.0/2.0),n);
}

double logn(int n){
  return log(n)/log(2);
} 

double ntwon(int n){
  return n*pow(2,n);
}

double twopowerlogn(int n){
  return pow(2,logn(n));
}

double tworaiseton(int n){
  return pow(2,n);
}

double eRaisedToN(int n){
    return exp(n);
}

double lognsquare(int n){
  return pow(logn(n),2);
}

double inN(int n){
  return log(n);	
}

double nfunction(int n){
  return n;
}

float factorial(int a){
  if(a<=1){
    return 1;
  }
  return a * factorial(a-1);
}

int main() {
  int n,a;
  ofstream myFile;
  myFile.open("data.txt");
  myFile<<"Hello"<<endl;
  myFile.close();


    ofstream myfile("file.csv");

  for(int i=1;i<=100;i++){
    myfile<<i<<","<<
    ncube(i)<<","<<
    threebytwon(i)<<","<<
    logn(i)<<","<<
    ntwon(i)<<","<<
    twopowerlogn(i)<<","<<
    tworaiseton(i)<<","<<
    eRaisedToN(i)<<","<<
    lognsquare(i)<<","<<
    inN(i)<<","<<
    nfunction(i)<<endl;

 }
  myfile.close();

  int i=1;

  while(i<=20){
    float a = factorial(i);
    cout<<i<<"-"<<a<<endl;
    i++;
  }
  return 0;
  }
