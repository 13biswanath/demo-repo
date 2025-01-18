// JsonParse_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//AUTHOR: Jacob Wioskowski
//AUTHOR: Biswanath Chakraborty
//ITCS-2550 H1601 2025WI

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//Editting Class JsonParser
class JsonParser {
private:
    // Array to store JSON keys and JSON values
    string names[100];  
    string values[100]; 
    fstream file;       

public:
    // Function for opening a JSON file
    bool OpenFile(const string& filename) {
        file.open(filename, ios::in);
        return file.is_open();
    }

    // Function to parse the JSON file and fill names or values arrays
    bool ParseJson() {
        if (!file.is_open()) return false;

        string line;
        int nameIndex = 0, valueIndex = 0;

        while (getline(file, line)) {
            size_t colonPos = line.find(':');
            if (colonPos != string::npos) {
                // Extracting name and value here
                string name = line.substr(0, colonPos);
                string value = line.substr(colonPos + 1);

                // Removing extra characters (quotes, commas, whitespace)
                name.erase(remove(name.begin(), name.end(), '\"'), name.end());
                name.erase(remove(name.begin(), name.end(), ','), name.end());
                name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());

                value.erase(remove(value.begin(), value.end(), '\"'), value.end());
                value.erase(remove(value.begin(), value.end(), ','), value.end());
                value.erase(remove_if(value.begin(), value.end(), ::isspace), value.end());

                // Storing in arrays
                names[nameIndex++] = name;
                values[valueIndex++] = value;
            }
        }

        file.close(); // Closing this file after parsing
        return true;
    }
    
    // Accessors for test cases
    string* GetNames() { return names; }
    string* GetValues() { return values; }
};


///////////////// Testing ////////////////////////////////
TEST_CASE("Testing my JSON Parser")
{
    JsonParser jp;

    SUBCASE("Parsing empty JSON object") {
        // Opening JSON file
        CHECK(jp.OpenFile("C:/Users/bangl/source/repos/week-02-programming-assignment-13biswanath-main/TestData/JsonObject1.json") == true); 
        //Parsing JSON and validating empty names and values
        CHECK(jp.ParseJson() == true);                           
        CHECK(jp.GetNames()[0] == "");                           
        CHECK(jp.GetValues()[0] == "");
    }

    SUBCASE("Parsing simple JSON object") {
        // Open JSON file
        CHECK(jp.OpenFile("C:/Users/bangl/source/repos/week-02-programming-assignment-13biswanath-main/TestData/JsonObject2.json") == true); 
        //Parsing JSON
        CHECK(jp.ParseJson() == true);
        //Validating key "Names", value "Bitcoin", key "Symbol", and value "BTC"
        CHECK(jp.GetNames()[0] == "Name");                       
        CHECK(jp.GetValues()[0] == "BitCoin");                   
        CHECK(jp.GetNames()[1] == "Symbol");                     
        CHECK(jp.GetValues()[1] == "BTC");                       
    }
}
