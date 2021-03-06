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
    \\  /    A nd           | Copyright  held by original author
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
    simpleFunctionObject

Description
    Basis for the other function objects here. Creates the directory and the files

SourceFiles
    simpleFunctionObject.C

Contributors/Copyright:
    2008-2011, 2013, 2015 Bernhard F.W. Gschaider <bgschaid@ice-sf.at>

 SWAK Revision: $Id$
\*---------------------------------------------------------------------------*/

#ifndef simpleDataFunctionObject_H
#define simpleDataFunctionObject_H

#include "simpleFunctionObject.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class simpleDataFunctionObject Declaration
\*---------------------------------------------------------------------------*/

class simpleDataFunctionObject
:
    public simpleFunctionObject
{
    // Private Member Functions

    //- Disallow default bitwise copy construct
    simpleDataFunctionObject(const simpleDataFunctionObject&);

    //- Disallow default bitwise assignment
    void operator=(const simpleDataFunctionObject&);

    static fileName defaultPostProcDir_;

    fileName postProcDir_;

protected:

    //- Get the path to the data directory
    virtual fileName dataDir();

    //- Get the path to the base directory
    fileName baseDir();

    //- Name of the sub-dictionary of the case
    virtual word dirName()=0;

public:

    //- Runtime type information
    TypeName("simpleDataFunctionObject");


    // Constructors

    //- Construct from components
    simpleDataFunctionObject
    (
        const word&,
        const Time&,
        const dictionary&
    );

    bool start();

    static void setPostProcDir(const fileName &);

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
