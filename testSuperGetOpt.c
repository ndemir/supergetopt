/*********************************************************************

Copyright (c) 2007, Anthony P. Russo

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of Russolutions, Inc. nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*********************************************************************/

#include <stdio.h>
#include "supergetopt.h"

static void usage();

int main( int argc, char *argv[] )
{
	int n, i;
	int argErr;
	
	char c; double lf; char *s; int d; short h; float f;
	float farray[20];
	int numf = 20; // must be set to max initially -- will be overwritten with actual number
	char *sarray[10];
	int nums = 10;
	int helpSet = 12;
	char *ss;
	
/* example call to supergetopt */

	n = superGetOpt(argc,argv, &argErr,
			"-puffy %c %lf %s %d",&c, &lf, &s, &d,
			"-eminem %hd %f", &h, &f,
			"-vanna *%f", farray, &numf,
			"-stringo *%s", sarray, &nums,
			"-what %s", &ss,
			"-help", &helpSet,
			(char * ) 0 ); 
#if 1	
	printf("-puffy has c=%c double=%lf s=%s int=%d eminem has short=%hd fl=%f\n", c,lf,s,d,h,f);
	//printf("-stringo array=%s,%s,%s nums=%d\n", sarray[0],sarray[1],sarray[2],nums);
	for( i = 0, printf("stringo: ") ; i < nums ; i++ )
		printf("<%s> ", sarray[i]);
	printf("\n");
	for( i = 0, printf("vanna: ") ; i < numf ; i++ )
		printf("<%f> ", farray[i]);
	printf("\n");
#endif
	printf("Supergetopt returned %d argErr=%d helpSet=%d\n", n,argErr,helpSet);
	
	if( helpSet ) usage();
	
	return(0);
}

static void usage()
{
printf("testSuperGet: [options] Options:\n\
\t[-puffy: <char> <double> <string> <int>]\n\
\t[-eminem: <short> <float>]\n\
\t[-stringo: <string1> ... <stringN>]\n\
\t[-what: <string>]\n\
\t[-vanna: <float1> ... <floatN>]\n\
\t[-help]\n"
 );
}

