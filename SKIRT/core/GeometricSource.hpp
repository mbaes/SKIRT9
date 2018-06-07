/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#ifndef GEOMETRICSOURCE_HPP
#define GEOMETRICSOURCE_HPP

#include "Source.hpp"
#include "Geometry.hpp"
#include "LuminosityNormalization.hpp"
#include "SED.hpp"

//////////////////////////////////////////////////////////////////////

/** GeometricSource represents a primary radiation source for which the spatial luminosity
    distribution is characterized by a Geometry object. The spectral distribution is identical in
    all locations and is characterized by an SED object. The bolometric output is characterized by
    a LuminosityNormalization object. The emitted radiation is isotropic and unpolarized. The
    source can have a single bulk velocity, i.e. the bulk velocity is identical in all locations.
    */
class GeometricSource : public Source
{
    ITEM_CONCRETE(GeometricSource, Source, "a primary source with a built-in geometry")

    PROPERTY_ITEM(geometry, Geometry, "the geometry of the spatial luminosity distribution for the source")
        ATTRIBUTE_DEFAULT_VALUE(geometry, "PlummerGeometry")

    PROPERTY_ITEM(sed, SED, "the spectral energy distribution for the source")
        ATTRIBUTE_DEFAULT_VALUE(sed, "SunSED")

    PROPERTY_ITEM(normalization, LuminosityNormalization, "the type of luminosity normalization for the source")
        ATTRIBUTE_DEFAULT_VALUE(normalization, "IntegratedLuminosityNormalization")

    ITEM_END()

    //======================== Other Functions =======================

public:
    /** This function returns the dimension of the source, which is the same as the dimension of
     * its source, except if there is a nonzero bulk velocity. */
    int dimension() const override;

    /** This function returns the luminosity \f$L\f$ (i.e. radiative power) of the source
        integrated over the wavelength range of primary sources (configured for the source system
        as a whole) and across its complete spatial domain. */
     double luminosity() const override;

     /** This function returns the specific luminosity \f$L_\lambda\f$ (i.e. radiative power per
         unit of wavelength) of the source at the specified wavelength, or zero if the wavelength is
         outside the wavelength range of primary sources (configured for the source system as a
         whole) or if the source simply does not emit at the wavelength. */
     double specificLuminosity(double wavelength) const override;

     /** This function causes the photon packet \em pp to be launched from the source using the
         given history index and luminosity contribution. The position and propagation direction of
         the emission are determined randomly from the geometry of the source. */
    void launch(PhotonPacket* pp, size_t historyIndex, double L) const override;
};

//////////////////////////////////////////////////////////////////////

#endif