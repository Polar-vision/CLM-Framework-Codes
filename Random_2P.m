function Random_2P(k,gcf,aviobj)
[v_x,v_y,x,y]=getvec(2)
i=0;
x_new=[];
y_new=[];



for a2=-0.5:0.1:1.5
    i=i+1;
    x_new(i)=a2*v_x(1)+x(1);
    y_new(i)=a2*v_y(1)+y(1);
%     scatter(x_new,y_new,'.','b');
    plot(x,y,'g','linewidth',2);
    plot(x,y,'+','MarkerFaceColor','red','MarkerEdgeColor','r','Markersize',20,'LineWidth',2);
    x_start=x_new(1);
    y_start=y_new(1);
    x_end=x_new(i);
    y_end=y_new(i);
%     dynamic(k,i,gcf,aviobj);
end 

line([x_start x_end],[y_start y_end],'linewidth',2,'color','b');
dynamic(k,i,gcf,aviobj);