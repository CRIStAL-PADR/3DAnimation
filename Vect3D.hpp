#ifndef _Vect3D_
#define _Vect3D_


#include <iostream>
#include <vector>
#include <algorithm>

class Vect3D
{
    public:
        Vect3D(std::size_t ligne, std::size_t colonne, double valeur = 0);
        double & operator()(std::size_t i, std::size_t j); // Accès en écriture
        double const & operator()(std::size_t i, std::size_t j) const; // Accès en lecture
        std::size_t nb_lignes() const ;
        std::size_t nb_colonnes() const ;


    private:
        std::size_t offset(std::size_t ligne, std::size_t colonne) const ;
        std::size_t m_ligne;
        std::size_t m_colonne;
        std::vector<double> m_vect3d;


};

std::ostream& operator<<(std::ostream & flux, Vect3D const& vect);

#endif