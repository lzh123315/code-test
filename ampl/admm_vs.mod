param a1x;
param a1y;
param b1x;
param b1y;
param c1x;
param c1y;


param a2x;
param a2y;
param b2x;
param b2y;
param c2x;
param c2y;
param d2x;
param d2y;

param a3x;
param a3y;
param b3x;
param b3y;
param c3x;
param c3y;
param d3x;
param d3y;

param a4x;
param a4y;
param b4x;
param b4y;
param c4x;
param c4y;
param d4x;
param d4y;

param a5x;
param a5y;
param b5x;
param b5y;
param c5x;
param c5y;
param d5x;
param d5y;
param e5x;
param e5y;

param s1;
param s2;
param s3;
param s4;
param s5;

param Nstep;

param xg0;
param yg0;
param thetag0;
param vg0;
param phig0;
param tfg0; 

param xgend;
param ygend;
param thetagend;
param err;

var xg{1..Nstep}>=0;
var yg{1..Nstep}>=-2.8,<=4;
var thetag{1..Nstep}>=-1.57,<=1.57;
var vg{1..Nstep}>=0,<=0.8;
var phig{1..Nstep}>=-0.785,<=0.785;
var tfg >=2;


minimize obj_g: tfg+ sum{i in 1..Nstep-1} (vg[i+1]-vg[i])^2 + sum{i in 1..Nstep-1} (phig[i+1]-phig[i])^2;


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
			
s.t. thetaend_con:
			thetag[Nstep] = thetagend;
			
			
s.t. ob1_con{i in 1..Nstep}:
			0.5*abs(xg[i]*a1y+a1x*b1y+b1x*yg[i]-xg[i]*b1y-a1x*yg[i]-b1x*a1y) +
			0.5*abs(xg[i]*c1y+c1x*b1y+b1x*yg[i]-xg[i]*b1y-c1x*yg[i]-b1x*c1y) + 
			0.5*abs(xg[i]*c1y+c1x*a1y+a1x*yg[i]-xg[i]*a1y-c1x*yg[i]-a1x*c1y)  >= s1+err;
			
s.t. ob2_con{i in 1..Nstep}:
			0.5*abs(xg[i]*a2y+a2x*b2y+b2x*yg[i]-xg[i]*b2y-a2x*yg[i]-b2x*a2y) +
			0.5*abs(xg[i]*c2y+c2x*b2y+b2x*yg[i]-xg[i]*b2y-c2x*yg[i]-b2x*c2y) + 
			0.5*abs(xg[i]*c2y+c2x*d2y+d2x*yg[i]-xg[i]*d2y-c2x*yg[i]-d2x*c2y) +
			0.5*abs(xg[i]*a2y+a2x*d2y+d2x*yg[i]-xg[i]*d2y-a2x*yg[i]-d2x*a2y)  >= s2+err;
			
s.t. ob3_con{i in 1..Nstep}:	
			0.5*abs(xg[i]*a3y+a3x*b3y+b3x*yg[i]-xg[i]*b3y-a3x*yg[i]-b3x*a3y) +	
			0.5*abs(xg[i]*c3y+c3x*b3y+b3x*yg[i]-xg[i]*b3y-c3x*yg[i]-b3x*c3y) + 
			0.5*abs(xg[i]*c3y+c3x*d3y+d3x*yg[i]-xg[i]*d3y-c3x*yg[i]-d3x*c3y) +
			0.5*abs(xg[i]*a3y+a3x*d3y+d3x*yg[i]-xg[i]*d3y-a3x*yg[i]-d3x*a3y)  >= s3+err;	
			

s.t. ob4_con{i in 1..Nstep}:	
			0.5*abs(xg[i]*a4y+a4x*b4y+b4x*yg[i]-xg[i]*b4y-a4x*yg[i]-b4x*a4y) +	
			0.5*abs(xg[i]*c4y+c4x*b4y+b4x*yg[i]-xg[i]*b4y-c4x*yg[i]-b4x*c4y) + 
			0.5*abs(xg[i]*c4y+c4x*d4y+d4x*yg[i]-xg[i]*d4y-c4x*yg[i]-d4x*c4y) +
			0.5*abs(xg[i]*a4y+a4x*d4y+d4x*yg[i]-xg[i]*d4y-a4x*yg[i]-d4x*a4y)  >= s4+err;
			
			
s.t. ob5_con{i in 1..Nstep}:	
			0.5*abs(xg[i]*a5y+a5x*b5y+b5x*yg[i]-xg[i]*b5y-a5x*yg[i]-b5x*a5y) +	
			0.5*abs(xg[i]*c5y+c5x*b5y+b5x*yg[i]-xg[i]*b5y-c5x*yg[i]-b5x*c5y) + 
			0.5*abs(xg[i]*c5y+c5x*d5y+d5x*yg[i]-xg[i]*d5y-c5x*yg[i]-d5x*c5y) +	
			0.5*abs(xg[i]*e5y+e5x*d5y+d5x*yg[i]-xg[i]*d5y-e5x*yg[i]-d5x*e5y) +	
			0.5*abs(xg[i]*e5y+e5x*a5y+a5x*yg[i]-xg[i]*a5y-e5x*yg[i]-a5x*e5y)  >= s5+err;	

#s.t. ob5con{i in 1..Nstep}:
			#(xg[i]-3)^2 + (yg[i]+2.1)^2 >=0.26^2;

