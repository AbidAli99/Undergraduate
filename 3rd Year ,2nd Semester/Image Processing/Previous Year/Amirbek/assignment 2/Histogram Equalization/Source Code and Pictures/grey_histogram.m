% 2018380038_Amirbek_Raimov - Histogram Equalization
clearvars
close all
clc

lena1 = imread("lena1.bmp");
lena2 = imread("lena2.bmp");
lena3 = imread("lena3.bmp");
lena4 = imread("lena4.bmp");
hist1 = imread("hist1.bmp");

figure('Name','Greyscale histograms','NumberTitle','off');
subplot(2,4,1);
imshow(lena1);
subplot(2,4,2);
imshow(lena2);
subplot(2,4,3);
imshow(lena3);
subplot(2,4,4);
imshow(lena4);

subplot(2,4,5);
imhist(lena1,256);
subplot(2,4,6);
imhist(lena2,256);
subplot(2,4,7);
imhist(lena3,256);
subplot(2,4,8);
imhist(lena4,256);

figure('Name','Greyscale histogram - stretching','NumberTitle','off');
subplot(2,2,1);
imshow(hist1);
subplot(2,2,3);
imhist(hist1,256);
subplot(2,2,2);
adjusted_hist1 = imadjust(hist1);
imshow(adjusted_hist1);
subplot(2,2,4);
imhist(adjusted_hist1,256);