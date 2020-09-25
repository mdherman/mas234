#include <iostream>
#include <string>

void task1(){
    long int num[10] = {0,1,2,3,4,5,6,7,8,9};

    for (int i = 0; i <= 9; ++i){
        long int* pointer = &num[i];
        *pointer = num[i];
        std::cout << "Num: " << *pointer << ", Adress: " << pointer << std::endl;
    }
}

void task2_1(){
    int a;
    int b;
    int* ptrA = &a;
    int* ptrB = &b;
    std::cout << "Input integer a: ";
    std::cin >> *ptrA;
    std::cout << "Input integer b: ";
    std::cin >> *ptrB;

    std::cout << "\nInteger a = " << *ptrA << ". The address is: " << ptrA << std::endl;
    std::cout << "Integer b = " << *ptrB << ". The address is: " << ptrB << std::endl;




}

void task2_2(){
    int dataSets;
    int max = 0;

    std::cout << "How many data sets?" << std::endl;
    std::cin >> dataSets;
    std::cout << "What data to check?" << std::endl;
    int data[dataSets-1];

    for (int i = 0; i <= dataSets-1; ++i){
        std::cin >> data[i];
    }
    for (int u = 0; u <= dataSets; ++u){
        if (data[u]> max){
            max = data[u];
        }
    }
    int* pointer = &max;
    std::cout << "The highest value is: " << *pointer << std::endl;








}

void task2_3(){
    char h = 0;
    std::cout << "What char would you like to print?" << std::endl;
    std::cin >> h;
    char*  pointer = &h;

    std::cout << "\nThe printed char is: " << *pointer << std::endl;

}

void task2_4(){
    std::string aString = "A string";

    std::string A = "A";
    std::string* pointer = &A;

    std::size_t found = aString.find(*pointer);
    if (found!=std::string::npos){
        std::cout << "The letter A is in position: " << found << std::endl;
    }

    *pointer = "r";
    std::size_t found1 = aString.find(*pointer);
    if (found!=std::string::npos){
        std::cout << "The letter r is in position: " << found1 << std::endl;
    }

    *pointer = "g";
    std::size_t found2 = aString.find(*pointer);
    if (found!=std::string::npos){
        std::cout << "The letter g is in position: " << found2 << std::endl;
    }
}

int main()
{
task2_4();



}
