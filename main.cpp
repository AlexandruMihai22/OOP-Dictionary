#include "Dictionary.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main()
{
    Dictionary<int, string> dictionar1;
    dictionar1.Add(1, "POO");
    dictionar1.Add(2, "is");
    dictionar1.Add(3, "not");
    dictionar1.Add(4, "fun");
    dictionar1.Delete(3);
    assert(dictionar1.Search(2));
    assert(dictionar1[2]=="is");
    assert(dictionar1[3]!="not");
    cout<<dictionar1<<endl;

    Dictionary<int, string>Dictionar2(dictionar1);
    Dictionar2.Add(4, "funx");
    cout<<Dictionar2<<endl;

    Dictionary<string, string> dictionar3;
    dictionar3.Add("1111", "String");
    dictionar3.Add("11122", "Test");
    assert(dictionar3["1111"]=="Test");
    dictionar3.Add("12246", "GDFhh");
    assert(dictionar3["1111"]!="GDFhh");
    cout<<dictionar3<<endl;

    return 0;
}
