#include "print.h"
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string>
using namespace std;

int int_to_string(string string_in)
{
    int i = 0;
    try {
        i = boost::lexical_cast<int>(string_in);
    } catch (...) {
        return -1; // Returns -1 if exception raised
    }
    return i;
}

bool valid_name(string test_name)
{
    // Check name is valid
    return true;
}

bool valid_text(string text)
{
    if (text.length() < 1){
        return false;
    }
    return true;
}

string get_text()
{
    string textIn = "";
    bool validIn = false;
    while(!validIn){
        getline(cin, textIn);
        if (!valid_text(textIn)){
            print("Invalid input - please try again", "red");
        } else {
            validIn = true;
        }
    }
    return textIn;
}

bool yes_or_no()
{
    print("Enter yes or no (y/n): ", "blue", false);
    string answer = "";
    bool valid_in = false;
    while (!valid_in) {
        cin >> answer;
        if (answer == "y" || answer == "yes" || answer == "Y" || answer == "Yes") {
            valid_in = true;
            return true;
        } else if (answer == "n" || answer == "no" || answer == "N" || answer == "No") {
            valid_in = true;
            return false;
        } else {
            print("Invalid input! Try again: ", "red", false);
        }
    }
}

int int_option(int max_digit)
{
    bool valid_in = false;
    string string_in = "-1";
    int answer = int_to_string(string_in);
    string prompt = "Enter a value between 1 and " + to_string(max_digit) + ": ";
    //print(prompt, "blue", false);
    while (!valid_in) {
        print(prompt, "blue", false);
        cin >> string_in;
        answer = int_to_string(string_in);
        if (answer > 0 & answer <= max_digit) {
            valid_in = true;
        } else {
            cin.clear();
            print("Invalid option. Try again...", "red");
        }
    }
    return answer;
}
