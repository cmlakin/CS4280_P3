#include <iostream>
#include <stdlib.h>
#include <string>
#include "node.h"
#include "statSem.h"


using namespace std;

list symbolTable;
string prevIdentifier;
Token prevTk;

void statSem(node_t* p) {
  if (p == nullptr) {
    return;
  } else {

      // cout << p->label << endl;

      int i, j;
      string entry;
      string temp; // to hold identifier value while checking
      // boolean found; //flag for if identifier found in symbolTable

      for (i = 0; i < p->children.size(); i++){

        entry = p->children[i];

        // switch statement for all entries that come before identifier
        switch(entry){


          // when name
          case "Name":
                        // check for i++ to see identifier value
                        i++;
                        temp = p->children[i];

                        // check if value already in table
                        for (j = 0; j < list.size(); j++){
                          // if yes - ERROR
                          if (temp == symbolTable[j]) {
                            cout << "Error. Identifier previously defined.\n";
                            cout << "Exiting program.\n";
                            exit(-1);
                          }
                          // else check to see if greater then previous Identifier
                          else {
                            // if yes - add to table and update prev identifier
                            if (temp > prevIdentifier){
                              symbolTable.push_back(temp);
                            }
                            // else ERROR
                            else {
                              cout << "Error. Identifiers not introduced in correct order.\n";
                              cout << "Exiting program.\n";
                              exit(-1);
                            }
                          }
                        }


          // If spot can now also define an identifier
          case "Spot":


        // for all other possible entries
          case "Show":
          case "If":
          case "Assign":
          case "Move":
          case "Flip":
          case "/":       // check for i++ to see identifier value
                          i++;
                          temp = p->children[i];
                          // check to see if identifier in symbol table
                          for (j = 0; j < list.size(); j++){
                            // if yes - continue
                            if (temp == symbolTable[j]) {
                              cout << "Error. Identifier previously defined.\n";
                              cout << "Exiting program.\n";
                              exit(-1);
                            }
                            // else ERROR
                            else {
                              cout << "Error. Identifiers not introduced in correct order.\n";
                              cout << "Exiting program.\n";
                              exit(-1);
                            }
                          }

                            // if no - ERROR
                            //else continue - treePrint(&s);

          }

      }
    }

}
