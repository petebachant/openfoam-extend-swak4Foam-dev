/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "swak.H"

#ifdef FOAM_HAS_BASICSOURCES

#include "SwakExplicitSource.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

#if defined(FOAM_HAS_FVOPTIONS) && !defined(FOAM_FVOPTION_MAKE_NOT_IN_NAMESPACE)
    namespace fv {
#endif

        makeSwakFvOption(SwakExplicitSource, scalar);
        makeSwakFvOption(SwakExplicitSource, vector);
        makeSwakFvOption(SwakExplicitSource, sphericalTensor);
        makeSwakFvOption(SwakExplicitSource, symmTensor);
        makeSwakFvOption(SwakExplicitSource, tensor);

#if defined(FOAM_HAS_FVOPTIONS) && !defined(FOAM_FVOPTION_MAKE_NOT_IN_NAMESPACE)
    }
#endif

}

#endif

// ************************************************************************* //
