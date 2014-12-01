

#include <triv_lib.h>
#include <cagd_lib.h>



	extern "C" {
#include "geom_lib.h"
#include "irit_sm.h"
#include "iritprsr.h"
#include "allocate.h"
#include "geom_lib.h"
	}


#include <iostream>
#include <cstdio>
#include <cstdlib>
/*****************************************************************************
* Compute the area of a polyhedra object.				     *
******************************************************************************
* (C) Gershon Elber, Technion, Israel Institute of Technology                *
******************************************************************************
* Written by:  Gershon Elber				Ver 1.0, June 1995   *
*****************************************************************************/


#include <areaFunction.h>
#include <vtkUnstructuredGrid.h>
#include <vtkSmartPointer.h>

void main(int argc, char **argv)
{
	vtkSmartPointer<vtkUnstructuredGrid> mesh = vtkSmartPointer<vtkUnstructuredGrid>::New();
	mesh->Print(std::cout);
	

	if (argc == 2) {
		calculatePolyhedraArea(argv[1]);
	}
	else {
		fprintf(stderr, "Usage: PolyArea geom.dat\n");
		exit(2);
	}

	exit(0);
}

#if 0
int main(int argc, char *argv[])
{
	printf("IRIT_TEST  tt\n");
	CagdCrvStruct crv;
	printf("Length : %d\n", crv.Length);

	return 0;
}
#endif