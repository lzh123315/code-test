param vehicle_l;
param Nstep;
param ob_num;

param sigma;
param lambda{1..5*Nstep+1};


param xg{1..Nstep};
param yg{1..Nstep};
param thetag{1..Nstep};
param vg{1..Nstep};
param phig{1..Nstep};
param tfg;

param xz0;
param yz0;


param xzend;
param yzend;
param thetazend;

param Lstack{1..Nstep, 1..ob_num, 1..2};
param Sstack{1..Nstep, 1..ob_num};
param margin;

var xz{1..Nstep}>=0;
var yz{1..Nstep}>=-4,<=4;
var thetaz{1..Nstep}>=-1.57,<=1.57;
var vz{1..Nstep}>=0,<=0.8;
var phiz{1..Nstep}>=-0.785,<=0.785;
var tfz >=2;


minimize obj_z: sigma*0.5*
					(sum{i in 1..Nstep}(xg[i]-xz[i] + 1/sigma*lambda[i])^2+
					 sum{i in 1..Nstep}(yg[i]-yz[i] + 1/sigma*lambda[Nstep+i])^2+
					 sum{i in 1..Nstep}(thetag[i]-thetaz[i] + 1/sigma*lambda[2*Nstep+i])^2+
					 sum{i in 1..Nstep}(vg[i]-vz[i] + 1/sigma*lambda[3*Nstep+i])^2+
					 sum{i in 1..Nstep}(phig[i]-phiz[i] + 1/sigma*lambda[4*Nstep+i])^2+
					 (tfg-tfz + 1/sigma*lambda[5*Nstep+1])^2
					 ) ;
					 
					 
					
s.t. x0con:
			xz[1] = xz0;
s.t. y0con:
			yz[1] = yz0;
			
s.t. xcon{i in 1..Nstep-1}:
			xz[i+1] >= xz[i];
			
#s.t. ycon{i in 1..Nstep-1}:
			#abs(yz[i+1]-yz[i])<=0.05;			
												
s.t. xendcon:
			xz[Nstep] = xzend;
			
s.t. yendcon:
			yz[Nstep] = yzend;
			
s.t. thetaendcon:
			thetaz[Nstep] = thetazend;			
			
s.t. vb_free_con{i in 1..Nstep, j in 1..ob_num}:
			xz[i]*Lstack[i,j,1]+yz[i]*Lstack[i,j,2] <= Sstack[i,j]- margin;
			
			
			

