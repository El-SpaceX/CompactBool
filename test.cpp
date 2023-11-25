#include <iostream>
#include <cassert>
#include <limits>
#include "CompactBool.h"


using namespace std;

int main() {
    CompactBool<7> test1;
    CompactBool<8> test2;
    CompactBool<9> test3;

    assert(sizeof(test1)*8 == 8);  //1 byte
    assert(sizeof(test2)*8 == 8);  //1 byte
    assert(sizeof(test3)*8 == 16); //2 bytes


    CompactBool<32> test4;
    CompactBool<32> test5;
    CompactBool<33> test6;
    assert(sizeof(test4)*8 == 32);  //4 bytes
    assert(sizeof(test5)*8 == 32);  //4 bytes
    assert(sizeof(test6)*8 == 64);  //8 bytes


    CompactBool<29> var(0xFFFF);
    cout << "Valor bruto: " << var.GetValueBrute() << '\n';
    cout << "Bin: " << var.GetBin() << '\n';
    cout << "Bytes: " << sizeof(var) << '\n';
    cout << "-------------------------------------------------\n";
    
    var.Set(29, true);
    var.Set(3, false);
    var.Set(9, false);
    
    cout << "Valor bruto: " << var.GetValueBrute() << '\n';
    cout << "Bin: " << var.GetBin() << '\n';
    cout << "-------------------------------------------------\n";

    assert(var.Get(29) == true);
    assert(var.Get(9) == false);
    assert(var.GetValueBrute() == 0b10000000000001111111011111011);
    
    var.SetValueBrute(std::numeric_limits<uint32_t>::max());
    
    cout << "Valor bruto: " << var.GetValueBrute() << '\n';
    cout << "Bin: " << var.GetBin() << '\n';
    assert(var.GetValueBrute() == 0b11111111111111111111111111111111);
    cout << "-------------------------------------------------\n";


    
    return EXIT_SUCCESS;
}