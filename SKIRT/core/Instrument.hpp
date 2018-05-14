/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#ifndef INSTRUMENT_HPP
#define INSTRUMENT_HPP

#include "SimulationItem.hpp"
#include "Direction.hpp"
#include "Position.hpp"
#include "WavelengthGrid.hpp"
class PhotonPacket;

////////////////////////////////////////////////////////////////////

/** Instrument is an abstract class representing instruments to collect the photon packets during a
    Monte Carlo simulation. Subclasses implement instruments that can vary in type of projection
    (e.g. parallel or perspective) and in what is recorded (e.g. SED or full integral field data
    cube). This top-level abstract class offers a generic interface for receiving photon packets
    from the simulation. It also includes the facilities for configuring the instrument's
    wavelength grid either by specifying a grid for this instrument specifically, or by defaulting
    to the common grid specified for the instrument system. */
class Instrument : public SimulationItem
{
    ITEM_ABSTRACT(Instrument, SimulationItem, "an instrument")

    PROPERTY_STRING(instrumentName, "the name for this instrument")

    PROPERTY_ITEM(wavelengthGrid, WavelengthGrid, "the wavelength grid for this instrument")
        ATTRIBUTE_DEFAULT_VALUE(wavelengthGrid, "LogWavelengthGrid")
        ATTRIBUTE_OPTIONAL(wavelengthGrid)

    ITEM_END()

    //============= Construction - Setup - Destruction =============

protected:
    /** This function performs setup for the instrument. It sets the wavelength grid for the
        instrument: if a grid is specified for the instrument, this grid is used. If not, the
        default wavelength grid specified for the instrument system is used. If neither of these
        grids are specified, the function throws a fatal error. */
    void setupSelfBefore() override;

    //======================== Other Functions =======================

public:
    /** Returns the wavelength grid for the instrument as determined during setup, i.e. either the
        grid specified for this instrument or the default grid specified for the instrument system.
        After setup has completed, the function never returns a nulltpr because setupSelfBefore()
        throws a fatal error if neither of these grids are specified. */
    const WavelengthGrid* instrumentWavelengthGrid() const { return _instrumentWavelengthGrid; }

    //=========== Functions to be implemented in subclass ===========

public:
    /** Returns the direction towards the observer, given the photon packet's launching position.
        The implementation must be provided in a subclass. */
    virtual Direction bfkobs(const Position& bfr) const = 0;

    /** Returns the direction along the positive x-axis of the instrument frame, expressed in model
        coordinates. The implementation must be provided in a subclass. */
    virtual Direction bfkx() const = 0;

    /** Returns the direction along the positive y-axis of the instrument frame, expressed in model
        coordinates. The implementation must be provided in a subclass. */
    virtual Direction bfky() const = 0;

    /** This function simulates the detection of a photon packet by the instrument. Its
        implementation must be provided in a subclass. */
    virtual void detect(PhotonPacket* pp) = 0;

    /** This function calibrates the instrument and writes down the recorded contents to a set of
        files. Its implementation must be provided in a subclass. */
    virtual void write() = 0;

    //======================== Data Members =======================

private:
    const WavelengthGrid* _instrumentWavelengthGrid{nullptr};
};

////////////////////////////////////////////////////////////////////

#endif
