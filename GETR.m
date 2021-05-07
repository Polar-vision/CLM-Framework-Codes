function [min_1,max_1] = GETR(a2)
%UNTITLED6 此处显示有关此函数的摘要
%   此处显示详细说明
a=-0.5-a2;
b=1.5-a2;
if a>-0.5
    min_1=a;
else
    min_1=-0.5;
end
if b<1.5
    max_1=b;
else
    max_1=1.5;
end

end

