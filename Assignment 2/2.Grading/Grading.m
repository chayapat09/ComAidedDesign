function grade = Grading(Score)
G =  ['F' ,'D' ,'C' ,'B' ,'A' ];
nx = [60 , 10 , 10 , 10 , 10 ];
function out = g(Score,d)
    if (Score - nx(d) < 0 || d == length(nx))
        out = G(d);return
    end
    out = g(Score - nx(d),d+1);
end
grade = g(Score,1);
end