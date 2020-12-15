#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
    cout << "Dime tu nombre: ";
    string name;
    cin >> name;

    string greetings = " Hola, " + name + "! ";
    
    unsigned int pad = 3;
    unsigned int rows = 3 + pad * 2;
    string::size_type cols = greetings.size() + pad * 2 + 2;


    for(unsigned int r = 0; r != rows; r++){
        
        string::size_type c = 0;
        while(c != cols){
            if(r == (pad + 1) && (c == pad + 1)){
                cout << greetings;
                c += greetings.size();
            }
            else
            {
               if(r == 0 || r == (rows - 1) || c == 0 || c == (cols - 1) ){
                cout << '*';
            }
            else{
                cout << ' ';
                }
            ++c;
            }

        }
        cout << std::endl;
    }

    return 0;
}