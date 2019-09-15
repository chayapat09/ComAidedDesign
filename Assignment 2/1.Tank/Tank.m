function echo = Tank(R,d)
if (d > 3*R)
    echo = "Overtop";return
end
echo = pi * ( max(0,min(R^3,d^3)/3) + R^2*max(0,d-R) );
end