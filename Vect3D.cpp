#include <cassert>
#include <iostream>
#include "Vect3D.hpp"

using namespace std;

Vect3D::Vect3D(size_t ligne, size_t colonne, double valeur):m_ligne(ligne), 
m_colonne(colonne), m_vect3d(ligne * colonne, valeur)
{
    if (m_colonne == m_ligne){
        perror("Les valeurs données ne permettent pas d'avoir une matrice vecteur\n");
        exit(-1);
    }
}


std::size_t Vect3D::offset(std::size_t ligne, std::size_t colonne) const 
{
    // retourne l'indice de la matrice ou on aimerait accéder
    assert(ligne < m_ligne && "Ligne demandée invalide.");
    assert(colonne < m_colonne && "Colonne demandée invalide.");
    return colonne * m_ligne + ligne;
}


double & Vect3D::operator()(std::size_t x, std::size_t y)
{

    return m_vect3d[offset(x, y)];
}

double const& Vect3D::operator()(std::size_t x, std::size_t y) const
{

    return m_vect3d[offset(x, y)];
}


size_t Vect3D::nb_lignes() const 
{
    return m_ligne;
}

size_t Vect3D::nb_colonnes() const 
{
    return m_colonne;
}

std::ostream& operator<<(std::ostream & flux, Vect3D  const & vect){
    size_t i ; size_t j ;
    for(i = 0; i < vect.nb_lignes(); i++){
        for(j = 0; j < vect.nb_colonnes(); j++){
            flux << vect(i, j) << " ";
        }
        flux << " \n";
    }

    return flux;
}


