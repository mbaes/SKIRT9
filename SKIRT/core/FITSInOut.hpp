/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#ifndef FITINSOUT_HPP
#define FITINSOUT_HPP

#include "Array.hpp"
class SimulationItem;

////////////////////////////////////////////////////////////////////

/** The FITSInOut class offers static functions to read/write a 2D or 3D data stream from/to a
    standard FITS file, with support for a basic set of metadata in the header. */
class FITSInOut final
{
public:
    // ================== Read/write in the context of an item hierarchy ==================

    /** This function reads data from a FITS file in the context of the simulation item hierarchy
        specified through the first argument. This allows the function to issue log messages and to
        determine a full path from the input filename specified as the second argument, relative to
        the simulation's input path. The input filename should include the filename extension. The
        remaining arguments of this function are the same as those described for the basic read()
        function in this class. */
    static void read(const SimulationItem *item, string filename, Array& data, int& nx, int& ny, int& nz);

    /** This function writes data to a FITS file in the context of the simulation item hierarchy
        specified through the first argument. This allows the function to issue log messages using
        the human-readable description of the data given as the second argument, to skip writing in
        non-root processes of a multi-process similation, and to determine a full path from the
        output filename specified as the third argument, relative to the simulation's output path.
        The output filename should \em not include the filename extension nor the simulation
        prefix. The remaining arguments of this function are the same as those described for the
        basic write() function in this class. */
    static void write(const SimulationItem *item, string description, string filename,
                      const Array& data, int nx, int ny, int nz,
                      double incx, double incy, double xc, double yc, string dataUnits, string xyUnits);

    // ================== Basic read/write ==================

    /** This function reads a data frame or cube from a FITS file containing one or more data
        planes (i.e. a 2D or 3D data array). The first argument specifies a relative or absolute
        file path; a file with that name should exist. By default, the function uses the first
        nonempty data unit in the file; usually this is the primary data unit. To specify another
        data unit, add the extension name (EXTNAME) between square brackets after the file
        name. For example:

            SomePath/myFile.fits[SED]

        The subsequent function arguments serve to store data read from the file: \em data receives
        the actual values in the data cube; \em nx and \em ny receive the number of values in each
        direction, \em nz specifies the number of planes (which is equal to 1 for 2D data). The
        values in the \em data array are ordered such that the index along the x-axis varies most
        rapidly, the index along the y-axis varies less rapidly, and the index along the z-axis (if
        present) varies least rapidly. */
    static void read(string filepath, Array& data, int& nx, int& ny, int& nz);

    /** This function reads a single table column from a FITS file containing a two-dimensional
        table. The first argument specifies a relative or absolute file path; a file with that name
        should exist. By default, the function uses the first column of the first table in the
        file. To specify another table, add the extension name (EXTNAME) of the data unit
        containing the table between square brackets after the file name. To specify another column
        in the table, add the column name as follows:

            SomePath/myFile.fits[AXES][col time]

        The \em data argument serves to store the column data read from the file, and \em n
        specifies the number of values (i.e. rows) to be read. */
    static void readColumn(string filepath, Array& data, int n);

    /** This function writes a FITS file containing one or more data planes (i.e. a 2D or 3D data
        array) in the primary data unit. The first argument specifies a relative or absolute file
        path; if a file with that name already exists, it is overwritten. The subsequent arguments
        specify the contents of the file: \em data contains the actual values in the data cube; \em
        nx and \em ny specify the number of values in each direction, \em nz specifies the number
        of planes (set \em nz to 1 for 2D data), \em incx and \em incy specify the increment
        between subsequent grid points in each direction, \em xc and \em yc specify the centre of
        the image, \em dataUnits describes the units of the data values, and \em xyUnits describes
        the units of the xy-grid increments. The values in the \em data array must be ordered such
        that the index along the x-axis varies most rapidly, the index along the y-axis varies less
        rapidly, and the index along the z-axis (if present) varies least rapidly. */
    static void write(string filepath, const Array& data, int nx, int ny, int nz,
                      double incx, double incy, double xc, double yc, string dataUnits, string xyUnits);

};

////////////////////////////////////////////////////////////////////

#endif
