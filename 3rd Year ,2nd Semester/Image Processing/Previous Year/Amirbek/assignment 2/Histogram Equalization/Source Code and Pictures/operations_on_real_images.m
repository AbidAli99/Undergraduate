% 2018380038_Amirbek_Raimov - Histogram Equalization
clearvars
close all
clc

hist2 = imread("hist2.bmp");
hist3 = imread("hist3.bmp");
hist4 = imread("hist4.bmp");

figure('Name','Real images','NumberTitle','off');
subplot(3,4,1);
imshow(hist2);
title("Original image");

subplot(3,4,2);
adjusted_hist2 = imadjust(hist2);
imshow(adjusted_hist2);
title("Image after stretching");

subplot(3,4,3);
hist2_he = histeq(hist2);
imshow(hist2_he);
title("Histogram equalization - histeq");

subplot(3,4,4);
hist2_clahe = adapthisteq(hist2);
imshow(hist2_clahe);
title("Histogram equalization - CLAHE");

subplot(3,4,5);
imshow(hist3);
title("Original image");

subplot(3,4,6);
adjusted_hist3 = imadjust(hist3);
imshow(adjusted_hist3);
title("Image after stretching");

subplot(3,4,7);
hist3_he = histeq(hist3);
imshow(hist3_he);
title("Histogram equalization - histeq");

subplot(3,4,8);
hist3_clahe = adapthisteq(hist3);
imshow(hist3_clahe);
title("Histogram equalization - CLAHE");

subplot(3,4,9);
imshow(hist4);
title("Original image");

subplot(3,4,10);
adjusted_hist4 = imadjust(hist4);
imshow(adjusted_hist4);
title("Image after stretching");

subplot(3,4,11);
hist4_he = histeq(hist4);
imshow(hist4_he);
title("Histogram equalization - histeq");

subplot(3,4,12);
hist4_clahe = adapthisteq(hist4);
imshow(hist4_clahe);
title("Histogram equalization - CLAHE");
