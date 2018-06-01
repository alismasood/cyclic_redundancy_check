#include <iostream>

#include "cyclic_redundancy_check.cpp"

using std::cout;
using std::endl;


void run_tests();
void run_tests_simple_checksum();
void test_simple_checksum(const char* message, uint16_t length, uint8_t expected_checksum);

int main(int argc, char* argv[]){
    run_tests_simple_checksum();
}
void run_tests(){
    run_tests_simple_checksum();
    cout << "Tests completed." << endl;
}

void run_tests_simple_checksum(){
    cout << "Running tests for simple_checksum." << endl;
    test_simple_checksum("A",2,190);
    test_simple_checksum("B",2,189);        
    test_simple_checksum("AB",3,124);        
    test_simple_checksum("",1,255);        
}

void test_simple_checksum(const char* message, uint16_t length, uint8_t expected_checksum){
    uint8_t returned_checksum = simple_checksum(message, length);
    if(returned_checksum != expected_checksum){
        cout << "simple_checksum failed." << endl;
        cout << "   expected: " << (int)expected_checksum << endl;
        cout << "   returned: " << (int)returned_checksum << endl;
    }
}
