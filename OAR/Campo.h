#pragma once
enum FieldType{CHAR, INTF, DEC};

struct FieldDefinition{
    char name[30];
    FieldType type;
    int size;
    int size_dec;
    bool key;
};
