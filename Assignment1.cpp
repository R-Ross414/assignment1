#include "Assignment1.h"
#include <fstream>
#include <string>

using namespace std;

/*////////////////////////////////////////////////////////////////*/
//////////////////////////////FREQUENCY///////////////////////////////////

//initialize variable base for counting frequency of each base
int base = 0;
int total_base_count;

int calc_frequency(string DNA_str, char target)
{

//  int base = 0;

//use for loop to convert to to to upper
for(int i = 0; i < DNA_str.size(); i++)
  {
    //change casing for file content

    //iterate for count of each base
    if(DNA_str[i] == base)
    {
      ++total_base_count;
    }

  return base;
  }

}

/*////////////////////////////////////////////////////////////////*/
/////////////////////////////////MEAN//////////////////////////////
double calc_mean(int sum, int total_str)
{
  double mean = sum/total_str;
  return mean;
}

//////////////////////////////VARIANCE//////////////////////////////////
/*double calc_vari(int mean, int nuc)
{

} */



///////////////////////////STANDARD DEVIATION///////////////////////




//////////////////////////RELATIVE PROBABILITY/////////////////////
//INDIVIDUAL NUCLEOTIDES

//NUCLEOTIDES BIGRAMS
