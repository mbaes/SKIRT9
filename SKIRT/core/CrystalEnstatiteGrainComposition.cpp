/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "CrystalEnstatiteGrainComposition.hpp"

//////////////////////////////////////////////////////////////////////

string CrystalEnstatiteGrainComposition::name() const
{
    return "Crystalline_Enstatite";
}

//////////////////////////////////////////////////////////////////////

double CrystalEnstatiteGrainComposition::bulkDensity() const
{
    return 2.8e3;
}

//////////////////////////////////////////////////////////////////////

string CrystalEnstatiteGrainComposition::resourceNameForOpticalProps() const
{
    return "MinEnstatiteOpticalProps";
}

//////////////////////////////////////////////////////////////////////

string CrystalEnstatiteGrainComposition::resourceNameForEnthalpies() const
{
    return "DustEM_aSil_Entalphies";
}

//////////////////////////////////////////////////////////////////////