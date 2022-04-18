/***************************************************************
 * Corrina Lakin
 * CS4280 P1
 * Description:
    Lexical Analyzer
 *************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <type_traits>
#include "parser.h"
#include "statSem.h"

using namespace std;

int main(int argc, char * argv[]) {
  //cout << "*** in main\n";
  char* filenameIn;
  ifstream inFile;

  // parse commandline arguements
  if (argc == 2) {
    filenameIn = argv[1];

    inFile.open(filenameIn);
    parser(inFile);
    inFile.close();
  }
  else if (argc > 2){
    cout << "ERROR: Too many arguements entered.\n";
    cout << "USAGE: ./scanner [filename]\n";
  }
  else {
    cout << "Enter string to check for tokens.\n";
    cout << "Enter 'Done' when finished to exit program.\n";
    parser(cin);
  }

  statSem(getRoot());
  printSymTab();

  return 0;
}
