#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int i = 0, n = 0;
        while(num != 0){
            n = num%10;
            num = num/10;
            result = getDigitPresentation(n, ++i) + result;
        }
        return result;
    }
    
    string getDigitPresentation(int n, int i){
        char symbol1 = 'I';
        char symbol2 = 'V';
        char symbol3 = 'X';
        string result = "";
        switch(i){
            case 1: break;
            case 2:
                symbol1 = 'X';
                symbol2 = 'L';
                symbol3 = 'C';
                break;
            case 3: 
                symbol1 = 'C';
                symbol2 = 'D';
                symbol3 = 'M';
                break;
            case 4: 
                symbol1 = 'M';
                break;                
        }
        if(n<4){
            result= result + string(n, symbol1);
        }else if(n==4){
            result = result + symbol1 + symbol2;
        }else if(n==9){
            result = result + symbol1 + symbol3;
        }else{
            result = result + symbol2 + string(n-5, symbol1);
        }
        return result;
    }
};