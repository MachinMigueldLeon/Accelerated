#include <iostream>
#include <cstddef>

int next(int n){
    ++n;
    return n;
}

int main(){
    const size_t DIM;
    int (*ptr) (int);   //Hay que ponerlo de estas manera si o si.
    ptr = next;    //No se ponen los parentesis | Tambien lo pueod poner como &next 
    int x = ptr(5);
    x = (*ptr)(x);  //Otra forma de ponerlo
    std::cout << x << std::endl;

}