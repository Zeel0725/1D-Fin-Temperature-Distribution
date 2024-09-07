#include <iostream>
#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main() {

    const char* dir = "ST";
    if (mkdir(dir, 0755) == -1 && errno != EEXIST) 
	{
        perror("Error creating directory");
    }

    int nx;
    printf("Enter number of grids: ");
    scanf("%d",&nx);

    double x[nx+10], T[nx+10], Told[nx+10], d[nx+10], a[nx+10], b[nx+10], R[nx+10];
    
    int i, step, boundary_choicel, boundary_choicer;
    double L, dx, A, dt, TH, TC, ap, aw, ae, a0, rms, residue, S, h, k, Ts, q, B;

	int c;
    scanf("%d", &c);


    dt = 0.01;  // time-step
    residue = 0.000001;  // residue
    B = 0.002;

    printf("Enter the value of volumetric heating rate S: ");
    scanf("%lf", &S);

    // rest of the code remains the same...


printf("\nEnter 1 for constant S\nEnter 2 for S as function of temperatue\nEnter 3 for S as function of fin distance\n");
printf("Volumetric heating rate function- ");
scanf("%d", &c);

printf("\nenter the value of L= ");
scanf("%lf", &L);

printf("enter the value of TH(left)= ");
scanf("%lf", &TH);

printf("enter the value of TC(right)= ");
scanf("%lf", &TC);

printf("enter the value of A(diffusivity)= ");
scanf("%lf", &A);

printf("enter the value of Ts= ");
scanf("%lf", &Ts);

printf("\npress 1 for Dirichlet boundary condition\npress 2 for Robin's boundary condition\npress 3 for Newmann Homogeneous boundary condition\npress 4 for Newmann Non-Homogeneous boundary condition");
printf("\nboundary choice for left side  - ");
scanf("%d",&boundary_choicel);
printf("boundary choice for right side  - ");
scanf("%d",&boundary_choicer);

if (boundary_choicel==2 or boundary_choicer==2)
{
    printf("\nenter the value of h= ");
    scanf("%lf", &h);

    printf("enter the value of k= ");
    scanf("%lf", &k);
}
if (boundary_choicel==4 or boundary_choicer==4)
{
    printf("enter the value of k= ");
    scanf("%lf", &k);
}

if (boundary_choicel==4 or boundary_choicer==4)
{
	printf("enter the value of q= ");
	scanf("%lf", &q);
}
dx = L/nx;  
    x[1] = 0.5*dx;
    x[0] = 0.0;
    x[nx+1] = L;
    for(i=2;i<=nx;i++)
    x[i] = x[i-1] + dx;

    //----------coefficients-------------//
    if(c==2)
    {
      ap = (1+((2*A*dt)/(dx*dx))-B*S);	
	}
	else
	{
		ap = (1+((2*A*dt)/(dx*dx)));
		aw = (-1)*((A*dt)/(dx*dx));
		ae = (-1)*((A*dt)/(dx*dx));
		a0 = 1.0;
	}

    //-------initialisation----------//
   for(i=1;i<=nx;i++) 
  {
		
    T[i] = 0.0;
    Told[i]=0.0;
  }
	
   //---------iterative calculation with TDMA-------------//
   step = 1;
