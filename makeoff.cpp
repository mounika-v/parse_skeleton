#include "makeoff.h"

void makeofffile()
{
    FILE *nodef,*elef;
    nodef = fopen("triangle/contour.2.node","r");
    elef = fopen("triangle/contour.2.ele","r");

    cout<<"Writing .off file for the mesh.."<<endl;
    ofstream outdata;
    outdata.open("skeleton/build/offnraw/mesh1.off");
    outdata<<"OFF"<<endl;

    int n=0,ne=0,iter = 1;
    float x,y,z;

    if(fscanf(nodef,"%d %f %f %f\n",&n,&x,&y,&z))
    outdata<<n<<" ";
    if(fscanf(elef,"%d %f %f\n",&ne,&x,&y))
    outdata<<ne<<" "<<0<<endl;

    while(iter != n)
    {
      if(fscanf(nodef,"%d %f %f %f",&iter,&x,&y,&z))
      outdata<<x<<" "<<y<<" "<<z<<endl;
    }

    iter = 1;\
    while(iter != ne)
	  {
		    if(fscanf(elef,"%d %f %f %f",&iter,&x,&y,&z))
		      outdata<<3<<" "<<x-1<<" "<<y-1<<" "<<z-1<<endl;
    }

	  fclose(nodef);
	  fclose(elef);
	  outdata.close();
}
