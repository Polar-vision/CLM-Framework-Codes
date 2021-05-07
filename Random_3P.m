function Random_3P(k,gcf,aviobj)
[v_x,v_y,x,y]=getvec(3)
i=0;
x_new=[];
y_new=[];
k1=0;
x_s=[];
y_s=[];
x_e=[];
y_e=[];
c1='a2:';
c2='a3:';

for a2=-0.5:0.5:1.5
    [a3_min,a3_max]=GETR(a2);
    i=0;
    k1=k1+1;
    
    for a3=a3_min:0.5:a3_max
            i=i+1;
            x_new(i)=a2*v_x(1)+a3*v_x(2)+x(1);
            y_new(i)=a2*v_y(1)+a3*v_y(2)+y(1);
            scatter(x_new,y_new,'.','b');
            fill(x,y,'g','linewidth',2);
            plot(x,y,'+','MarkerFaceColor','red','MarkerEdgeColor','r','Markersize',20,'LineWidth',2);
            x_start=x_new(1);
            y_start=y_new(1);
            x_end=x_new(i);
            y_end=y_new(i);
    end 
    x_s(k1)=x_start;
    x_e(k1)=x_end;
    y_s(k1)=y_start;
    y_e(k1)=y_end;
    dynamic(k,k1,gcf,aviobj);
end
line([x_s(1) x_e(1)],[y_s(1) y_e(1)],'linewidth',2,'color','r');
line([x_s(k1) x_e(k1)],[y_s(k1) y_e(k1)],'linewidth',2,'color','r');
for j=1:1:k1-1
    line([x_s(j) x_s(j+1)],[y_s(j) y_s(j+1)],'linewidth',2,'color','r');
    line([x_e(j) x_e(j+1)],[y_e(j) y_e(j+1)],'linewidth',2,'color','r');
end
dynamic(k,k1,gcf,aviobj);