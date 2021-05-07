function avi()
%UNTITLED4 此处显示有关此函数的摘要
%   此处显示详细说明
close all; clear all;
clc;
clf;
%创建avi文件对象
aviobj = VideoWriter('1.avi','Uncompressed AVI');
open(aviobj);
set(gcf,'color','w')

%动画部分代码
hold on;
%fig=figure;
for k=1:1:20
    cla;
    Random_2P(k,gcf,aviobj);
% %   fourP(4);
% % fiveP(5);
%     %scatter3(M(1+100*(k-1):100*k,1),M(1+100*(k-1):100*k,2),M(1+100*(k-1):100*k,2),'r','*')
%     %legend('problem','potential solutions','location','best','Orientation','horizontal')
%     xlabel('-3 \leq Gene 1 \leq 3','FontName','Tahoma','FontWeight','bold','FontSize',24)
%     ylabel('-3 \leq Gene 2 \leq 3','FontName','Tahoma','FontWeight','bold','FontSize',24)
%     %zlabel('\it f\rm(\itx\rm)','FontName','Times New Roman')
%     axis([-10 10 -10 10 0 100])
%     caxis([-90 90])
%     set(gca,'linewidth',2,'fontsize',24,'fontweight','bold');
%     grid on;
%     box on;
%     %获取当前画面
%     F = getframe(gcf);
%     %加入avi对象中
%     writeVideo(aviobj,F);
%       
%     %转成gif图片,只能用256色
%     im = frame2im(F);
%     [I,map] = rgb2ind(im,256);
%     %写入 GIF89a 格式文件   
%     if k == 1;
%         imwrite(I,map,'search_space-5p_comb.gif','GIF', 'Loopcount',inf,'DelayTime',0.001);
%     else
%         imwrite(I,map,'search_space-5p_comb.gif','GIF','WriteMode','append','DelayTime',0.001);
%     end  
end

close(gcf);
%关闭avi对象
close(aviobj);
end

