#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;

void usage ();
void credit();
void version();
string language();

enum{
    LISTENING_ON,
    INCORRECT_FLAG,
    TOO_MANY,
    ENV_PORT,
    WRONG_NUMBER
};

string en[] = {
    "Listening on port ",
    "Inocrect flag was used.",
    "Too many arguments",
    "Unrecognized environment port",
    "Port number must be between 0 and 65000"
};

string es[] = {
    "Escuchando en el puerto",
    "Se utilizó la bandera Inocrect.",
    "Demasiados argumentos",
    "Entorno de puerto no reconocido",
    "Número de puerto debe estar entre 0 y 65000"
};

int main(int argc, char *argv[]) {
    //string input;
    //cout << "What port would you like to use " << endl;
    //getline(cin, input);
    //string portsetter;
    string flag;
    string portNumber;
    string environmentPort;
    string lang = language();
    //splitting the input
    //stringstream spaceSplit(input);
    //spaceSplit >> flag >> portNumber;
    string msg;
    if(lang != "en" || lang != "es"){
        cout << "Missing translation files. Using English" << endl;
        msg = en;
    }
    
    else msg = lang;
    
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
            cout << msg[LISTENING_ON] << intNumber << "\n";
            return 0;
        
        }
        }
    }
    
}

//prints out usage
void usage(){
    ifstream usageFile;
    string output;
    usageFile.open("usage_en.txt");
    while(!usageFile.eof()){
        getline(usageFile, output);
        cout << output << "\n";
    }
    usageFile.close();
}

void credit(){
    ifstream creditFile;
    string output;
    creditFile.open("credit_en.txt");
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
                return finalArray[i];
            }
        }
    }
}