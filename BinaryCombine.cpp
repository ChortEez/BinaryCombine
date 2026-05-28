#include <iostream>
#include <cstdint> 
#include <string>
#include <math.h>
#include <iomanip>






// std::cout << ((number >> i) & 1);
//         if((i % 4) == 0) std::cout <<" ";



//Розрядність системи - 16 біт. Всюди буду юзати uint16_t
// Для двійкової системи - стрінг.
std::string decimalToBinary(uint16_t number){
    std::string result;
    for (int i = 15; i >= 0; i--){
        result.push_back('0' + ((number >> i) & 1));
        if((i % 4) == 0) result.push_back(' ');
    }
    return result;
}
uint16_t binaryToDecimal(std::string number){ //1010 3
    uint16_t result;
    int j = 0;    //Віднімаємо 1 для синхронізації i з j.
    for(int i = number.length() - 1; i >= 0; i--){
        if(number[i] == '1') {
            result += pow(2, j);
        }else if(number[i] == ' ') continue;
        
        if(number[i] != '1' && number[i] != '0'){
            std::cout <<"НЕВАЛІДНИЙ ВВІД!"; 
            break;
        }
        j++;
    }
    return result;
    std::cout << '\n';
}
void binaryAdd(std::string num1, std::string num2){ //1010 0101 //ПЕРЕПИШИ ЛОГІКУ ПЕРЕВІРКИ ПЕРЕПОВНЕННЯ
    const uint16_t maximal = 65535;
    uint16_t number1, number2, temp;
    uint16_t result;
    number1 = binaryToDecimal(num1);
    number2 = binaryToDecimal(num2);
    
    if(number1 > (maximal - number2)){
        std::cout <<"Overflow, numbers too large" << '\n';
        return;
    }

    result = number1 + number2;

    std::cout << std::setw(32) << num1 << '\n';
    std::cout << std::setw(32) << num2 << '\n';
    std::cout << std::setfill('-')<< std::setw(33) << '\n'; // Розділювач. З невідомих причин звідкись береться ще один символ, і при значенні зсуву в 32, рівняється на один символ лівіше.
    std::cout << std::setfill(' ') << std::setw(33) << decimalToBinary(number1 + number2);
}


int main(){
    binaryAdd("1111 1111 1111 1111","1111 1111 1111 1111");
}