% 2018380038_Amirbek_Raimov - Histogram Equalization
clearvars
close all
clc

load desiredHistogram.mat
phobos = imread("phobos.bmp");

figure('Name','Histogram matching','NumberTitle','off');

subplot(1,5,1);
imshow(phobos);
title("Original image");
subplot(1,5,2);
phobos_he = histeq(phobos);
imshow(phobos_he);
title("Histogram equalization - histeq");
subplot(1,5,3);
phobos_he = histeq(phobos,desiredHistogram);
imshow(phobos_he);
title("Histogram matching");
subplot(1,5,4);
adjusted_phobos = imadjust(phobos);
imshow(adjusted_phobos);
title("Image after stretching");
subplot(1,5,5);
phobos_clahe = adapthisteq(phobos);
imshow(phobos_clahe);
title("Histogram equalization - CLAHE");
