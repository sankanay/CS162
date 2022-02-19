#include <iostream>
#include <cstring>
#include "cave.h"
using namespace std;

bool check_arguments(int argc){
    
    if(argc != 3){
        cout << "Invalid set of arguments!" << endl;
        return false;
    }
    return true;
}

int get_rows(int argc, char *argv[], bool valid_inputs){
    int rows = 0;
    if(valid_inputs){
        for(int i = 0; i < argc; ++i){
            if (i == 1){
                rows = atoi(argv[i]);
                while (rows < 0 || rows > 20){
                    cout << "Invalid grid size! Enter again: " << endl;
                    cin >> rows;
                }
                return rows;
            }
        }
    }    
    else{
        cout << "Enter grid size: " << endl;
        cin >> rows;
        while (rows < 0 || rows > 20){
            cout << "Invalid grid size! Enter again: " << endl;
            cin >> rows;
        }
        return rows;
    }
    return 0;
}

bool get_debug(int argc, char *argv[], bool valid_inputs){
    bool debug = false;
    if(valid_inputs){
        for(int i = 0; i < argc; ++i){
            if (i == 2){
                string s = argv[2];
                while (s.empty() && s != "true" && s != "false"){
                    cout << "Invalid game type! Enter again: " << endl;
                    cin >> s;
                }
                if(s == "true"){
                    debug = true;
                }
                return debug;
            }
        }
    }    
    else{
        string s = " ";
        cout << "Enter game type: " << endl;
        cin >> s;
        while (s.empty() && !s.compare("true") && !s.compare("false") && s != "True" && s != "False"){
            cout << "Invalid game type! Enter again: " << endl;
            cin >> s;
        }
        if(s == "true"){
            debug = true;
        }
        return debug;
    }
    return debug;
}


int main(int argc, char *argv[]){

    bool valid_inputs = check_arguments(argc); 
    int rows = get_rows(argc, argv, valid_inputs);
    int cols = rows;
    bool debug = get_debug(argc, argv, valid_inputs);
    cout << debug << endl;

    Cave mycave(rows, cols);
    mycave.hunt(debug);

    return 0;
}