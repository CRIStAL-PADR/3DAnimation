#include <cassert>
#include <iostream>
#include "Vect3D.hpp"

using namespace std;
namespace linalg
{
    Vect3D::Vect3D(size_t colonne,double valeur):m_ligne(1), m_colonne(colonne),m_vect3d( m_ligne * m_colonne, valeur)
    {
        
    }

    double & Vect3D::operator()(std::size_t i)
    {

        return m_vect3d[i];
    }

    double const& Vect3D::operator()(std::size_t i) const
    {

        return m_vect3d[i];
    }


    std::ostream& operator<<(std::ostream & flux, Vect3D  const & vect) {
        size_t i ;
        flux << "[ ";
        for(i = 0; i < vect.nb_colonnes(); i++){
            
            flux << vect(i) << " ";
        }
        flux << "] \n ";
        return flux;
    }

    size_t  Vect3D::nb_colonnes() const{
        return m_colonne;
    } 

}