do
{
   	for(i=1;i<=nx-1;i++)  //above diagonal
	a[i] = ae;
	
	for(i=2;i<=nx;i++) 	//below diagonal
	b[i] = aw;
	
	if (boundary_choicel==1)
		d[1] = (ap-aw);   //main diagonal
	else if (boundary_choicel==2)
		d[1]= (ap+((2*k+h*dx)/(2*k-h*dx)*aw));
	else if (boundary_choicel==3)
		d[1]=(ap+aw);
	else if (boundary_choicel==4)
		d[1]=(ap+aw);
	
    if (boundary_choicer==1)	
	    d[nx] = (ap-ae);
	else if (boundary_choicer==2)
	    d[nx] = (ap+((2*k-h*dx)/(2*k+h*dx)*ae)); 
	else if (boundary_choicer==3)
		d[nx]=(ap+ae);
	else if (boundary_choicer==4)
		d[nx]=(ap+ae);
	    

		   

	for(i=2;i<=nx-1;i++)
	d[i] = ap;
	
	if(c==1)	
	{

		if (boundary_choicel==1)
			R[1] = ((a0*T[1])-(2*TH*aw)+S);  //B matirx in AX=B  //main diagonal
		else if (boundary_choicel==2)
			R[1] = ((a0*T[1])+((2*h*dx)/(2*k-h*dx)*aw*Ts)+S);
		else if (boundary_choicel==4)
			R[1] = ((a0*T[1])-(aw*q*dx/(k))+S);
		else if (boundary_choicel==3)
			R[1] = ((a0*T[1])+S);
		
		
		if (boundary_choicer==1)	
			R[nx] = ((a0*T[nx])-(2*TC*ae)+S);
		else if (boundary_choicer==2)
			R[nx] = ((a0*T[nx])-((2*h*dx)/(2*k+h*dx)*ae*Ts)+S);
		else if (boundary_choicer==4)
			R[nx] = ((a0*T[nx])+(ae*q*dx/(k))+S);
		else if (boundary_choicer==4)
			R[1] = ((a0*T[nx])+S);
		
		for(i=2;i<=nx-1;i++)
		R[i] = a0*T[i]+S;
	}
	
	else if (c==3)
	{
		if (boundary_choicel==1)
			R[1] = ((a0*T[1])-(2*TH*aw)+S*B*x[1]);  //B matirx in AX=B  //main diagonal
		else if (boundary_choicel==2)
			R[1] = ((a0*T[1])+((2*h*dx)/(2*k-h*dx)*aw*Ts)+S*B*x[1]);
		else if (boundary_choicel==4)
			R[1] = ((a0*T[1])-(aw*q*dx/(k))+S*B*x[1]);
		else if (boundary_choicel==3)
			R[1] = ((a0*T[1])+S*B*x[1]);
		
		
		if (boundary_choicer==1)	
			R[nx] = ((a0*T[nx])-(2*TC*ae)+S*B*x[nx]);
		else if (boundary_choicer==2)
			R[nx] = ((a0*T[nx])-((2*h*dx)/(2*k+h*dx)*ae*Ts)+S*B*x[nx]);
		else if (boundary_choicer==4)
			R[nx] = ((a0*T[nx])+(ae*q*dx/(k))+S*B*x[nx]);
		else if (boundary_choicer==4)
			R[1] = ((a0*T[nx])+S*B*x[nx]);
		
		for(i=2;i<=nx-1;i++)
		R[i] = a0*T[i]+S*B*x[i];
	}	
	for(i=2;i<=nx;i++)   //forward sweep
	{
		d[i] = (d[i] - ((b[i]/d[i-1])*a[i-1]));
		R[i] = (R[i] - ((b[i]/d[i-1])*R[i-1]));
	}
	
	
	T[nx] = R[nx]/d[nx]; //backword sweep
	
	for(i=nx-1;i>0;i--)
	T[i] = ((R[i] - (a[i]*T[i+1]))/d[i]);
	T[0] = TH;
	T[nx+1] = TC;
	
	double sum = 0.0;   //rms calulation
	for(i=1;i<=nx;i++)
	{
	
	sum = sum + pow((Told[i]-T[i]),2);
	
    Told[i]=T[i];
	printf("%d\t%lf\t%lf\n",step,rms,T[i]);
    }
    rms = sqrt(sum/nx);
	
	if (step%1==0)
		{
			char filename[10000]; //////size of charecter
			FILE*f2;
			// snprintf(filename,"SC/%d.dat",step);
			// sprintf(filename, "ST/%d.dat", step);
			snprintf(filename, sizeof(filename), "/Users/zeel0725/Desktop/CFD/1D-Fin-Temperature-Distribution/src/ST/%d.dat", step);


			f2=fopen(filename,"w");
			if (f2 == NULL) {
				perror("Error opening file");
				return 1;
			}

			fprintf(f2,"VARIABLES=X,T\n");
			fprintf(f2,"\nZONE T=\"0\" i=%d, ZONETYPE=ORDERED,DATAPACKING=POINT\n",nx);
			for (i=1;i<=nx;i++)
			{
		
				{
					fprintf(f2,"%f\t%.10f\n ",x[i],T[i]);
				}
			}
			fclose(f2);
			printf("File to be created: %s\n", filename);

		}
	
    step++;
}

while(rms>residue);
	// printf("%d",step);

	//-------------file writing------------//
	FILE *f1;
	// for(i=0;i<=nx;i++)
	{
		
		// f1 = fopen("temp.dat","w");
		f1 = fopen("/Users/zeel0725/Desktop/CFD/1D-Fin-Temperature-Distribution/src/temp.dat", "w");
		if (f1 == NULL) 
		{
		perror("Error opening temp.dat");
		return 1; // Exit if file opening fails
		}

		fprintf(f1,"VARIABLES=""X"",""TEMPERATURE""\nZONE I=%d ZONETYPE=ORDERED DATAPACKING=POINT\n",nx+2);
		for(i=0;i<=nx+1;i++)
			fprintf(f1,"%lf\t%lf\n",x[i],T[i]);	
	}
	fclose(f1);
	return 0;
}
