function Random_5P(k,gcf,aviobj)

[v_x,v_y,x,y]=getvec(5);
i=0;
x_new=[];
y_new=[];
k1=0;
k2=0;
k3=0;
x_s=[;;];
y_s=[;;];
x_e=[;;];
y_e=[;;];
kk2=[;];
kk3=[];
c1='a2:';
c2='a3:';
c3='a4:';
c4='a5:';

for a2=-0.5:0.5:1.5
    [a3_min,a3_max]=GETR(a2);
    k1=k1+1;
    k2=0;
    for a3=a3_min:0.5:a3_max
        [a4_min,a4_max]=GETR(a2+a3);
        k2=k2+1;
        k3=0;
        for a4=a4_min:0.5:a4_max
            [a5_min,a5_max]=GETR(a2+a3+a4);
            i=0;
            k3=k3+1;
            for a5=a5_min:0.5:a5_max
                i=i+1;
                x_new(i)=a2*v_x(1)+a3*v_x(2)+a4*v_x(3)+a5*v_x(4)+x(1);
                y_new(i)=a2*v_y(1)+a3*v_y(2)+a4*v_y(3)+a5*v_y(4)+y(1);
%                 scatter(x_new,y_new,'b','linewidth',2);
                scatter(x_new,y_new,'.','b');
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
            x_s(k1,k2,k3)=x_start;
            x_e(k1,k2,k3)=x_end;
            y_s(k1,k2,k3)=y_start;
            y_e(k1,k2,k3)=y_end;
            dynamic(k,k1,gcf,aviobj);
        end
        kk2(k1,k2)=k3;
    end
    kk3(k1)=k2;
end
n=0;
x_se=[];
y_se=[];
for j=1:1:k1
    for m=1:1:kk3(j)
        for h=1:1:kk2(j,m)
            n=n+1;
            x_se(n)=x_s(j,m,h);
            y_se(n)=y_s(j,m,h);
        end
    end
end
for j=1:1:k1
    for m=1:1:kk3(j)
        for h=1:1:kk2(j,m)
            n=n+1;
            x_se(n)=x_e(j,m,h);
            y_se(n)=y_e(j,m,h);
        end
    end
end

x=x_se';
y=y_se';
dt = delaunayTriangulation(x,y);
kk = convexHull(dt);
% plot(x,y,'o','MarkerFaceColor','red');
plot(x(kk), y(kk), 'r','linewidth',2);
dynamic(k,k1,gcf,aviobj);
end