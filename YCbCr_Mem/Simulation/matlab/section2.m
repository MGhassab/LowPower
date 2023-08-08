%% Mahdi Ghassab
clc;
clear
close all
% 
%               
% %% Read Image & Make RGB Color Matrix
imgY = imread('Y_result_Black.png');
imgCb = imread('Cb_result_Black.png');
imgCr = imread('Cr_result_Black.png');


R_img = imgY(:,:,:);
G_img = imgCb(:,:,:);
B_img = imgCb(:,:,:);

 edge_img = cat(3, R_img, G_img,B_img);


 imshow(edge_img);


% RGB = imread("HPIM1231.jpg");
% YCBCR = rgb2ycbcr(RGB);
% imshow(RGB);
% title("Image in RGB Color Space");
% imshow(YCBCR);
% title("Image in YCbCr Color Space");
% Y_img = YCBCR(:,:,1);
% Cb_img = YCBCR(:,:,2);
% Cr_img = YCBCR(:,:,3);
% dlmwrite('Y_img.txt',Y_img);
% dlmwrite('Cb_img.txt',Cb_img);
% dlmwrite('Cr_img.txt',Cr_img);