#include "areaFunction.h"
#include <triv_lib.h>
#include <cagd_lib.h>



extern "C" {
#include "geom_lib.h"
#include "irit_sm.h"
#include "iritprsr.h"
#include "allocate.h"
#include "geom_lib.h"
}


void calculatePolyhedraArea (const char * fileName) {
	int Handler;

	if ((Handler = IPOpenDataFile(fileName, TRUE, TRUE)) >= 0) {
		IPObjectStruct
			*PObj = IPGetObjects(Handler);


        // New dev.
        // ...
		/* Done with file - close it. */
		IPCloseStream(Handler, TRUE);

		fprintf(stderr, "Object is %d \n", PObj->ObjType);
		fprintf(stderr, "Object is %s \n",IPObjTypeAsString(PObj));

		/* Process the geometry - compute the accumulated area. */
		if (IP_IS_POLY_OBJ(PObj) && IP_IS_POLYGON_OBJ(PObj))
			fprintf(stderr, "Area of polyhedra is %lf\n",
			GMPolyObjectArea(PObj));
		else
			fprintf(stderr, "Read object is not a polyhedra.\n");

		IPFreeObject(PObj);
	}
	else {
		fprintf(stderr, "Failed to open file \"%s\"\n", fileName);
		exit(1);
	}

}
