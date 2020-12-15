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
#include <numeric>

/**
 * @brief Utilizando esta funcion auxiliar,
 * el compilador sabrá a que función llamar
 * cuando use la función transform
 * 
 * @param EStructura alumno
 * @return double 
 */
double grade_aux(const struct Alumno &s){
    try{
        return grade(s); 
    } catch(std::domain_error){
        return grade(s.midterm, s.final, 0);
    }
}
double average(const std::vector<double> &v){
    return (std::accumulate(v.begin(), v.end(), 0.0)/v.size());
}
double average_grade(const struct Alumno &s){
    return grade(s.midterm, s.final,average(s.homework));
}
double average_analysis(const std::vector<Alumno> &students){
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), average_grade);
    return median_func(grades);
}

double median_analysis(const std::vector<Alumno> &students){
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), grade_aux);
    return median_func(grades);
}
double optimistic_median(const Alumno &students){
    std::vector<double> nonzero;
    std::remove_copy(students.homework.begin(), students.homework.end(), std::back_inserter(nonzero),0);

    if(nonzero.empty())
        return grade(students.midterm,students.final,0);
    else
        return grade(students.midterm, students.final,median_func(nonzero));    

}
double optimistic_median_analysis(const std::vector<Alumno> &students){
    std::vector<double> grades;
    std::transform(students.begin(), students.end(), std::back_inserter(grades), optimistic_median);
    return median_func(grades);
}


void write_analysis(std::ostream &out, const std::string &name, double analysis(const std::vector<Alumno> &students),
                    const std::vector<Alumno> &did, const std::vector<Alumno> &didnt){
    out << name << ": median (did) = " << analysis(did) <<
                   ": median (didnt) = " << analysis(didnt) << std::endl;
}

int main()
{

    //Inicializacion de vectores
    std::vector<Alumno> did, didnt;
    Alumno student;
    std::string::size_type maxlen = 0;

    //Lectura
    while(read_alumno(std::cin,student)){
        if(made_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);

    }
    if(did.empty()){
    std::cout << "Ningun alumno ha hecho su tarea" << std::endl;
    return 1;
    }

    if(didnt.empty()){
    std::cout << "Todos los alumnos has hecho su tarea" << std::endl;
    return 1;
    }

    write_analysis(std::cout, "median", median_analysis, did, didnt);

    write_analysis(std::cout, "median", average_analysis, did, didnt);

    write_analysis(std::cout, "median of homework turned in", optimistic_median_analysis, did, didnt);
    
    return 0;
}
    



