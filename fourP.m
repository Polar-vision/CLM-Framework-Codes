function fourP()
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
[v_x,v_y,x,y]=getvec(4);
i=0;
x_new=[];
y_new=[];
k1=0;
k2=0;
x_s=[;];
y_s=[;];
x_e=[;];
y_e=[;];
kk2=[];

c1='a2:';
c2='a3:';
c3='a4:';
for a2=-0.5:0.5:1.5
    [a3_min,a3_max]=GETR(a2);
    k1=k1+1;
    k2=0;
    for a3=a3_min:0.5:a3_max
        i=0;
        k2=k2+1;
        [a4_min,a4_max]=GETR(a2+a3);
        for a4=a4_min:0.5:a4_max
            i=i+1;
            cla;
            text(-6,11,[c1,num2str(a2)],'FontName','Tahoma','FontWeight','bold','FontSize',18);
            text(0,11,[c2,num2str(a3)],'FontName','Tahoma','FontWeight','bold','FontSize',18);
            text(6,11,[c3,num2str(a4)],'FontName','Tahoma','FontWeight','bold','FontSize',18);
            x_new(i)=a2*v_x(1)+a3*v_x(2)+a4*v_x(3)+x(1);
            y_new(i)=a2*v_y(1)+a3*v_y(2)+a4*v_y(3)+y(1);
             plot(x_new,y_new,'b','linewidth',2);%'Color',[rand(),0.7,rand()]
%              scatter(x_new,y_new,'.','b');
             if((a2==1.5)&&(a3==a3_max||a3>a3_max)&&(a4==a4_max||a4>a4_max))
                 cla;
             end
             xx=x';
             yy=y';
             dt = delaunayTriangulation(xx,yy);
             k = convexHull(dt);
             fill(xx(k),yy(k),'g','linewidth',2);
            plot(x,y,'+','MarkerFaceColor','red','MarkerEdgeColor','r','Markersize',20,'LineWidth',2);
            x_start=x_new(1);
            y_start=y_new(1);
            x_end=x_new(i);
            y_end=y_new(i);
        end
        x_s(k1,k2)=x_start;
        x_e(k1,k2)=x_end;
        y_s(k1,k2)=y_start;
        y_e(k1,k2)=y_end;
        dynamic(k1,aviobj);
    end
    kk2(k1)=k2;
end
n=0;
x_se=[];
y_se=[];
for j=1:1:k1
    for m=1:1:kk2(j)
        n=n+1;
        x_se(n)=x_s(j,m);
        y_se(n)=y_s(j,m);
    end
end
for j=1:1:k1
    for m=1:1:kk2(j)
        n=n+1;
        x_se(n)=x_e(j,m);
        y_se(n)=y_e(j,m);
    end
end

x=x_se';
y=y_se';
dt = delaunayTriangulation(x,y);
k = convexHull(dt);
% plot(x,y,'o','MarkerFaceColor','red');
plot(x(k), y(k), 'b','linewidth',2);
dynamic(k1,aviobj);
close(gcf);
%关闭avi对象
close(aviobj);

