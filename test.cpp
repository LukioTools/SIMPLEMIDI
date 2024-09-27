#include <cstddef>
#include <iostream>
#include <limits>
using fp_2_14 = unsigned short;
constexpr fp_2_14 max = 16384;
constexpr size_t decimalPlaces = 4;
char loadedNumber[7] = {'0','.','0','0','0','0', 0};
const char* toString(fp_2_14 fp){
    loadedNumber[0] = '0'+(fp>>14);
        //trust me bro
    int fract = ((fp&0b0011111111111111) * 10000)/max;
    for(size_t i = 0; i < decimalPlaces; i++){
        loadedNumber[sizeof(loadedNumber)-2 - i] = '0' + fract%10;
        fract/=10;
    }
    loadedNumber[sizeof(loadedNumber)-1] = 0;
    return loadedNumber;
}

int main(int argc, const char* argv[]){

    for(std::size_t i = 0; i < std::numeric_limits<fp_2_14>::max(); i+=700){
        std::cout << "i: " << i << " / " << toString(i) << '\n';
    }
    

    return 0;
}