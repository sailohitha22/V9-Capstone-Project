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
% Reshape the Saturation (S) channel for k-means
S_reshaped = reshape(S, [], 1);
% Initialize k-means parameters
numClusters = 2;
maxIterations = 10;  % Maximum number of iterations
centroids = [min(S_reshaped); max(S_reshaped)];  % Initial centroids
% Perform simple k-means clustering
for iter = 1:maxIterations
    % Assign each point to the nearest centroid
    distances = abs(S_reshaped - centroids');
    [~, idx] = min(distances, [], 2);
    
    % Update centroids
    for k = 1:numClusters
        centroids(k) = mean(S_reshaped(idx == k));
    end
end
% Reshape the clustered labels back to the original image size
segmentedImage = reshape(idx, size(S));
% Determine which cluster represents the diseased part
diseasedCluster = find(centroids == min(centroids));
% Create a binary mask for the diseased part
diseasedPart = segmentedImage == diseasedCluster;
% Refine the mask using morphological operations
diseasedPart = imopen(diseasedPart, strel('disk', 3));  % Remove small noise
diseasedPart = imclose(diseasedPart, strel('disk', 5));  % Fill small gaps
% Display the binary mask (diseased part)
figure;
imshow(diseasedPart);
title('Binary Mask of Diseased Part (Simple K-Means)');
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
% Calculate statistics for the overall image (overall leaf)
meanValues_overall = mean(I_adj, [1 2]);  % Mean across rows and columns
medianValues_overall = median(I_adj, [1 2]);  % Median across rows and columns
stdValues_overall = std(double(I_adj), 0, [1 2]);  % Standard deviation across rows and columns
disp('Overall Image Statistics:');
disp('Mean Values:');
disp(meanValues_overall);
disp('Median Values:');
disp(medianValues_overall);
disp('Standard Deviation Values:');
disp(stdValues_overall);
% Calculate statistics for the diseased part only
diseasedArea = sum(diseasedPart(:));  % Number of pixels in diseased area
% Extract diseased part's pixel values for each channel and convert to double
diseasedPixels_R = double(I_adj(:,:,1));
diseasedPixels_G = double(I_adj(:,:,2));
diseasedPixels_B = double(I_adj(:,:,3));
% Set non-diseased pixels to NaN so they won't affect the mean and std calculation
diseasedPixels_R(~diseasedPart) = NaN;
diseasedPixels_G(~diseasedPart) = NaN;
diseasedPixels_B(~diseasedPart) = NaN;
% Calculate statistics for diseased pixels, excluding NaN values
meanValues_diseased = [mean(diseasedPixels_R(~isnan(diseasedPixels_R))), ...
                       mean(diseasedPixels_G(~isnan(diseasedPixels_G))), ...
                       mean(diseasedPixels_B(~isnan(diseasedPixels_B)))];
medianValues_diseased = [median(diseasedPixels_R(~isnan(diseasedPixels_R))), ...
                         median(diseasedPixels_G(~isnan(diseasedPixels_G))), ...
                         median(diseasedPixels_B(~isnan(diseasedPixels_B)))];

stdValues_diseased = [std(diseasedPixels_R(~isnan(diseasedPixels_R))), ...
                      std(diseasedPixels_G(~isnan(diseasedPixels_G))), ...
                      std(diseasedPixels_B(~isnan(diseasedPixels_B)))];
% Display statistics for the diseased part
disp(['Diseased Area (in pixels): ', num2str(diseasedArea)]);
disp('Mean Intensity of Diseased Part:');
disp(meanValues_diseased);
disp('Median Intensity of Diseased Part:');
disp(medianValues_diseased);
disp('Standard Deviation of Diseased Part:');
disp(stdValues_diseased);
% Perform Sobel edge detection on the overall leaf and diseased part
BW_sobel_overall = edge(L, 'sobel');  % Sobel edge detection on overall leaf
L_diseased = L;  % Copy of Luminance channel for edge detection on diseased part
L_diseased(~diseasedPart) = 255;  % Set healthy areas to white in the Luminance channel
BW_sobel_diseased = edge(L_diseased, 'sobel');  % Sobel edge detection on diseased part
% Display Sobel edge detection results
figure;
tiledlayout(1, 2);
nexttile;
imshow(BW_sobel_overall);
title('Sobel Edge Detection on Overall Leaf');
nexttile;
imshow(BW_sobel_diseased);
title('Sobel Edge Detection on Diseased Part');

