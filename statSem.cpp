#include <iostream>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <list>
#include "node.h"
#include "statSem.h"


using namespace std;

list<string> symTab;  // symbol table
string prevIdent;
string currentIdent;

void statSem(node_t* p) {
  if (p == nullptr) {
    return;
  }
  else {
    // cout << p->label << endl;

    string entry;
    //cout << "label " << p->label << endl;
    for (list<node_t>::iterator iter = std::begin(p->children); iter!=std::end(p->children); ++iter){

      cout << "iter " << (*iter).token.chars << endl;

      entry = (*iter).token.chars;

      if (entry == "Name") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        insertIdent(currentIdent);
      }
      else if (entry == "Spot") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        if ((*iter).token.ID == 1002) {
          insertIdent(currentIdent);
        }
        else {
          verifyIdent(currentIdent);
        }
      }
      else if (entry == "Show") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        if ((*iter).token.ID == 1002) {

          verifyIdent(currentIdent);
        }
        else {
          ;
        }
      }
      else if (entry == "If") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        verifyIdent(currentIdent);
      }
      else if (entry == "Assign") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        verifyIdent(currentIdent);
      }
      else if (entry == "Move") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        verifyIdent(currentIdent);
      }
      else if (entry == "Flip") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        verifyIdent(currentIdent);
      }
      else if (entry == "/") {
        ++iter;
        currentIdent = (*iter).token.chars;
        cout << "current ident = " << currentIdent << endl;
        verifyIdent(currentIdent);
      }
      else {
        statSem(&(*iter));
      }

      // statSem(&(*iter));
    }
  }
}


void insertIdent(string ident) {

  if (symTab.size() == 0) {
    cout << "in if symTab size = " << symTab.size() << endl;
    symTab.push_back(ident);
    prevIdent = ident;
  }
  else {
    //int flag = 0;
    cout << "in else symTab size = " << symTab.size() << endl;
    print();
    //while (flag == 0) {
      for (list<string>::iterator iter = std::begin(symTab); iter!=std::end(symTab); ++iter){
        cout << "in for sT iter " << (*iter) << endl;

        if (ident == (*iter)){
          cout << "in if:\n";
          print();
          cout << "ident = " << ident << " iter = " << *iter << endl;
          cout << "Error. Identifier already defined. Exiting Program.\n";
          exit(-1);
        }
        else {
          cout << "ident = " << ident << " iter = " << *iter << endl;
          //flag = 1;
        }
      }
      cout << "in if:\n";
      print();

      symTab.push_back(ident);
      prevIdent = ident;
    //}
  }
}

void verifyIdent(string ident) {
  int flag = 0;

  //while (flag == 0) {
    for (list<string>::iterator iter = std::begin(symTab); iter!=std::end(symTab); ++iter){
      cout << "in verify for ident = " << ident << " iter = " << *iter << endl;
      if (ident == (*iter)){
        flag = 1;
        break;
      }
      else {
        // cout << "in verify ident = " << ident << endl;
        // cout << "Error. Identifer not defined prior to usage. Exiting Program\n";
        // exit(-1);
      }
    }
  cout << "flag  = " << flag << endl;
  if (flag == 0) {
    cout << "in verify ident = " << ident << endl;
    cout << "Error. Identifer not defined prior to usage. Exiting Program\n";
    exit(-1);
  }
}

void print() {
  cout << "\nSymbol Table:\n";
  for (list<string>::iterator iter = std::begin(symTab); iter!=std::end(symTab); ++iter){
    cout << (*iter) << endl;
  }
  cout << endl;
}
