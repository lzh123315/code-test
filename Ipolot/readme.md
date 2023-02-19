## HS071
$min \quad x_1 x_4 (x_1 + x_2 + x_3) + x_3 \\ 
s.t. \quad x_1x_2x_3x_4 \geq 25\\
x_1^2 + x_2^2 + x_3^2 + x_4^2 = 40 \\
1  \leq x_1, x_2, x_3, x_4 \leq 5$
with the starting point 
$x_0 = (1, 5, 5, 1)$
## The C++ Interface
### (1) problem representation
  Creat a class that inherits off the pure virtual base class `Ipopt::TNLP`
### (2) the executable(the main function)
  make the call to Ipopt through the `Ipopt::IpoptApplication` class
### (3) memory management
  using the `Ipopt::SmartPtr` class which  implements a reference counting pointer
  
