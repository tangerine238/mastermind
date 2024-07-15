#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <map>
using namespace std;

string normalize(const string& str){
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}

int to_number(string n){
    if (n == "red"){
        return 1;
    }
    else if (n == "blue"){
        return 2;
    }
    else if (n == "yellow"){
        return 3;
    }
    else if (n == "green"){
        return 4;
    }
    else if (n == "orange"){
        return 5;
    }
    else if (n == "purple"){
        return 6;
    }
    else if (n == "magenta"){
        return 7;
    }
    else if (n == "silver"){
        return 8;
    }
    else if (n == "black"){
        return 9;
    }
    else{
        return 10;
    }
}

vector<int> guesses(){
    vector<int> code;
    string first;
    string second;
    string third;
    string fourth;
    int one;
    int two;
    int three;
    int four;
    cout << "What do you think the first colour is?";
    cin >> first;
    normalize(first);
    one = to_number(first);
    cout << "What do you think the second colour is?";
    cin >> second;
    normalize(second);
    two = to_number(second);
    cout << "What do you think the third colour is?";
    cin >> third;
    normalize(third);
    three = to_number(third);
    cout << "What do you think the fourth colour is?";
    cin >> fourth;
    normalize(fourth);
    four = to_number(fourth);
    code.push_back(one);
    code.push_back(two);
    code.push_back(three);
    code.push_back(four);
    cout << "done";
    return code;
}

vector<int> check(vector<int> a, vector<int> b){
    vector<int> same;
    int right_place;
    vector<int> place;
    int wrong_place;
    vector<int> total;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (a[i] == b[j]){
                if(i == j){
                    same.push_back(a[i]);
                    right_place++;
                }
                else{
                    place.push_back(a[i]);
                    wrong_place++;
                }
            }
        }
    }
    for (int a = 0; a < same.size(); a ++){
        for (int b = 0; b < place.size(); b++){
            if (same[a] == place[b]){
                wrong_place --;
            }
        }
    }
    total.push_back(right_place);
    total.push_back(wrong_place);
    return total;
}

int main(){
    vector<int> choice;
    vector<int> comp;
    vector<int> result;
    for (int i = 0; i < 4; i++){
        comp.push_back((rand() % 10) + 1);
    }
    cout << "Welcome to mastermind!. The goal of the game is to find the 4 colour combination, that the computer has randomly chosen. There are 10 availible colours to choose from including red, blue, yellow, green, orange, purple, magenta, silver, black and white. You will get 10 chances.\n";
    for (int i = 0; i < 10; i++){
        choice = guesses();
        cout<< "check";
        result = check(comp,choice);
        cout << result[0] << " correct and in the right place. " << result[1] << " correct and in the wrong place.";
        if (result[0] == 4){
            cout << "You win!";
            break;
        }
        else{
            cout << "Guess again.\n";
        }          
    }
}
