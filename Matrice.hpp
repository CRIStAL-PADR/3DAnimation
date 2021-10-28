#ifndef _Matrice_
#define _Matrice_


#include <iostream>
#include <vector>
#include "Vect3D.hpp"
#include <algorithm>

class Matrice
{
    public:
        Matrice(std::size_t ligne, std::size_t colonne, double valeur = 0);
        double & operator()(std::size_t i, std::size_t j); // Accès en écriture
        double const & operator()(std::size_t i, std::size_t j) const; // Accès en lecture
        std::size_t nb_lignes() const ;
        std::size_t nb_colonnes() const ;

        Vect3D getLigne(Matrice const& matrice ,size_t indice) const;
        Vect3D getColonne(Matrice const& matrice, size_t indice) const;

        //Vect3D& operator*=(Matrice const & matrice);


    private:
        std::size_t offset(std::size_t ligne, std::size_t colonne) const ;
        std::size_t m_ligne;
        std::size_t m_colonne;
        std::vector<double> m_matrice;


};

Vect3D operator*(Vect3D const & vect, Matrice const & mat);

std::ostream& operator<<(std::ostream & flux, Matrice const& matrice);

#endif