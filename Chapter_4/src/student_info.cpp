#include "student_info.h"

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

std::istream & read_alumno(std::istream &is, struct Alumno &alum){

    is >> alum.name >>alum.midterm >> alum.final;
    read_hw(is,alum.homework);

    return is;
}

bool compare(const struct Alumno &x,const struct Alumno &y){
    return x.name < y.name;
}
bool made_all_hw(const struct Alumno &a){
    return ((find(a.homework.begin(),a.homework.end(), 0)) == a.homework.end());
}
std::vector<Alumno> extract_fails(std::vector<Alumno> &s){


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
    std::vector<Alumno>::iterator iter = std::stable_partition(s.begin(), s.end(),pgrade);

    std::vector<Alumno> fail(iter,s.end());

    s.erase(iter,s.end());

    return fail;
}