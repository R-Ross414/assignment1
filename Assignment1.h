#ifndef ASSIGNMENT1_H
#define ASSIGNMENT1_H
#include <string>

using namespace std;

//this function is for returning frequency of the nucleotide base in the DNA string */
int calc_frequency(string DNA_str, char base);
//this function calculates mean
double calc_mean(int sum, int total_str);
//this function calculates variance
double calc_vari(int mean, int num_samples);
//this function calculates standard deviation
double calc_stdDev(double mean, int total);
//this function calculates probability
double calc_prob(int total_occurance, int total_len);

#endif
