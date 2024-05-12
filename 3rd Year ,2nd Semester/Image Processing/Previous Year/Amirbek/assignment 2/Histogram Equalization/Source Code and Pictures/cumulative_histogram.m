% 2018380038_Amirbek_Raimov - Histogram Equalization
clearvars
close all
clc

image = imread("board.png");

figure('Name','Cumulative histogram before stretching','NumberTitle','off');
h = fspecial('average',hsize);
Cfull = conv2(3,3);

title("Cumulative and default histogram");
