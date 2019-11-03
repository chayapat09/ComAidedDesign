x = 0:0.2:10;
i = 1;
y(1:length(x)) = 0;
while i <= length(x)
    y(i) = Beam(x(i));
    i = i + 1;
end
plot(x,y)
