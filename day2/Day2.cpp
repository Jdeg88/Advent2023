#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

const int MAX = 3;
bool impossible(string);
int getSubString(string);
int getColonSubString(string);
int getSemiColonCount(string);
bool mapAddition(string);
void getLowestCount(map<string,int>&,string);
int lowestCount(string);

int main(){
    ifstream myFile("info.txt");
    string line;
    int game = 1;
    int result = 0;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            cout << "Game " << game << endl;
            //Day two part one
            /*
            if(!impossible(line)){}
            else{
                result += game;
            }
            */
           
            //Day two part two
            result += lowestCount(line);
            game++;
        }
    }
    myFile.close();
    cout << "Final count: " << result;
    return 0;
}


bool impossible(string game){
    int game_attemps = getSemiColonCount(game);
    string game_removeGame = game.substr(getSubString(game));
    string games[game_attemps+1];
    int size= 0;
    
    map<string,int> newMap = {
        {"blue",0},
        {"green",0},
        {"red",0}
    };

    for(int i=0;i < game_attemps; i++){
        games[i] = game_removeGame.substr(0,getColonSubString(game_removeGame));
        game_removeGame = game_removeGame.substr(getColonSubString(game_removeGame)+1);
        size++;
    }
    if(game_removeGame != ""){
        games[size] = game_removeGame;
        game_removeGame = "";
        size++;
    }
    for(int i=0; i < size+1; i++){
        //cout << games[i] << "--";
        // if(!mapAddition(games[i])){
        //     cout << "Not possible" << endl;
        //     return false;
        // }
        getLowestCount(newMap,games[i]);
    }
    cout << endl;

    cout <<" : " << newMap["blue"] <<" : " << newMap["red"] <<" : " << newMap["green"] << endl;

    return true;
}

int getSubString(string line){
    for(int i =0; i < line.length(); i ++){
        if (line[i] == ':'){
            return i+2;
        }
    }
    return 0;
}

int getColonSubString(string line){
    for(int i =0; i < line.length(); i++){
        if(line[i] == ';'){
            return i+1;
        }
    }
    return 0;
}

int getSemiColonCount(string line){
    int count =0;
    for(int i =0; i < line.length();i++){
        if(line[i] == ';')
            count++;
    }
    return count;
}

bool mapAddition(string line){

    map<string,int> newMap = {
        {"blue",0},
        {"green",0},
        {"red",0}
    };
    string words[line.length()];
    string word = "";
    int index = 0;
    for(int i=0;i < line.length(); i++){
        if(line[i] == ' ' || line[i] == ',' || line[i] == ';'){
            if(word != ""){
                words[index] = word;
                word = "";
                index++;
            }

        }
        else{word += line[i];}
    }
    if(word != ""){
        words[index] = word;
        index++;
    }

    for(int i= 0; i < line.length(); i+=2){
        if(words[i] == "" || words[i] == " " || words[i+1] == "" || words[i+1] == " "){}
        else{newMap[words[i+1]] += stoi(words[i]);}
    }

    cout <<"blue: " << newMap["blue"] <<" red: " << newMap["red"] <<" green: " << newMap["green"] << endl;
    if(newMap["blue"] > 14 || newMap["red"] > 12 || newMap["green"] > 13){return false;}
    return true;
}

void getLowestCount(map<string,int>& myMap,string line){
    map<string,int> newMap;
    string words[line.length()];
    string word = "";
    int index = 0;
    for(int i=0;i < line.length(); i++){
        if(line[i] == ' ' || line[i] == ',' || line[i] == ';'){
            if(word != ""){
                words[index] = word;
                word = "";
                index++;
            }

        }
        else{word += line[i];}
    }
    if(word != ""){
        words[index] = word;
        index++;
    }

    for(int i= 0; i < line.length(); i+=2){
        if(words[i] == "" || words[i] == " " || words[i+1] == "" || words[i+1] == " "){}
        else{newMap[words[i+1]] += stoi(words[i]);}
    }
    if(myMap["blue"] < newMap["blue"]){
        myMap["blue"] = newMap["blue"];
    }
    if(myMap["red"] < newMap["red"]){
        myMap["red"] = newMap["red"];
    }
    if(myMap["green"] < newMap["green"]){
        myMap["green"] = newMap["green"];
    }
}

int lowestCount(string game){
    
    int game_attemps = getSemiColonCount(game);
    string game_removeGame = game.substr(getSubString(game));
    string games[game_attemps+1];
    int size= 0;
    
    map<string,int> newMap = {
        {"blue",0},
        {"green",0},
        {"red",0}
    };

    for(int i=0;i < game_attemps; i++){
        games[i] = game_removeGame.substr(0,getColonSubString(game_removeGame));
        game_removeGame = game_removeGame.substr(getColonSubString(game_removeGame)+1);
        size++;
    }
    if(game_removeGame != ""){
        games[size] = game_removeGame;
        game_removeGame = "";
        size++;
    }
    for(int i=0; i < size+1; i++){
        getLowestCount(newMap,games[i]);
    }
    cout << endl;

    cout <<" : " << newMap["blue"] <<" : " << newMap["red"] <<" : " << newMap["green"] << endl;

    return newMap["blue"] * newMap["red"] * newMap["green"];
}