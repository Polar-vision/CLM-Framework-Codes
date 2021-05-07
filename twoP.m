function twoP()
%UNTITLED9 此处显示有关此函数的摘要

close all; clear all;
clc;
clf;
set(gcf,'color','w')
%创建avi文件对象
aviobj = VideoWriter('search_space-2p.avi','Uncompressed AVI');
open(aviobj);
%动画部分代码
hold on;
%fig=figure;
cla;
%   此处显示详细说明
[v_x,v_y,x,y]=getvec(2)

i=0;
x_new=[];
y_new=[];

c1='a2:';

for a2=-0.5:0.1:1.5
    i=i+1;
    cla;
    text(-2,11,[c1,num2str(a2)],'FontName','Tahoma','FontWeight','bold','FontSize',18);
    x_new(i)=a2*v_x(1)+x(1);
    y_new(i)=a2*v_y(1)+y(1);
%     plot(x_new,y_new,'b','linewidth',2);%'Color',[rand(),0.7,rand()]
scatter(x_new,y_new,'.','b');
    plot(x,y,'g','linewidth',2);
    plot(x,y,'+','MarkerFaceColor','red','MarkerEdgeColor','r','Markersize',20,'LineWidth',2);
    dynamic(i,i,gcf,aviobj);
    x_start=x_new(1);
    y_start=y_new(1);
    x_end=x_new(i);
    y_end=y_new(i);
end

line([x_start x_end],[y_start y_end],'linewidth',2,'color','b');
dynamic(i,i,gcf,aviobj);
close(gcf);
%关闭avi对象
close(aviobj);


