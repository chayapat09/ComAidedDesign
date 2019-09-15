function v = Piecewise(x)
syms t
c = [x>30 , x>20 , x>10 ,x>=0,1];
a = [1520*exp((-0.2*(t-30))) , 50*t+2*(t-20)^2 , 1100-5*t ,11*t*t-5*t , 0];
i = 1;
while ~c(i) ; i = i + 1; end
v(t) = a(i);v = v(x);
end

