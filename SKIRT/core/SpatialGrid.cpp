/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "SpatialGrid.hpp"
#include "Random.hpp"

//////////////////////////////////////////////////////////////////////

void SpatialGrid::setupSelfBefore()
{
    SimulationItem::setupSelfBefore();

    _random = find<Random>();
}

//////////////////////////////////////////////////////////////////////

void SpatialGrid::write_xy(SpatialGridPlotFile* /*outfile*/) const
{
}

//////////////////////////////////////////////////////////////////////

void SpatialGrid::write_xz(SpatialGridPlotFile* /*outfile*/) const
{
}

//////////////////////////////////////////////////////////////////////

void SpatialGrid::write_yz(SpatialGridPlotFile* /*outfile*/) const
{
}

//////////////////////////////////////////////////////////////////////

void SpatialGrid::write_xyz(SpatialGridPlotFile* /*outfile*/) const
{
}

//////////////////////////////////////////////////////////////////////