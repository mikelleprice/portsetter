#include <iostream>
#include <string>
//#include <sstream>
#include <vector>
using namespace std;

void print(int);
int test();
const int SIZE = 17;
int count = 0;

string testCases[] = {
    "setport",
    "setport -h",
    "setport --help",
    "setport -p 4040",
    "setport --port 4040",
    "setport help",
    "setport -help",
    "setport --h",
    "setport -h --help",
    "setport -hs",
    "setport -p --port 9",
    "setport -p 77 33",
    "setport -p -21",
    "setport -p 0",
    "setport --port",
    "setport 90624",
    "setport -x 45321",
    "setport -P 714",
    };

int main(){
    
    
    int result;
    
    result = system("chmod u+x ~/.bash_aliases");
    
    //system("cat ~/.bash_aliases >my_aliases.txt");
    
    //result = system("grep 'setport' my_aliases.txt")/256;
    
    system("echo alias setport='~/workspace/portsetter/portsetter.cpp.o'>> .bash_aliases");
    system("echo alias test='~/workspace/portsetter/portsetter.cpp.o' >> .bash_aliases");
    
    //result = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o >test.txt")/256;
    test();
}

int test (){
    int testResult;
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -h >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o --help >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -p 4040 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o --port 4040 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o help >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -help >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o --h >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -h --help >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -hs >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -p --port 9 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -p 77 33 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -p -21 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -p 0 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o --port >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -p 90642 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -x 45321 >test.txt") / 256;
    print(testResult);
    testResult = system("/home/ubuntu/workspace/portsetter/portsetter.cpp.o -P 714 >test.txt") / 256;
    print(testResult);
}


void print(int _testResult){
        if(_testResult != 0) cout << testCases[count] << " : Failed test" << endl;
        else cout << testCases[count] << " : Passed test" << endl;
        count += 1;
}