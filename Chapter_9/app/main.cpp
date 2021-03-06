#include <iostream>
#include <iomanip>      //Incluye los manipuladores de datos
#include <string>
#include <ios>      //Define streamsize, la variable del sistema para representar datos
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "median.h"
#include "grade.h"
#include "student_info.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{

    //Inicializacion de vectores
    Alumno x;
    std::vector<Alumno> alumno_vect;
    string::size_type maxlen = 0;

    //Lectura
    while(x.read_alumno(cin)){
        alumno_vect.push_back(x);
        maxlen = std::max(maxlen, x.name().size());
    }
    //Ordenacion
    std::sort(alumno_vect.begin(),alumno_vect.end(),compare);   //A sort
    //Criba
    //extract_fails(alumno_vect);

    //for(std::vector<Alumno>::size_type i = 0;
    //    i != alumno_vect.size(); ++i)
    for(std::vector<Alumno>::size_type i = 0;
    i != alumno_vect.size(); ++i)
    {
        string space((maxlen + 1 - alumno_vect[i].name().size()), ' ');
           cout << alumno_vect[i].name() << ' ' + space;

        try
        {
            double final_grade = alumno_vect[i].grade();
            cout << std::setprecision(4) << final_grade << std::endl;
            //<< " Aprobado: " << fgrade((Alumno[iter] << endl;
        }catch(std::domain_error e)
        {
         cout << e.what();
        }   
    }
    return 0;
}
    




//No entiendo muy bien la clase istream. Ficheros de entrada?
