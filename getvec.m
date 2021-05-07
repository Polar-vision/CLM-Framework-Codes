function [vec_x, vec_y,x,y] = getvec(m)
%UNTITLED5 此处显示有关此函数的摘要
%   此处显示详细说明
x=rand(1,m)*10-5;
y=rand(1,m)*10-5;

% x(1)=0;
% y(1)=4*sqrt(3)/2;
% x(2)=4;
% y(2)=-4*sqrt(3)/2;
% x(3)=-4;
% y(3)=-4*sqrt(3)/2;
% x(4)=2;
% y(4)=-2;
%五边形
% x(1)=0;
% y(1)=4*cos(3*pi/10);
% x(2)=4*sin(3*pi/10);
% y(2)=0;
% x(3)=4/2;
% y(3)=-4*cos(pi/10);
% x(4)=-4/2;
% y(4)=-4*cos(pi/10);
% x(5)=-4*sin(3*pi/10);
% y(5)=0;
vec_x=[];
vec_y=[];
for i=1:m-1
    vec_x(i)=x(i+1)-x(1);
    vec_y(i)=y(i+1)-y(1);
end


end

