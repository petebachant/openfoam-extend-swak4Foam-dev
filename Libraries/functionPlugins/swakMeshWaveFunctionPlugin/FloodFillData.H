/*---------------------------------------------------------------------------*\
 ##   ####  ######     |
 ##  ##     ##         | Copyright: ICE Stroemungsfoschungs GmbH
 ##  ##     ####       |
 ##  ##     ##         | http://www.ice-sf.at
 ##   ####  ######     |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2008 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is based on OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    Foam::FloodFillData

Description
    Helper class for Flood-Filling

SourceFiles
    FloodFillData.C

Contributors/Copyright:
    2014 Bernhard F.W. Gschaider <bgschaid@ice-sf.at>

 SWAK Revision: $Id$
\*---------------------------------------------------------------------------*/

#ifndef FloodFillData_H
#define FloodFillData_H

#include "FaceCellWaveData.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class FaceCellWave Declaration
\*---------------------------------------------------------------------------*/


class FloodFillData
:
    public FaceCellWaveData
{
    label val_;

    label target_;

    bool blocked_;
public:

    inline FloodFillData();

    inline FloodFillData(label target,label d,bool blocked=false);

    inline label val() const;

    inline void setTarget(label t);

#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
    template<class TrackingData>
#endif
    inline bool valid(
#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
        TrackingData &
#endif
    ) const;

    inline bool blocked() const;

#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
    template<class TrackingData>
#endif
    inline bool updateCell
    (
        const polyMesh& mesh,
        const label thisCellI,
        const label neighbourFaceI,
        const FloodFillData& neighbourInfo,
        const scalar tol
#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
        ,TrackingData &
#endif
    );

#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
    template<class TrackingData>
#endif
    inline bool updateFace
    (
        const polyMesh& mesh,
        const label thisFaceI,
        const label neighbourCellI,
        const FloodFillData& neighbourInfo,
        const scalar tol
#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
        ,TrackingData &
#endif
    );

#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
    template<class TrackingData>
#endif
    inline bool updateFace
    (
        const polyMesh&,
        const label thisFaceI,
        const FloodFillData& neighbourInfo,
        const scalar tol
#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
        ,TrackingData &
#endif
    );

    inline bool operator!=(const FloodFillData &rhs) const;

    friend inline Ostream& operator<<(Ostream&, const FloodFillData&);
    friend inline Istream& operator>>(Istream&, FloodFillData&);

#ifdef FOAM_FACECELLWAVE_HAS_TRACKINGDATA
    template<class TrackingData>
    inline bool equal(const FloodFillData &rhs,TrackingData &td) const;
#endif
};

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "FloodFillData.C"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
