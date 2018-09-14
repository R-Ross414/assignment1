#include "Assignment1.h" //implements header file
#include <iostream> //library for IO
#include <fstream> //allows file processing
#include <string> //string abilities

using namespace std; //standard C++ library

//helper function
int get_length(string xyz, int index) {
  int count = 0;
  string s = xyz;


for (int i = 0; i < index; i++)
{
  int pos = s.find(" ");

  s = s.substr(pos, s.size());

    cout << s.find(" ", pos) << endl;
}

cout << s << endl;

  /*while (count - 1  < index)
  {

    if (count - 1 < index)
        {
          i++;
        }
    if (xyz[i] = ' ')
    {
      count++;
    }

  }
  i++;
  //cout << count << endl;

  //string s = "";

int j = i;
  while (xyz[j] != ' ')
  {
    //s += xyz[i];
    j++;

    //cout << xyz[i] << endl;
  }

//cout << j << endl;

  string s = xyz.substr(i, j - i);
  //cout << s << endl; */
  return 0;
}


int main(int argc, char* argv[])
{
//input file
/*/////////////////////////////////////////////////////////////////*/

//now we have a file name
//declare object for string
cout << "Enter the name of the file" << endl;
string file_name;
cin >> file_name;

//creating the file input stream
ifstream inputFile(file_name);
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

//store the DNA string lengths
string lengths = "";

//for hodling dna string we need a local variable
string DNA_str = "";
int DNA_size;
string string_lengths;

///////////////////////read file line by line///////////////////////
while (getline (inputFile, DNA_str))
{


  int count = 0;

  for (int i = 0; i < DNA_str.size(); ++i){
    if (!(DNA_str[i] == 'A' || DNA_str[i] == 'T' || DNA_str[i] == 'C' || DNA_str[i] == 'G'))
      {
          count++;
      }
    else {DNA_str = DNA_str.substr(count, DNA_str.size());
      break; }
  }

  //DNA_str = DNA_str.substr(count , DNA_str.size());

  for (int i = 0; i < DNA_str.size(); ++i)
  {
    //variable for checking character
    //char ch = DNA_str[i];
    //if statement to check validity of text content
    if (!(DNA_str[i] == 'A' || DNA_str[i] == 'T' || DNA_str[i] == 'C' || DNA_str[i] == 'G'))
      {
          DNA_str = DNA_str.substr(0, i);
          break;

      }
  }

//getting sum of all of the lengths of strings
sum += DNA_str.size();

string_lengths += ' ' + to_string(DNA_str.size());


  //cout << DNA_str << endl;
  //cout << DNA_str.size() << endl;


//print out the DNA string
//count each frequency for each nucleotide base
//this will be later used for calculating probability
  countC += calc_frequency(DNA_str, 'C');
  countG += calc_frequency(DNA_str, 'G');
  countA += calc_frequency(DNA_str, 'A');
  countT += calc_frequency(DNA_str, 'T');

}
cout << string_lengths << " " << endl;
for (int i = 0; i < 4; i++)
{
  get_length(string_lengths, i);
}

//cout << string_lengths << " " << endl;

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
