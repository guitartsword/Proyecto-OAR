#pragma once
enum FieldType{CHAR, INTF, DEC};

class Campo{
public:
    Campo();
    char name[30];
    FieldType type;
    int size;
    bool key;
};
/*
struct FieldDefinition{
    char name[30];
    FieldType type;
    int size;
    int size_dec;
    bool key;
};
*/

