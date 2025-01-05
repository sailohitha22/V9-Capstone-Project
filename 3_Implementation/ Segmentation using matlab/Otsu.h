% Read the image
I = imread('Tomato.jpg');
imshow(I);
title('Original Image');
% Apply imadjust to each RGB channel separately for contrast enhancement
I_adj = I;  % Create a copy of the original image
for k = 1:3
    I_adj(:,:,k) = imadjust(I(:,:,k));  % Adjust contrast for each channel
end
% Display the adjusted image
figure;
imshow(I_adj);
title('Contrast-Adjusted Image');
% Convert RGB to Luminance (L) for edge detection and Saturation (S) for segmentation
L = rgb2gray(I_adj);  % Luminance channel for edge detection
% Recalculate Saturation (S) after contrast adjustment
R = double(I_adj(:,:,1)) / 255;
G = double(I_adj(:,:,2)) / 255;
B = double(I_adj(:,:,3)) / 255;
Cmax = max(max(R, G), B);
Cmin = min(min(R, G), B);
S = Cmax - Cmin; % Saturation channel for segmentation
% Perform Otsu's thresholding on Saturation (S) channel to segment the diseased part
threshold = graythresh(S);  % Otsu's method to determine optimal threshold
diseasedPart = imbinarize(S, threshold * 0.85);  % Apply slightly lower threshold
% Invert the binary mask if necessary (darker regions assumed to be diseased)
diseasedPart = ~diseasedPart;
% Refine the mask using morphological operations
diseasedPart = imopen(diseasedPart, strel('disk', 3));  % Remove small noise
diseasedPart = imclose(diseasedPart, strel('disk', 5));  % Fill small gaps
% Display the binary mask (diseased part)
figure;
imshow(diseasedPart);
title('Binary Mask of Diseased Part (Otsu Method)');
% Separate the diseased part and make the background white
I_diseased_only = I_adj; % Copy of the adjusted image
% Set the healthy areas to white (255 for all RGB channels)
for k = 1:3
    temp_channel = I_diseased_only(:,:,k);
    temp_channel(~diseasedPart) = 255;  % Set non-diseased parts to white
    I_diseased_only(:,:,k) = temp_channel;
end
% Display the separated diseased part with white background
figure;
imshow(I_diseased_only);
title('Separated Diseased Part with White Background');
% Calculate statistics for the overall leaf (entire image)
meanValues_overall = mean(I, [1 2]);  % Mean across rows and columns
medianValues_overall = median(I, [1 2]);  % Median across rows and columns
stdValues_overall = std(double(I), 0, [1 2]);  % Standard deviation across rows and columns
disp('Overall Leaf Statistics:');
disp('Mean Values:');
disp(meanValues_overall);
disp('Median Values:');
disp(medianValues_overall);
disp('Standard Deviation Values:');
disp(stdValues_overall);
% Calculate statistics for the diseased part only
diseasedArea = sum(diseasedPart(:));  % Number of pixels in diseased area
meanValues_diseased = mean(I(repmat(diseasedPart, [1 1 3])));  % Mean values for diseased area
medianValues_diseased = median(I(repmat(diseasedPart, [1 1 3])));  % Median values for diseased area
stdValues_diseased = std(double(I(repmat(diseasedPart, [1 1 3]))));  % Std dev for diseased area
disp(['Diseased Area (in pixels): ', num2str(diseasedArea)]);
disp('Mean Values of Diseased Area:');
disp(meanValues_diseased);
disp('Median Values of Diseased Area:');
disp(medianValues_diseased);
disp('Standard Deviation of Diseased Area:');
disp(stdValues_diseased);
% Apply Sobel edge detection for overall leaf and diseased part
BW_sobel_overall = edge(L, 'sobel');  % Sobel edge detection on overall leaf
L_diseased = L;  % Copy of Luminance channel for edge detection on diseased part
L_diseased(~diseasedPart) = 255;  % Set healthy areas to white in the Luminance channel
BW_sobel_diseased = edge(L_diseased, 'sobel');  % Sobel edge detection on diseased part
% Apply Canny edge detection for overall leaf and diseased part
BW_canny_overall = edge(L, 'canny', [0.05 0.2]);  % Canny edge detection on overall leaf
BW_canny_diseased = edge(L_diseased, 'canny', [0.05 0.2]);  % Canny edge detection on diseased part
% Display edge detection results for both overall leaf and diseased part
figure;
tiledlayout(2, 2);
% Display Sobel edge detection on overall leaf
nexttile;
imshow(BW_sobel_overall);
title('Sobel Edge Detection on Overall Leaf');
% Display Sobel edge detection on diseased part
nexttile;
imshow(BW_sobel_diseased);
title('Sobel Edge Detection on Diseased Part');

% Display Canny edge detection on overall leaf
nexttile;
imshow(BW_canny_overall);
title('Canny Edge Detection on Overall Leaf');

% Display Canny edge detection on diseased part
nexttile;
imshow(BW_canny_diseased);
title('Canny Edge Detection on Diseased Part');

% Interactive selection of pixel values for overall leaf and diseased part
[x, y] = ginput(5);  % Get 5 points from the figure
for i = 1:length(x)
    % Get RGB values for the selected points
    row = round(y(i));
    col = round(x(i));
    
    pixelValue_overall = I(row, col, :);  % Get RGB values for overall leaf
    pixelValue_diseased = I_diseased_only(row, col, :);  % Get RGB values for diseased part

    disp(['Pixel Value at (', num2str(row), ', ', num2str(col), ') in Overall Leaf: ', num2str(pixelValue_overall')]);
    disp(['Pixel Value at (', num2str(row), ', ', num2str(col), ') in Diseased Part: ', num2str(pixelValue_diseased')]);
end
