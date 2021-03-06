/* Read the parameters from file ParFile
All parameters will be defined here. ParFile does not
need to contain all parameter values. Default values
are called here and defined in default_parameters.c */



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "allvars.h"
#include "proto.h"

#define MAXPAR 100
#define INT 1
#define LONG 2
#define FLOAT 3
#define DOUBLE 4
#define STRING 5

void read_parameters(char *ParFile)
{


  
        FILE *fd;
	char par[MAXPAR][50];
	char buf[200],buf1[200],buf2[200],buf3[200];
	void *addr[MAXPAR];
	int itype[MAXPAR];
	int ip = 0;
	int i;


//	Parameter definition. Default values
	
	default_parameters();

	strcpy(par[ip],"NPhotons");
	itype[ip] = LONG;
	addr[ip++] = &NPhotons;

	strcpy(par[ip],"GeomName");
	itype[ip] = STRING;
	addr[ip++] = GeomName;

	strcpy(par[ip],"Set_Tolerance");
	itype[ip] = STRING;
	addr[ip++] = Set_Tolerance;

	strcpy(par[ip],"IncDust");
	itype[ip] = STRING;
	addr[ip++] = IncDust;

	strcpy(par[ip],"VarXCrit");
        itype[ip] = INT;
        addr[ip++] = &VarXCrit;

	strcpy(par[ip],"IncShield");
	itype[ip] = INT;
	addr[ip++] = &IncShield;

	strcpy(par[ip],"IncUV");
	itype[ip] = INT;
	addr[ip++] = &IncUV;

	strcpy(par[ip],"Static");
	itype[ip] = INT;
	addr[ip++] = &Static;

	strcpy(par[ip],"nout_max");
	itype[ip] = LONG;
	addr[ip++] = &nout_max;

	strcpy(par[ip],"np_max");
	itype[ip] = LONG;
	addr[ip++] = &np_max;

	strcpy(par[ip],"np_min");
	itype[ip] = LONG;
	addr[ip++] = &np_min;

	strcpy(par[ip],"NCellX");
	itype[ip] = LONG;
	addr[ip++] = &NCellX;

	strcpy(par[ip],"NCellY");
	itype[ip] = LONG;
	addr[ip++] = &NCellY;

	strcpy(par[ip],"NCellZ");
	itype[ip] = LONG;
	addr[ip++] = &NCellZ;

	strcpy(par[ip],"NCells");
	itype[ip] = LONG;
	addr[ip++] = &NCells;

	strcpy(par[ip],"XPeriodic");
	itype[ip] = INT;
	addr[ip++] = &XPeriodic;

	strcpy(par[ip],"YPeriodic");
	itype[ip] = INT;
	addr[ip++] = &YPeriodic;

	strcpy(par[ip],"ZPeriodic");
	itype[ip] = INT;
	addr[ip++] = &ZPeriodic;

	strcpy(par[ip],"xSize");
	itype[ip] = DOUBLE;
	addr[ip++] = &xSize;

	strcpy(par[ip],"ySize");
	itype[ip] = DOUBLE;
	addr[ip++] = &ySize;

	strcpy(par[ip],"zSize");
	itype[ip] = DOUBLE;
	addr[ip++] = &zSize;

	strcpy(par[ip],"RSphere");
	itype[ip] = DOUBLE;
	addr[ip++] = &RSphere;

	strcpy(par[ip],"R_Static");
	itype[ip] = DOUBLE;
	addr[ip++] = &R_Static;

	strcpy(par[ip],"Temp");
	itype[ip] = DOUBLE;
	addr[ip++] = &Temp;

	strcpy(par[ip],"vmax");
	itype[ip] = DOUBLE;
	addr[ip++] = &vmax;

	strcpy(par[ip],"b");
	itype[ip] = DOUBLE;
	addr[ip++] = &b;
	
	strcpy(par[ip],"ColDens");
        itype[ip] = DOUBLE;
        addr[ip++] = &ColDens;

	strcpy(par[ip],"mean_nH");
	itype[ip] = DOUBLE;
	addr[ip++] = &mean_nH;

	strcpy(par[ip],"mean_nH_static");
	itype[ip] = DOUBLE;
	addr[ip++] = &mean_nH_static;

	strcpy(par[ip],"Z");
	itype[ip] = DOUBLE;
	addr[ip++] = &mean_z;

	strcpy(par[ip],"Vrot");
	itype[ip] = DOUBLE;
	addr[ip++] = &Vrot;

	strcpy(par[ip],"x_mean");
	itype[ip] = DOUBLE;
	addr[ip++] = &x_mean;

	strcpy(par[ip],"tabledir");
	itype[ip] = STRING;
	addr[ip++] = tabledir;

	strcpy(par[ip],"StartAtCenter");
	itype[ip] = INT;
	addr[ip++] = &StartAtCenter;

	strcpy(par[ip],"DefinePosAndDir");
	itype[ip] = INT;
	addr[ip++] = &DefinePosAndDir;

	strcpy(par[ip],"Ix0");
	itype[ip] = DOUBLE;
	addr[ip++] = &Ix0;

	strcpy(par[ip],"Iy0");
	itype[ip] = DOUBLE;
	addr[ip++] = &Iy0;

	strcpy(par[ip],"Iz0");
	itype[ip] = DOUBLE;
	addr[ip++] = &Iz0;

	strcpy(par[ip],"Ith0");
	itype[ip] = DOUBLE;
	addr[ip++] = &Ith0;

	strcpy(par[ip],"Iph0");
	itype[ip] = DOUBLE;
	addr[ip++] = &Iph0;

	strcpy(par[ip],"OutShort");
	itype[ip] = STRING;
	addr[ip++] = OutShort;

	strcpy(par[ip],"OutLong");
	itype[ip] = STRING;
	addr[ip++] = OutLong;

	strcpy(par[ip],"OutMode");
	itype[ip] = STRING;
	addr[ip++] = OutMode;

	strcpy(par[ip],"dX");
	itype[ip] = DOUBLE;
	addr[ip++] = &dX;

	strcpy(par[ip],"xcritval");
	itype[ip] = DOUBLE;
	addr[ip++] = &xcritval;

	strcpy(par[ip],"Ndot");
	itype[ip] = DOUBLE;
	addr[ip++] = &Ndot;

	strcpy(par[ip],"R_inner");
	itype[ip] = DOUBLE;
	addr[ip++] = &R_inner;

	strcpy(par[ip],"R_Peak");
	itype[ip] = DOUBLE;
	addr[ip++] = &R_Peak;



	strcpy(par[ip],"sxfile");
	itype[ip] = STRING;
	addr[ip++] = sxfile;

	strcpy(par[ip],"Redshift");
	itype[ip] = FLOAT;
	addr[ip++] = &redshift;


	if(fd = fopen(ParFile,"r") )
	{
		while(!feof(fd))
		{
			*buf = 0;					
			fgets(buf,300,fd);
			if(sscanf(buf,"%s%s%s",buf1,buf2,buf3)<2)
				continue;
			if(buf1 == "#")	//Comment lines start with #
				continue;
			
			for (i=0;i<ip;i++)		// search for parameter values in file
			{
				if(strcmp(buf1,par[i]) == 0)
				{
					switch(itype[i])
					{
						case INT:
							*((int *) addr[i]) = atoi(buf3);
							break;
						case LONG:
							*((long *) addr[i]) = atol(buf3);
							break;
					 	case FLOAT:
							*((float *) addr[i]) = atof(buf3);
							break;
						case DOUBLE:
							*((double *) addr[i]) = atof(buf3);
							break;
						case STRING:
							strcpy((char *) addr[i],buf3);
							break;
					}
				}
			}		
		}
		fclose(fd);								
	}
	else
	{
		printf(" Cannot open parameter file %s\n Exiting...\n",ParFile);
		exit(0);
	}
	
#undef INT
#undef LONG
#undef FLOAT
#undef DOUBLE
#undef STRING

}

