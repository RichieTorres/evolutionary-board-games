#ifndef BASE_NODE_H_
#define BASE_NODE_H_

#include <list>
#include <vector>

#include "base/ChoicesList.h"

const int kMemoryPositionLimit  = 9;
const int kMemoryIntegerLimit   = 99;
const int kBooleanOperatorLimit = 3;
const int kStatementLimit       = 5;

const int kBooleanStatementCode  = 99;
const int kBooleanOperatorCode   = 98;
const int kNumberStatementCode   = 97;
const int kPositionStatementCode = 96;


class Node {
 public:
    Node(ChoicesList* code_in, int type_in);
    virtual ~Node();

    bool create();
    std::vector<Node*> getChilds();
    int getNumberValue();
    int getType();

 private:
    ChoicesList* code;
    std::vector<Node*> myChilds;
    int numberValue;
    int type;

    bool booleanStatement();
    bool blockStatement();
    bool ifStatement();
    int  nextNumber(int mod);
    bool numberStatement();
    bool numberValueStatement(int limit);
    bool readBoardStatement();
    bool readMemoryStatement();
    bool sequenceStatement();
    bool setMemoryStatement();
};

#endif  // BASE_NODE_H_
