#include"strategy.h"
#include<iostream>
#include<stdlib.h>
#include<limits.h>

double OnePlusOneStrategy::run(int dim, int iterations, Function *f){
	std::cout<<"1+1"<<std::endl;
	int iter=0;
	double* bestVector = generateVector(dim,10);
	double bestScore = f->run(dim,bestVector);
	while (iter<iterations) {
		std::cout<<"loop "<<iter<<std::endl;
		double* v=mutate(dim,bestVector,3);
		double s = f->run(dim,v);
		if (s<bestScore) {
			bestScore = s;
			delete bestVector;
			bestVector = v;	
		}
		else {
			delete v;
		}
		if (1==1){
			for( int i=0;i<dim;++i)
				std::cout<<bestVector[i]<<"  ";
			std::cout<<std::endl<<"bestScore = "<<bestScore<<std::endl;
			for( int i=0;i<dim;++i)
				std::cout<<v[i]<<"  ";
			std::cout<<std::endl<<"score = "<<s<<std::endl;
		}
		++iter;
	}
}
void OnePlusLambdaStrategy::setLambda(int l){
	lambda=l;
}

double OnePlusLambdaStrategy::run(int dim, int iterations, Function *f){
	std::cout<<"1+L"<<std::endl;
	int iter=0;
	double* bestVector = generateVector(dim,10);
	double bestScore = f->run(dim,bestVector);
	while (iter<iterations) {
		std::cout<<"loop "<<iter<<std::endl;
		double** l = new double*[lambda]();		
		double* ls = new double[lambda]();		
		for(int li =0; li<lambda; ++li){
			l[li]=mutate(dim,bestVector,3);
			ls[li]=f->run(dim,l[li]);
		}
		double* v = l[0];
		double s = ls[0];
		for(int li =1; li<lambda; ++li){
			if (ls[li]<s) {
				s = ls[li];
				delete v;
				v = l[li];	
			}
			else {
				delete l[li];
			}
		}
		delete ls;
		if (1==1){
			for( int i=0;i<dim;++i)
				std::cout<<bestVector[i]<<"  ";
			std::cout<<std::endl<<"bestScore = "<<bestScore<<std::endl;
			for( int i=0;i<dim;++i)
				std::cout<<v[i]<<"  ";
			std::cout<<std::endl<<"iterationScore = "<<s<<std::endl;
		}
		if (s<bestScore) {
			bestScore = s;
			delete bestVector;
			bestVector = v;	
		}
		else {
			delete v;
		}
		++iter;
	}
}

double* generateVector(int dim, double variance){
	double* tab = new double[dim]();
	for (int i=0;i<dim;++i)
	{
		tab[i]=((double)rand()/INT_MAX)*(variance*2)-variance;
	}
	return tab;
}

double* add(int dim, double* v1, double* v2){
	double* tab = new double[dim]();
	for (int i=0;i<dim;++i)
	{
		tab[i]=v1[i]+v2[i];
	}
	return tab;
}


double* mutate(int dim, double* v, double variance){
	double* tab = new double[dim]();
	double* tmp = generateVector(dim, variance);
	for (int i=0;i<dim;++i)
	{
		tab[i]=v[i]+tmp[i];
	}
	delete tmp;
	return tab;
}

