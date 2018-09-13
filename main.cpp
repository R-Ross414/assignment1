#include "Assignment1.h" //implements header file
#include <iostream> //library for IO
#include <fstream> //allows file processing
#include <string> //string abilities
//#include <iomanip> //keep?

using namespace std; //standard C++ library

int main(int argc, char* argv[])
{
//input file
/*/////////////////////////////////////////////////////////////////*/
    //input file name supplied through cmd line
    if (argc != 2) {
      cout << "No input file name found" << endl;
      cin.get();
      return 0;
    }

//now we have a file name
//declare object for string
string file_name(argv[1]);
//creating the file input stream
ifstream inputFile("dnasample.txt");
//check if file opened properly
if (!inputFile.is_open())
{
  cout << "Invalid file name" << endl;
  cin.get();
  return 0;
}

/*/////////////////////////////////////////////////////////////////*/
////////////////////////process file data///////////////////////////

//initialize local variables for frequency of nucleotides
int countA = 0;
int countC = 0;
int countT = 0;
int countG = 0;

//initialize for holding sum of length and total count
int sum = 0;
int total_str = 0;

//for hodling dna string we need a local variable
string DNA_str;

///////////////////////read file line by line///////////////////////
while (getline (inputFile, DNA_str))
{
  cout << DNA_str << '\n'; //PRINTS DNA STRINGS

  //while loop for reading lines for sum
  total_str++;
  sum += DNA_str.size();

//count each frequency for each nucleotide base
//this will be later used for calculating probability
  countC += calc_frequency(DNA_str, 'C');
  countG += calc_frequency(DNA_str, 'G');
  countA += calc_frequency(DNA_str, 'A');
  countT += calc_frequency(DNA_str, 'T');

}

//close input file when done dealing with it
inputFile.close();

/*/////////////////////////////////////////////////////////////////*/
//////////////////////////create output file////////////////////////

//opening an object for output file
ofstream outputFile("rross.txt");

//write each value into the file
outputFile << "SUM: " << sum << endl;
/////////outputFile << "MEAN" << setprecision(2) << fixed << calc_mean(sum, total_str) << endl;
//outputFile << "MEAN" << mean << endl;

cin.get();
return 0;

}
