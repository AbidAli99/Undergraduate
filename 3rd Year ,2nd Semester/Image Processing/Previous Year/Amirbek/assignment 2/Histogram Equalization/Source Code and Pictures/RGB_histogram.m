% 2018380038_Amirbek_Raimov - Histogram Equalization
clearvars
close all
clc

lena = imread("lenaRGB.bmp");

figure('Name','RGB histogram','NumberTitle','off');
lenaR = lena(:,:,1);
lenaG = lena(:,:,2);
lenaB = lena(:,:,3);
subplot(1,3,1);
imhist(lenaR);
title("Red");
subplot(1,3,2);
imhist(lenaG);
title("Green");
subplot(1,3,3);
imhist(lenaB);
title("Blue");

figure('Name','RGB histogram equalization','NumberTitle','off');
lenaR = histeq(lenaR);
lenaG = histeq(lenaG);
lenaB = histeq(lenaB);
lena_eq = lena;
lena_eq(:,:,1) = lenaR;
lena_eq(:,:,2) = lenaG;
lena_eq(:,:,3) = lenaB;
subplot(1,2,1);
imshow(lena);
title("Original image");
subplot(1,2,2);
imshow(lena_eq);
title("Image after equalization");

figure('Name','HSV','NumberTitle','off');
lena_hsv = rgb2hsv(lena);
lena_h = lena_hsv(:,:,1);
lena_s = lena_hsv(:,:,2);
lena_v = lena_hsv(:,:,3);
subplot(2,3,1);
imhist(lena_h);
title("H");
subplot(2,3,2);
imhist(lena_s);
title("S");
subplot(2,3,3);
imhist(lena_v);
title("V");

lena_hsv_eq = lena_hsv;
lena_v = histeq(lena_v);
lena_hsv_eq(:,:,1) = lena_h;
lena_hsv_eq(:,:,2) = lena_s;
lena_hsv_eq(:,:,3) = lena_v;

RGB = hsv2rgb(lena_hsv_eq);
subplot(2,3,4:6);
imshow(RGB);
title("HDV equalization");