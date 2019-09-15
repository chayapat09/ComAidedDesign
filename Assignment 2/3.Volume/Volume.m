syms r L h;
V(r,L,h) = (r.*r.*acos((r-h)./r) - (r-h).*(2.*r.*h-h.*h).^0.5 ).*L;
x = 0:0.2:5;
plot(x,V(2,5,x))