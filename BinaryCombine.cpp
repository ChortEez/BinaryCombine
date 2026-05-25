#include <iostream>
#include <cstdint> 
#include <string>
#include <math.h>

//Розрядність системи - 16 біт. Всюди буду юзати uint16_t
void decimalToBinary(uint16_t number){
    for (int i = 15; i >= 0; i--){
        std::cout << ((number >> i) & 1);
        if((i % 4) == 0) std::cout <<" ";
    }
    std::cout << '\n';
}
void binaryToDecimal(std::string number){ //1010 3
    uint16_t result;
    int j = -1;    //Віднімаємо 1 для синхронізації i з j.
    for(int i = number.length(); i >= 0; i--){
        if(number[i] == '1') {
            result += pow(2, j);
        }else if(number[i] == ' ') continue;
        j++;
    }
    std::cout << result;
    std::cout << '\n';
}


int main(){
    decimalToBinary(11);
    binaryToDecimal(" 1000 0000 0000 0000");
}