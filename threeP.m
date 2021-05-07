function threeP()
%UNTITLED9 此处显示有关此函数的摘要

close all; clear all;
clc;
clf;
set(gcf,'color','w')
%创建avi文件对象
aviobj = VideoWriter('search_space-3p.avi','Uncompressed AVI');
open(aviobj);
%动画部分代码
hold on;
%fig=figure;
cla;
%   此处显示详细说明
[v_x,v_y,x,y]=getvec(3)

i=0;
x_new=[];
y_new=[];
k=0;
x_s=[];
y_s=[];
x_e=[];
y_e=[];
c1='a2:';
c2='a3:';
for a2=-0.5:0.5:1.5
    [a3_min,a3_max]=GETR(a2);
    i=0;
    k=k+1;
    
    for a3=a3_min:0.5:a3_max
            i=i+1;
            cla;
            text(-2,11,[c1,num2str(a2)],'FontName','Tahoma','FontWeight','bold','FontSize',18);
            text(5,11,[c2,num2str(a3)],'FontName','Tahoma','FontWeight','bold','FontSize',18);
            x_new(i)=a2*v_x(1)+a3*v_x(2)+x(1);
            y_new(i)=a2*v_y(1)+a3*v_y(2)+y(1);
            plot(x_new,y_new,'b','linewidth',2);%'Color',[rand(),0.7,rand()]
            fill(x,y,'g','linewidth',2);
            plot(x,y,'+','MarkerFaceColor','red','MarkerEdgeColor','r','Markersize',20,'LineWidth',2);
            dynamic(k,aviobj);
            x_start=x_new(1);
            y_start=y_new(1);
            x_end=x_new(i);
            y_end=y_new(i);
    end
    x_s(k)=x_start;
    x_e(k)=x_end;
    y_s(k)=y_start;
    y_e(k)=y_end;

    
end
line([x_s(1) x_e(1)],[y_s(1) y_e(1)],'linewidth',2,'color','b');
line([x_s(k) x_e(k)],[y_s(k) y_e(k)],'linewidth',2,'color','b');
for j=1:1:k-1
    line([x_s(j) x_s(j+1)],[y_s(j) y_s(j+1)],'linewidth',2,'color','b');
    line([x_e(j) x_e(j+1)],[y_e(j) y_e(j+1)],'linewidth',2,'color','b');
end
dynamic(k,aviobj);
close(gcf);
%关闭avi对象
close(aviobj);


