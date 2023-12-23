#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool isNumber(char);
int wordToNumber(string);
char checkFirstLetter(string);
char getNumber(string);

int main(){
    ifstream myFile("info.txt");
    string word;
    int result = 0;
    if (myFile.is_open()){
        while(!myFile.eof()){
            myFile >> word;
            result += wordToNumber(word);
        }
    }
    myFile.close();
    cout << result;
    return 0;
}


bool isNumber(char c){
    switch(c){
        case '1':
            return true;
            break;
        case '2':
            return true;
            break;
        case '3':
            return true;
            break;
        case '4':
            return true;
            break;
        case '5':
            return true;
            break;
        case '6':
            return true;
            break;
        case '7':
            return true;
            break;
        case '8':
            return true;
            break;
        case '9':
            return true;
            break;
        case '0':
            return true;
            break;
        default:
            return false;

    }
}

int wordToNumber(string word){
    bool firstNumber = false;
    bool secondNumber = false;
    string result ="";

    for(int i =0; i < word.length(); i++){
        string subString  = word.substr(i);

        if(isNumber(word[i]) && !firstNumber){
            firstNumber = true;
            result += word[i];
        }
        else if(isNumber(word[i]) && !secondNumber){
            secondNumber = true;
            result+= word[i];
        }
        else if(isNumber(word[i])){result[1] = word[i];}
        else if(isNumber(checkFirstLetter(subString)) && !firstNumber){
            firstNumber = true;
            result += checkFirstLetter(subString);
        }
        else if(isNumber(checkFirstLetter(subString)) && !secondNumber){
            secondNumber = true;
            result+= checkFirstLetter(subString);
        }
        else if(isNumber(checkFirstLetter(subString))){
            result[1]= checkFirstLetter(subString);
        }
    }

    
    if(!secondNumber){
        result+= result[0];
        return stoi(result);
    }
    return stoi(result);

    
    
}
char checkFirstLetter(string word){
    char firstLetter = word[0];
    int subStringSize = -1;
    
        if(firstLetter == 'e'){subStringSize =5;}
        else if(firstLetter == 'f'){subStringSize = 4;}
        else if(firstLetter == 'o'){subStringSize = 3;}
        else if(firstLetter == 'n'){subStringSize = 4;}
        else if(firstLetter == 's'){
            if (word[1] == 'i'){
                subStringSize = 3;
            }
            else
                subStringSize =5;
        }
        else if(firstLetter == 't'){
            if (word[1] == 'h'){subStringSize =5;}
            else{subStringSize = 3;}
        }
        else if(firstLetter == 'z'){subStringSize = 4;}

    string number;
    if(subStringSize > 0){
        for(int i = 0; i < subStringSize; i++){number+= word[i];}
        char result = getNumber(number);
        if (result != 'a'){return result;}
    }

    return 'a';
}

char getNumber(string number){
    if(number == "one"){
        return '1';
    }
    else if(number == "two"){
        return '2';
    }
    else if(number == "three"){
        return '3';
    }
    else if(number == "four"){
        return '4';
    }
    else if(number == "five"){
        return '5';
    }
    else if(number == "six"){
        return '6';
    }
    else if(number == "seven"){
        return '7';
    }
    else if(number == "eight"){
        return '8';
    }
    else if(number == "nine"){
        return '9';
    }
    else if(number == "zero"){
        return '0';
    }
    else{return 'a';}

}