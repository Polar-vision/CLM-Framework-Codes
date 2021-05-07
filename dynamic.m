function dynamic(k,k1,gcf,aviobj)
xlabel('-5 \leq Gene 1 \leq 5','FontName','Tahoma','FontWeight','bold','FontSize',24)
ylabel('-5 \leq Gene 2 \leq 5','FontName','Tahoma','FontWeight','bold','FontSize',24)
%zlabel('\it f\rm(\itx\rm)','FontName','Times New Roman')
axis([-10 10 -10 10 0 100])
caxis([-90 90])
set(gca,'linewidth',2,'fontsize',24,'fontweight','bold');
grid on;
box on;
%获取当前画面
F = getframe(gcf);
%加入avi对象中
writeVideo(aviobj,F);
%转成gif图片,只能用256色
im = frame2im(F);
[I,map] = rgb2ind(im,256);
%写入 GIF89a 格式文件   
if (k==1)
%     if (k1==1)
        imwrite(I,map,'Random_2P1.gif','GIF', 'Loopcount',inf,'DelayTime',0.01);
%     end
%     if(k1~=1)
%         imwrite(I,map,'Random_2P.gif','GIF','WriteMode','append','DelayTime',0.01);
%     end
else
     imwrite(I,map,'Random_2P1.gif','GIF','WriteMode','append','DelayTime',0.01);
end  