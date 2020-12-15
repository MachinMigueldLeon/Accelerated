#include <iostream>
#include <cctype> //Para manipular caracteres individualmente
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<std::string> split(const std::string &s){
    std::vector<std::string> splited;
    typedef std::string::size_type size;
    size i = 0;
    while( i != s.size()){

        while( i != s.size() && isspace(s[i]))
        i++;

        size j = i;
        while(j != s.size() && !isspace(s[j]))
        ++j;

        if(j != i){
            splited.push_back(s.substr(i, j - i));
            i = j;
        }

    }

    return splited;
}
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

bool is_palindrome(const std::string &s){
    return std::equal(s.begin(),s.end(),s.rbegin());
}

std::string::size_type size_ (const std::vector<std::string> &v){
    std::string::size_type length = 0;
    for(std::vector<std::string>::const_iterator iter = v.begin();
        iter != v.end(); ++iter){
            length = std::max(length,iter->size());
        }
    return length;
}

std::vector<std::string> frame(const std::vector<std::string>  &s){
    std::vector<std::string> ret;
    std::string::size_type width = size_(s);
    std::string border(width + 4,'*');

    ret.push_back(border);


    for(std::vector<std::string>::size_type i = 0;
        i != s.size(); ++i){
            ret.push_back("* " + s[i] + std::string(width - s[i].size(),' ') + " *");
    }

    ret.push_back(border);

    return ret; 

}

std::vector<std::string> vcat(const std::vector<std::string>  &top,
    const std::vector<std::string>  &botton)
    {
    std::vector<std::string> ret = top; 

    /*for(std::vector<std::string>::const_iterator iter = botton.begin();
        iter != botton.end(); ++iter){
            ret.push_back(*iter);
        }*/
    //ret.insert(ret.end(),botton.begin(),botton.end());
    std::copy(botton.begin(),botton.end(),std::back_inserter(ret));
    return ret;
    }
std::vector<std::string> hcat(const std::vector<std::string>  &left,
    const std::vector<std::string>  &right)
    {
        std::vector<std::string> ret;

        std::string::size_type width = size_(left) + 1;

        std::vector<std::string>::size_type i = 0, j = 0;


        while(i != left.size() || j != right.size()){
            std::string s;

            if(i != left.size())
            s = left[++i];

            s += std::string(width - left[i].size(),' ');

            if(j !=right.size())
            s += right[++j];

            ret.push_back(s);

        }
        return ret;
    }

bool not_in_url(char c){
static const std::string url_ch = "-._~:/?#[]@!$&'()*+,;=";
return !(std::isalnum(c) || std::find(url_ch.begin(),url_ch.end(), c) != url_ch.end());
}

std::string::const_iterator begin_url(std::string::const_iterator &b, 
                                      std::string::const_iterator &e){
    static const std::string sep = "://";
    typedef std::string::const_iterator iter;
    iter i = b;
    while((i = std::search(i, e, sep.begin(), sep.end())) != e){

        if(i != b && i +sep.size() != e){
            iter beg = i;
            while(beg != b && std::isalpha(beg[-1]))
            --beg;

            if(beg != i && !not_in_url(i[sep.size()]))
            return beg;

        }
        i += sep.size();
    }
    return e;
}



std::string::const_iterator url_end(const std::string::const_iterator &b, 
                                      const std::string::const_iterator &e)
    {
        return std::find_if(b, e, not_in_url);//Busco un caracter que no pueda estar en un URL
}


std::vector<std::string> find_url (const std::string &s){
    typedef std::string::const_iterator iter;
    std::vector<std::string> ret;
    iter b = s.begin(), e = s.end();
    //Piensa que tienes dos funciones que te detectan lo que quieres
    while(b != e){
        b = begin_url(b,e);

        if(b != e){
            iter after = url_end(b,e);

            ret.push_back(std::string(b, after));

            b = after;
        }
    }
    return ret;
}


int main(){
    std::string s;

    while(std::getline(std::cin,s)){
        std::vector <std::string> t = split_2(s);
        
        std::vector <std::string> p = frame(t);

        std::vector <std::string> r = vcat(t,p);

        std::vector <std::string> k = find_url(s);

        for(std::vector <std::string>::iterator iter = r.begin();
        iter != r.end(); ++iter){
            std::cout << *iter << std::endl;
        }
    }
}