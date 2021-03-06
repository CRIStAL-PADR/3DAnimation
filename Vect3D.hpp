#ifndef _Vect3D_
#define _Vect3D_


#include <iostream>
#include <vector>
#include <algorithm>

namespace linalg
{
    class Vect3D
    {
        public:
            Vect3D(size_t colonne, double valeur = 0);
            double & operator()(std::size_t i); // Accès en écriture
            double const & operator()(std::size_t i) const; // Accès en lecture
            Vect3D transpose();
            std::size_t nb_colonnes() const ;

        private:
            std::size_t m_ligne;
            std::size_t m_colonne;
            std::vector<double> m_vect3d;


    };

    std::ostream& operator<<(std::ostream & flux, Vect3D const& vect) ;

}
#endif