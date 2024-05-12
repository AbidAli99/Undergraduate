% 2018380038_Amirbek_Raimov - Histogram Equalization
clearvars
close all
clc

hist1 = imread("hist1.bmp");

figure('Name','Histogram equalization - LUT function','NumberTitle','off');
[H,x] = imhist(hist1);
C = cumsum(H);
LUT_he(hist1, C);

figure('Name','Histogram equalization - histeq & adapthisteq','NumberTitle','off');
subplot(2,2,1:2);
imshow(hist1);
title("Original image");
subplot(2,2,3);
hist1_he = histeq(hist1,256);
imshow(hist1_he);
title("Image after histogram equalization - histeq");

subplot(2,2,4);
hist1_adapthisteq = adapthisteq(hist1);
imshow(hist1_adapthisteq);
title("Image after histogram equalization - adapthisteq");