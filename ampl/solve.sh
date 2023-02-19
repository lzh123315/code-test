ampl
reset;
model ./models/oil.mod;
data ./models/oil.data;
option solver ipopt;
solve;