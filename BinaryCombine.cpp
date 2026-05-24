#include <iostream>
#include <cstdint> 
//Розрядність системи - 16 біт. Всюди буду юзати uint16_t
void decimalToBinary(uint16_t number){
    for (int i = 15; i >= 0; i--){
        std::cout << ((number >> i) & 1);
        if((i % 4) == 0) std::cout <<" ";
    }
}


int main(){
    decimalToBinary(11);
}