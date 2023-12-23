#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX = 3;
bool impossible(string);
int getSubString(string);
int getColonSubString(string);
int getSemiColonCount(string);

int main(){
    ifstream myFile("info.txt");
    string line;
    if(myFile.is_open()){
        while(getline(myFile,line)){
            impossible(line);
        }
    }
    return 0;
}


bool impossible(string game){
    int game_attemps = getSemiColonCount(game);
    string game_removeGame = game.substr(getSubString(game));
    string games[game_attemps+1];
    int size= 0;
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
    // for(int i=0; i < size+1; i++){
    //     cout << games[i] << endl;
    // }

    return false;
}

int getSubString(string line){
    for(int i =0; i < line.length(); i ++){
        if (line[i] == ':'){
            return i+2;
        }
    }
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