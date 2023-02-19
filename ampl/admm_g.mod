param vehicle_l;
param Nstep;

param sigma;
param lambda{1..5*Nstep+1};


param xz{1..Nstep};
param yz{1..Nstep};
param thetaz{1..Nstep};
param vz{1..Nstep};
param phiz{1..Nstep};
param tfz;

param xg0;
param yg0;
param thetag0;
param vg0;
param phig0;
param tfg0;

param xgend;
param ygend;
param thetagend;

var xg{1..Nstep}>=0;
var yg{1..Nstep}>=-4,<=4;
var thetag{1..Nstep}>=-1.57,<=1.57;
var vg{1..Nstep}>=0,<=0.8;
var phig{1..Nstep}>=-0.785,<=0.785;
var tfg >=2;


minimize obj_g: tfg+ sum{i in 1..Nstep-1} (vg[i+1]-vg[i])^2 + sum{i in 1..Nstep-1} (phig[i+1]-phig[i])^2 + 
					sigma*0.5*
					(sum{i in 1..Nstep}(xg[i]-xz[i] + 1/sigma*lambda[i])^2+
					 sum{i in 1..Nstep}(yg[i]-yz[i] + 1/sigma*lambda[Nstep+i])^2+
					 sum{i in 1..Nstep}(thetag[i]-thetaz[i] + 1/sigma*lambda[2*Nstep+i])^2+
					 sum{i in 1..Nstep}(vg[i]-vz[i] + 1/sigma*lambda[3*Nstep+i])^2+
					 sum{i in 1..Nstep}(phig[i]-phiz[i] + 1/sigma*lambda[4*Nstep+i])^2+
					 (tfg-tfz + 1/sigma*lambda[5*Nstep+1])^2
					 ) ;
					 
					 
s.t. ode_x{i in 1..Nstep-1}:
			xg[i+1] - xg[i] = tfg/(Nstep-1)*vg[i]*cos(thetag[i]);
			
s.t. ode_y{i in 1..Nstep-1}:
			yg[i+1] - yg[i] = tfg/(Nstep-1)*vg[i]*sin(thetag[i]);
			
#s.t. ode_theta{i in 1..Nstep-1}:
			#thetag[i+1] - thetag[i] = tfg/(Nstep-1)*vg[i]*tan(phig[i])/vehicle_l;
			
s.t. ode_theta{i in 1..Nstep-1}:
			thetag[i+1] - thetag[i] = tfg/(Nstep-1)*phig[i];			
			
s.t. x0con:
			xg[1] = xg0;
s.t. y0con:
			yg[1] = yg0;
s.t. theta0con:
			thetag[1] = thetag0;

s.t. v0con:
			vg[1] = vg0;
s.t. phi0con:
			phig[1] = phig0;
			
									
s.t. xendcon:
			xg[Nstep] = xgend;
			
s.t. yendcon:
			yg[Nstep] = ygend;
			
s.t. thetaendcon:
			thetag[Nstep] = thetagend;			

