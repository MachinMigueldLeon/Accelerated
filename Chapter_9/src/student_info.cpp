#include "student_info.h"

Alumno::Alumno(): midterm(0),final(0) {}

std::istream & read_hw(std::istream &in,std::vector<double> &hw)
{
    if(in)  //Importante para no progragar la cadena cuando tienes varios cin
    {
        hw.clear();
        double x;
        while(in >> x)
        {
            hw.push_back(x);
        }
        in.clear();
    }

    return in;
}

std::istream & Alumno::read_alumno(std::istream &is){

    is >> n >> midterm >> final;
    ::read_hw(is,homework);    //Asi especifico que debo leer una funcion sin asociar a ninguna clase
    return is;
}

bool compare(const struct Alumno &x,const class Alumno &y){
    return x.name() < y.name();
}
bool Alumno::made_all_hw(){
    return ((std::find(homework.begin(),homework.end(), 0)) == homework.end());
}
/*std::vector<Alumno> extract_fails(std::vector<Alumno> &s){


    /*for(std::vector<Alumno>::iterator iter = s.begin();
    iter != s.end(); ++iter)
    {
        if(!fgrade(*iter)){
            fail.push_back(*iter);
            iter = s.erase(iter); //La forma de trabajar con erase es diferente
        }
    }*/
    //std::remove_copy_if(s.begin(),s.end(),std::back_inserter(fail),pgrade);
    //s.erase(std::remove_if(s.begin(),s.end(),fgrade),s.end());
    /*std::vector<Alumno>::iterator iter = std::stable_partition(s.begin(), s.end(),pgrade);

    std::vector<Alumno> fail(iter,s.end());

    s.erase(iter,s.end());

    return fail;
}*/
double Alumno::grade() const {
    //eturn 0.2*midterm + final*0.4 + ::median_func(homework) * 0.4;;
    return ::grade(midterm, final, homework);
}