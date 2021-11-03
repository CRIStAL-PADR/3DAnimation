#include <cassert>
#include <iostream>
#include <cstring>
#include "Matrice.hpp"
#include "Vect3D.hpp"

using namespace std;
using namespace linalg;

void readObjFile(vector<Vect3D> &vertexId, vector<Vect3D> &vertexTextureId, vector<Vect3D> &vertexNormalId, vector<int> &V, vector<int> &Vn, vector<int> &Vt);

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
  
    int i = 0;
    Vect3D vect( 3 , 1);
    Vect3D  multiplication { vect * m1 };
    cout << "Le produit de " << vect << " par "  << endl;
    cout << m1 << "donne " << endl;
    cout << multiplication << endl;
    cout << endl;
    vector<Vect3D> vertexId;
    vector<Vect3D> vertexTextureId;
    vector<Vect3D> vertexNormalId;
    vector<int> V, Vt, Vn;

    readObjFile(vertexId,  vertexTextureId, vertexNormalId, V, Vt, Vn);

  
}

    void readObjFile(vector<Vect3D> &vertexId, vector<Vect3D> &vertexTextureId, vector<Vect3D> &vertexNormalId, vector<int> &V, vector<int> &Vn, vector<int> &Vt){
    FILE  *file = fopen("input", "r");
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
            Vect3D vect(3,1);
            fscanf(file, "%lf %lf %lf", &vect(0), &vect(1), &vect(2));
            vertexId.push_back(vect);
        }
        else if(strcmp(id, "vt") == 0){        
            Vect3D vect(2, 0);
            fscanf(file, "%lf %lf", &vect(0), &vect(1));
            vertexTextureId.push_back(vect);
        }

        else if(strcmp(id, "vn") == 0){
            Vect3D vect(3, 0);
            fscanf(file, "%lf %lf %lf", &vect(0), &vect(1), &vect(2));
            vertexNormalId.push_back(vect);
        }
        else if(strcmp(id, "f") == 0){
            int v[3], vn[3], vt[3];
            fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d", &v[0], &vt[0], &vn[0], &v[1], &vt[1], &vn[1], &v[2], &vt[2], &vn[2]);
            //cout << v[0] << "/"<< vt[0] << "/" << vn[0] << "  " << v[1] << "/"<< vt[1] << "/" << vn[1] << "  " << v[2] << "/"<< vt[2] << "/" << vn[2] <<endl;
            V.push_back(v[0]);
            V.push_back(v[1]);
            V.push_back(v[2]);
            Vt.push_back(v[0]);
            Vt.push_back(v[1]);
            Vt.push_back(v[2]);
            Vn.push_back(v[0]);
            Vn.push_back(v[1]);
            Vn.push_back(v[2]);
        }
    }
}