/*
 conductivity.h

 Copyright (c) 2014 Terumasa Tadano

 This file is distributed under the terms of the MIT license.
 Please see the file 'LICENCE.txt' in the root directory 
 or http://opensource.org/licenses/mit-license.php for information.
*/

#pragma once

#include "pointers.h"
#include <vector>
#include <set>

namespace PHON_NS {

    class Conductivity: protected Pointers {
    public:
        Conductivity(class PHON *);
        ~Conductivity();
        void setup_kappa();
        void prepare_restart();
        void calc_anharmonic_imagself();
        void compute_kappa();
        void finish_kappa();

        int use_classical_Cv;
        unsigned int ntemp;
        double **damping3;
        double ***kappa;
        double *Temperature;

    private:
        double ***vel;
        unsigned int nk, ns;
        int nshift_restart;
        std::vector<int> vks, vks_l, vks_done;
        std::set<int> vks_job;

        void write_result_gamma(const unsigned int, const unsigned int, double ***, double **);
        void average_self_energy_at_degenerate_point(const int, const int, double **);
    };
}
