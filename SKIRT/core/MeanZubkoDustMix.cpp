/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "MeanZubkoDustMix.hpp"

////////////////////////////////////////////////////////////////////

MaterialMix::ScatteringMode MeanZubkoDustMix::scatteringMode() const
{
    return ScatteringMode::HenyeyGreenstein;
}

//////////////////////////////////////////////////////////////////////

string MeanZubkoDustMix::resourceNameForOpticalProps() const
{
    return "MeanZubkoOpticalProps";
}

//////////////////////////////////////////////////////////////////////
