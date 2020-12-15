#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype> //Para manipular caracteres individualmente
#include <algorithm>
#include <iterator>

using std::cin;


bool no_space(char c){
    return !std::isspace(c);
}
bool space(char c){
    return std::isspace(c);
}

std::vector<std::string> split_2(const std::string &s){

    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter i = s.begin();

    while(i != s.end()){

        i = std::find_if(i,s.end(),no_space);

        iter j = i;

        j = std::find_if(i,s.end(),space);

        if(i != s.end())
            ret.push_back(std::string(i,j));
        i = j;
    }
    return ret;
}

/*int main(){

    std::string s; 
    std::map<std::string,int> counter;

    while(cin >> s){
        ++counter[s];   //AL igual que en Python, uso los corchetes para acceder a la llave
    }
        
          
    for(std::map<std::string,int>::iterator iter = counter.begin();
    iter != counter.end(); ++iter){
       std::cout << iter->first << "\t" << iter->second << std::endl;
    }

    return 0;
}*/

std::map<std::string,std::vector<int> > xref(std::istream &in, 
        std::vector<std::string> find_word(const std::string &s) = split_2)//Estoy declarando la funcion por defecto
        {
            std::map<std::string,std::vector<int> > ret;
            std::string line;
            int line_number = 0;

            while(getline(in,line)){
                ++line_number;
                std::vector<std::string> words = find_word(line);
                for(std::vector<std::string>::const_iterator iter = words.begin();
                iter != words.end(); ++iter){
                    ret[*iter].push_back(line_number);
                }
            }
            return ret;
        }

int main(){
    std::map<std::string,std::vector<int> > mapa = xref(cin);
    for(std::map<std::string,std::vector<int> >::const_iterator iter = mapa.begin();
    iter != mapa.end();++iter){
        std::cout << iter->first << " occurs on line: ";
        std::vector<int>::const_iterator line_it = iter->second.begin();
        //line_it != iter->second.end(); ++line_it){
        std::cout << *line_it ;
        ++line_it;
        while(line_it != iter->second.end()){
            std::cout << ", " << *line_it;
            ++line_it;
        }
        std::cout << std::endl;
    }
    return 0;
}