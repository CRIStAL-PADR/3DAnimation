#include <cassert>
#include <iostream>
#include <cstring>
#include "Matrice.hpp"
#include "Vect3D.hpp"

using namespace std;
void readObjFile();

int main(){
    Matrice m1;
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;
  
    
    Vect3D vect( 3 , 1);
    Vect3D  multiplication { vect * m1 };
    cout << "Le produit de " << vect << " par "  << endl;
    cout << m1 << "donne " << endl;
    cout << multiplication << endl;
    cout << endl;
    readObjFile();

}

void readObjFile(){
    FILE  *file = fopen("input.obj", "r");
    if (file == NULL){
        cout <<"Impossible de libre le fichier " << endl;
        exit(0);
    }
    while(1){
        char id[50];
        int result = fscanf(file, "%s", id);
        if (result == EOF)
            break;
        if(strcmp(id , "v") == 0){
            cout << "v " << " ->";
            Vect3D vect(3,1);
            fscanf(file, "%lf %lf %lf", &vect(0), &vect(1), &vect(2));
            cout << vect;
        }
        else if(strcmp(id, "vt") == 0){
            cout << "vt " << " ->";           
            Vect3D vect(2, 0);
            fscanf(file, "%lf %lf", &vect(0), &vect(1));
            cout << vect;
        }

        else if(strcmp(id, "vn") == 0){
            cout << "vn " << " ->";
            Vect3D vect(3, 0);
            fscanf(file, "%lf %lf %lf", &vect(0), &vect(1), &vect(2));
            cout << vect;
        }
    }
}