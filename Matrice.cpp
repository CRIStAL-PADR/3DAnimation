#include <cassert>
#include <iostream>

#include "Matrice.hpp"
#include "Vect3D.hpp"

using namespace std;
using namespace linalg;

Matrice::Matrice(double valeur):m_ligne(3), m_colonne(3), m_matrice( m_ligne * m_colonne , valeur)
{

}


std::size_t Matrice::offset(std::size_t ligne, std::size_t colonne) const 
{
    // retourne l'indice  m_ligne = 1;   de la matrice ou on aimerait accéder
    assert(ligne < m_ligne && "Ligne demandée invalide.");
    assert(colonne < m_colonne && "Colonne demandée invalide.");
    return colonne * m_ligne + ligne;
}


double & Matrice::operator()(std::size_t x, std::size_t y)
{

    return m_matrice[offset(x, y)];
}

double const& Matrice::operator()(std::size_t x, std::size_t y) const
{

    return m_matrice[offset(x, y)];
}



std::ostream& operator<<(std::ostream & flux, Matrice  const & matrice){
    size_t i ; size_t j ;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            flux << matrice(i, j) << " ";
        }
        flux << " \n";
    }

    return flux;
}

/*Vect3D operator*(Matrice const& mat, Vect3D const& vect){
    
}*/

Vect3D operator*(Vect3D const & vect, Matrice const & mat) 
{
  
    if(vect.nb_colonnes() == 3)
    {   // Produit vect ligne par mat donne  un vect ligne
        Vect3D copie(3, 0);
        for (size_t j { 0 }; j < copie.nb_colonnes(); j++)
        {
            for (size_t k { 0 }; k < vect.nb_colonnes(); k++)
            {
                copie(j) = copie(j) + vect(k) * mat(k, j);
            }
        }
        return copie;
    }
    /*
    else if(vect.nb_lignes() == mat.nb_colonnes())
    {   // Produit d'une mat par un vect colonne donne  un vect colonne
        Vect3D copie(mat.nb_lignes(), vect.nb_colonnes(), 0);
        for (size_t i { 0 }; i < copie.nb_lignes(); i++)
        {
            for (size_t j { 0 }; j < copie.nb_colonnes(); j++)
            {
                for (size_t k { 0 }; k < mat.nb_colonnes(); k++)
                {
                    copie(i, j) = copie(i,j) + mat(i, k) * vect(k, j);
                }
            }
        }
        return copie;
    }*/
    else{
        throw("Impossible de faire ce produit matricielle");
        exit(0);
    }
    
}


/* Vect3D Matrice::getLigne(Matrice const& matrice, size_t indice) const
{
    Vect3D vect(3 ,0);
    for(size_t i = 0; i< 3; i++){
        vect(i) = matrice(i, indice);
    }
    return vect;
}

Vect3D  Matrice::getColonne(Matrice const& matrice, size_t indice) const
{
    Vect3D vect(3, 1, 0);
    for(size_t i = 0; i< 3; i++){
        vect(i, 0) = matrice(i, indice);
    }
    return vect;
}
*/
