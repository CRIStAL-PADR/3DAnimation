#include <cassert>
#include <iostream>

#include "Matrice.hpp"
#include "Vect3D.hpp"

using namespace std;

int main(){
    Matrice m1{3,3};
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;
    
    
    Vect3D vect(3, 1 , 1);
    Vect3D  multiplication { vect * m1 };
    cout << "Le produit de " << endl;
    cout << vect << endl;
    cout << " par " <<endl;
    cout << m1 << endl;
    cout << "donne " << endl;
    cout << multiplication << endl;
}