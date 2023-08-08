%% Mahdi Ghassab
clc;
clear
close all
%% Filter Matrix
average_filter = [ 1/9,1/9,1/9;
                   1/9,1/9,1/9;
                   1/9,1/9,1/9; ];
              
edge_filter = [  0,-1, 0;
                -1, 4,-1;
                 0,-1, 0; ];
              
%% Read Image & Make RGB Color Matrix
img = imread('elaine_16.png');
%subplot(2,3,1);
% imshow(img);
% title('Image')

 R_img = img(:,:,1);
  imshow(R_img);
% G_img = img(:,:,2);
% B_img = img(:,:,3);

%% Make gray_scale & noisy image(addition)
% img_grey = rgb2gray(img);
% subplot(2,3,2);
% imshow(img_grey);
% 
% img_noise = imnoise(img_grey,'salt & pepper');
% subplot(2,3,3);
% imshow(img_noise);
%% Average Filter & Edge Filter on Each color
% average_R = uint8(filter2(average_filter,R_img));
 edge_R = filter2(edge_filter,R_img);
% 
% average_G = uint8(filter2(average_filter,G_img));
% edge_G = filter2(edge_filter,G_img);
% 
% average_B = uint8(filter2(average_filter,B_img));
% edge_B = filter2(edge_filter,B_img);
%% Make final images and show them
% average_img = cat(3, average_R, average_G,average_B);
% edge_img = cat(3, edge_R, edge_G,edge_B);
% 
% subplot(2,3,2);
% imshow(average_img);
% title('Average')
%  
% subplot(2,3,3);
% imshow(edge_img);
% title('Edge')
%% Save Data on text file
 %dlmwrite('R_img.txt',R_img);
  dlmwrite('edgeR.txt',edge_R);
  imshow(edge_R);
% dlmwrite('G_img.txt',G_img);
% dlmwrite('B_img.txt',B_img);
% A = dlmread('kelidestan.txt')
