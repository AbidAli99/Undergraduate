% 2018380038_Amirbek_Raimov - Histogram Equalization
function LUT_he(image,reencoding)
rescaled_reencoding = rescale(reencoding,0,255);
rescaled_reencoding = uint8(rescaled_reencoding);
A = intlut(image,rescaled_reencoding);
subplot(1,3,1);
plot(rescaled_reencoding);
title("reencoding");
subplot(1,3,2);
imshow(image);
title("Original image");
subplot(1,3,3);
imshow(A);
title("Image after histogram equalization");

figure(68)
[H,x] = imhist(A);

C = cumsum(H);
k = max(C)/max(H);
C2 = C/k;

hold on
plot(x,H);
plot(x,C2);
title("Histogram and cumulative histogram after equalization");
end