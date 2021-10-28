#include <cassert>
#include <iostream>

#include "Matrice.hpp"
#include "Vect3D.hpp"

using namespace std;

Matrice::Matrice(size_t ligne, size_t colonne, double valeur):m_ligne(ligne), 
m_colonne(colonne), m_matrice(ligne * colonne, valeur)
{
    if (m_colonne != m_ligne){
        perror("La matrice doit être une matrice carré\n");
        exit(-1);
    }
}


std::size_t Matrice::offset(std::size_t ligne, std::size_t colonne) const 
{
    // retourne l'indice de la matrice ou on aimerait accéder
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


size_t Matrice::nb_lignes() const 
{
    return m_ligne;
}

size_t Matrice::nb_colonnes() const 
{
    return m_colonne;
}

std::ostream& operator<<(std::ostream & flux, Matrice  const & matrice){
    size_t i ; size_t j ;
    for(i = 0; i < matrice.nb_lignes(); i++){
        for(j = 0; j < matrice.nb_colonnes(); j++){
            flux << matrice(i, j) << " ";
        }
        flux << " \n";
    }

    return flux;
}

Vect3D Matrice::getLigne(Matrice const& matrice, size_t indice) const
{
    Vect3D vect( 1, matrice.nb_colonnes(),0);
    for(size_t i = 0; i< matrice.nb_colonnes(); i++){
        vect(0, i) = matrice(i, indice);
    }
    return vect;
}

Vect3D  Matrice::getColonne(Matrice const& matrice, size_t indice) const
{
    Vect3D vect(matrice.nb_lignes(), 1, 0);
    for(size_t i = 0; i< matrice.nb_lignes(); i++){
        vect(i, 0) = matrice(i, indice);
    }
    return vect;
}

Vect3D operator*(Vect3D const & vect, Matrice const & mat) 
{
    // Le produit vect * mat va retourner un vect
    try
    {
        if(vect.nb_colonnes() != mat.nb_lignes())
            throw  string(" le nombre de ligne du vect est different du nombre de ligne de la matrice");

    }
    catch(string const& chaine)
    {
        cerr << chaine << endl;
    }

            
    Vect3D copie(vect.nb_lignes(), mat.nb_colonnes(), 0);
    for (size_t i { 0 }; i < copie.nb_lignes(); i++)
    {
        for (size_t j { 0 }; j < copie.nb_colonnes(); j++)
        {
            for (size_t k { 0 }; k < vect.nb_colonnes(); k++)
            {
                copie(i, j) = copie(i,j) + vect(i, k) * mat(k, j);
            }
        }
    }
    return copie;
}
