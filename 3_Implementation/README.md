# Segmentation of Diseased Plant Leaves using MATLAB

## Introduction
This project focuses on detecting diseased parts of a plant leaf, specifically a tomato leaf, using image processing techniques. The system uses two methods for segmentation: **K-Means Clustering** and **Otsu's Thresholding**, along with edge detection to identify diseased regions. It also computes statistical information about the diseased and healthy parts of the leaf.

---

## Prerequisites
- **MATLAB** (compatible with Image Processing Toolbox)
- Input image: `Tomato.jpg` (or any other plant leaf image)

---

## Workflow Overview

### 1. Read and Display the Image
- The original image (`Tomato.jpg`) is loaded and displayed for reference.

### 2. Contrast Enhancement
- Each RGB channel of the image is adjusted individually to enhance contrast using the `imadjust` function.

### 3. Color Channel Processing
- The **Luminance (L)** channel is extracted for edge detection.
- The **Saturation (S)** channel is recalculated for segmentation purposes.

---

### **K-Means Clustering for Segmentation**
1. Saturation channel values are reshaped and processed using K-Means clustering.
2. Two clusters are created:
   - One represents healthy regions.
   - The other represents diseased regions.
3. Morphological operations refine the binary mask of the diseased part.
4. The diseased part is extracted and displayed against a white background.
5. Statistical information (mean, median, and standard deviation) is calculated for:
   - The overall image
   - The diseased region

---

### **Otsu's Thresholding for Segmentation**
1. Otsu's method determines an optimal threshold for the Saturation channel.
2. A binary mask is created and refined with morphological operations.
3. The diseased part is displayed with a white background.
4. Statistical information (mean, median, and standard deviation) is calculated for:
   - The overall image
   - The diseased region

---

### **Edge Detection**
- **Sobel Edge Detection**:
  - Applied to both the overall image and the diseased part.
- **Canny Edge Detection**:
  - Applied for additional detail on edge structures in both regions.

---

## Outputs
- **Images**:
  - Original Image
  - Contrast-Adjusted Image
  - Binary Mask of Diseased Part (K-Means and Otsu)
  - Diseased Part Highlighted on a White Background
  - Sobel and Canny Edge Detection Results
- **Statistics**:
  - Overall Leaf (mean, median, standard deviation)
  - Diseased Area (mean, median, standard deviation, pixel count)

---

## How to Run
1. Place the `Tomato.jpg` image in the MATLAB working directory.
2. Copy and paste the provided code into a MATLAB script or function file.
3. Run the script in MATLAB.
4. View outputs in the MATLAB figure windows and console.

---

## Notes
- The methods can be applied to other plant leaf images by replacing the input image.
- Fine-tune parameters (e.g., morphological operation sizes, thresholds) for better segmentation depending on the leaf type and condition.

---

## Applications
- Plant disease monitoring in agriculture.
- Preprocessing for machine learning models in automated plant health systems.

