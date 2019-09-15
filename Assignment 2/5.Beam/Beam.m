function u = Beam(x)
u = -5/6*( (max(0,x) )^4 - ( max(0,x-5) )^4 ) + 15/6 *(max(0,x-8))^3 + 75*(max(0,x-7))^2 +57/6*(x)^3 - 238.25.*x;
end
