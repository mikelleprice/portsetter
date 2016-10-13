#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
//#include <cctype>
using namespace std;

void usage ();
void credit();
void version();
string language();
string validate(string);

enum{
    LISTENING_ON,
    INCORRECT_FLAG,
    TOO_MANY,
    ENV_PORT,
    WRONG_NUMBER
};

string lang = language();

int main(int argc, char *argv[]) {
    //string input;
    //cout << "What port would you like to use " << endl;
    //getline(cin, input);
    //string portsetter;
    string flag;
    string portNumber;
    string environmentPort;
    //splitting the input
    //stringstream spaceSplit(input);
    //spaceSplit >> flag >> portNumber;
    
    vector<string>msg;
    string line;
    ifstream msgfile("messages_" + lang + ".txt");
    if(msgfile.fail()){
        cout<< "Could not recognise "<<lang<<". Now using English\n";
        msgfile.open("messages_en.txt");
    }
    while(!msgfile.eof()){
        getline(msgfile, line);
        //msgfile >> line;
        msg.push_back(line);
    }
    

    
    if(argc == 1) {
        //cout << "error" << "\n";
        //print usage message
        usage();
        return 0;
    }
    
    if(argc == 2){
        flag = argv[1];
        if(flag == "-h" || flag == "--help"){
            usage();
            return 0;
        }
        else if(flag == "-p" || flag == "--port"){
            cout << msg[WRONG_NUMBER] << endl;
            usage();
            return 23;
        }
        
        else if(flag == "-?"){
            usage();
        }
        
        else if(flag == "--!" || flag == "--about"){
            credit();
        }
        
        else if(flag == "-v" || flag == "--version"){
            version();
        }
        else{
            cout << msg[INCORRECT_FLAG] << endl;
            usage();
            return 23;
        }
    }
    
    else if (argc > 4) {
        string extraInput = argv[3];
        if (extraInput.length() != 0){
            cout << msg[TOO_MANY] << "\n\n";
            //print usage screen
            usage();
            return 23;
        }   
    }
            
    if(argc == 4){
        flag = argv[1];
        portNumber = argv[2];
        environmentPort = argv[3];
        char* envPrt = getenv(argv[3]);
        if (envPrt != NULL){
            cout << msg[LISTENING_ON] << envPrt << endl;
            return 0;
        }
        else{
            cout << msg[ENV_PORT] << endl;
            usage();
            return 23;
        }
    }
    
    if(argc == 3){
        flag = argv[1];
        portNumber = argv[2];
        if(flag == ("-h") || flag == ("--help")){
            cout<< msg[INCORRECT_FLAG] << endl;
            usage();
            return 23;
        }
         
        if(portNumber == "-p" || portNumber == "--port"){
            cout << msg[INCORRECT_FLAG] << "\n\n";
            usage ();
            return 23;
        }
        if (portNumber == "-h" || portNumber == "--help"){
            cout << msg[INCORRECT_FLAG] << "\n\n";
            usage();
            return 23;
        }
        if(portNumber == "-e"){
            string envPrt = getenv("PORT");
            cout<< msg[LISTENING_ON] << envPrt << endl;
            return 0;
        }
        if(!isdigit(portNumber[0])){
            cout << msg[INCORRECT_FLAG] << "\n\n";
            //print usage message
            usage();
            return 23;
        }
                
        else {
            int intNumber = stoi(portNumber);
            if(intNumber < 1) {
                cout << msg[TOO_MANY] << "\n\n";
                usage();
                return 23;
        }
        else if(intNumber > 65000) {
            cout << msg[TOO_MANY] << "\n\n";
            usage();
            return 23;
        }
        else{
            for (int i = 0; i<portNumber.length(); ++i){
            //check to make sure all chars are int
                if(!isdigit(portNumber[i])){
                    cout << msg[INCORRECT_FLAG] << "\n\n";
                    usage();
                    return 23;
                }
            }
            if (flag == "-p" || flag == "--port") {
                cout << msg[LISTENING_ON] << intNumber << "\n";
                return 0;
            }
            else{
                cout << msg[INCORRECT_FLAG] << "\n\n";
                usage();
                return 23;
            }
        
        }
        }
    }
}

//prints out usage
void usage(){
    fstream usageFile;
    usageFile.open("usage_" + lang + ".txt");
    if(usageFile.fail()){
        cout<<"Using english\n";
        usageFile.open("usage_en.txt");
    }
    string output;
    while(!usageFile.eof()){
        getline(usageFile, output);
        cout << output << "\n";
    }
    usageFile.close();
}

void credit(){
    ifstream creditFile;
    string output;
    creditFile.open("credit_" + lang + ".txt");
    if(creditFile.fail()){
        cout << "using English\n";
        creditFile.open("credit_en.txt");
    }
    while(!creditFile.eof()){
        getline(creditFile, output);
        cout << output << "\n";
    }
    creditFile.close();
}

void version(){
    ifstream versionFile;
    string output;
    versionFile.open("version_en.txt");
    while(!versionFile.eof()){
        getline(versionFile, output);
        cout << output << "\n";
    }
    versionFile.close();
}
    
string language(){
    string langArray[4];
    string secArray[4];
    string finalArray [4];
    char* tests[4] = {
        "LANGUAGE",
        "LC_ALL",
        "LC_MESSAGES",
        "LANG"
    };
    for(int i =0; i<5; ++i){
        char* langTest = getenv(tests[i]);
        //if(strcmp (langTest, NULL) != 0 || strcmp (langTest, " ") != 0){
        if(langTest != NULL){
            langArray[i] = langTest;
            if(langArray[i].compare("C.UTF-8")!=0){
                secArray[i] = langArray[i];
                if(secArray[i].compare("C")!=0)
                finalArray[i]=secArray[i];
                //return finalArray[i]
                string finalString(finalArray[i]);
                finalString = validate(finalString);
                return finalString;
                }
            }
        }
    }
   

string validate(string testLang){
    string temp;
    if(testLang.size()==2){
        if(islower(testLang[0]) && islower(testLang[1])) return testLang;
    }
    if(testLang.size()==5){
        if(islower(testLang[0]) && islower(testLang[1])){
            if(testLang[2] == '_'){
                if(isupper(testLang[3]) && isupper(testLang[4])) return testLang;
            }
        }
    }

    if(testLang.size()==8){
        if(islower(testLang[0])&&islower(testLang[1])){
            temp=testLang.substr(2,6);
            if(temp.compare(".UTF-8")==0) return testLang.substr(0,2);
        }
    }

    if(testLang.size()==11){
        if(islower(testLang[0])&&islower(testLang[1])){
            if(testLang[2]== '_'){
                if(isupper(testLang[3]) && isupper(testLang[4])){
                    temp = testLang.substr(5,6);
                    if(temp.compare(".UTF-8")==0) return testLang.substr(0,2);
                }
            }
        }
    }
     
     cout<<"Didn't recognise enviornment language. Using English. \n";
     string en;
     en = "en";
     return en;
}