void print_parameters(cell *CellArr)
{

	printf(" ####################################################################\n");
	printf(" ##	LyaRT: Monte Carlo radiative transfer of Ly-alpha photons	   ##\n");
	printf(" ####################################################################\n");



	printf("#########################################################################\n");
	printf(" 				PARAMETERS LIST:\n");
	printf("(some of the following parameters could be irrelevant for your current run, \n");
	printf(" but still they must be defined) \n");
	printf("#########################################################################\n");
	printf("Output File %s\n",OutShort);
	printf("Parameter File %s\n",ParFile);
	printf("Gas geometry: %s\n",GeomName);
	printf("Dust included ?: %s\n",IncDust);
	printf("Include UV Background ? : %d\n",IncUV);
	dprinti(StartAtCenter);
	dprintf(xcritval);
	dprintf(redshift);
	if (b == 0)
		printf("No turbulent velocity\n");
	else
	{
		dprintd(b);
		dprintd(CellArr[1].T);
	}
	
	dprinti(IncShield);
	dprintl(NPhotons);
	dprintl(NCells);
	dprints(Set_Tolerance);
	dprintd(RSphere);
	dprintd(xSize);
	dprintd(ySize);
	dprintd(zSize);
	dprintd(vmax);
	dprintd(Temp);
	dprints(HFile);
	dprintd(mean_z);
	dprintd(mean_nH);
	dprintd(Ndot);
	dprintd(R_inner);
	dprints(OutMode);
	dprintd(mean_nH);
	dprintd(CellArr[0].nH);
	dprintd(CellArr[1].nH);
	printf("*******************************************\n");

}

	
