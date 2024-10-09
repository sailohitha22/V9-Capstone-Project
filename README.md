# V9-Capstone-Project
# Problem Statement
Utilizing ZYNQ 7000 SOC for automated plant diesease detection

# Introduction
Developing a real-time automated plant disease detection system using
the ZYNQ 7000 SoC. The process started with MATLAB for image
segmentation and edge detection to identify crop disease patterns. After
optimizing the image processing in MATLAB, the system will be
integrated with the ZYNQ 7000 platform for enhanced performance,
improving crop management.

# Abstract
Plant diseases are a serious threat to agricultural productivity since they can have an impact on 
crop quality and quantity. Worldwide, millions of tons of crops are lost each year due to various 
plant diseases, leading to economic losses and food security concerns. Traditional methods for 
managing plant diseases include chemical treatments, crop rotation, and the use of disease resistant crop varieties. However, these measures have limitations, such as environmental 
impact, the emergence of resistant pathogens, and the time required for developing resistant 
varieties. To mitigate these losses, a real-time, computer vision-based system for detecting 
plant illnesses is proposed. This system aims to accurately identify two forms of diseases in 
plant leaves under various illumination conditions, leveraging the Xilinx ZYNQ SoC FPGA 
for implementation. The FPGA's low latency performance and parallel processing capabilities 
make it ideal for real-time applications, enabling rapid processing of high-resolution images 
and accurate disease detection, thus ensuring timely intervention and minimizing crop loss. 
The computational complexity and time demand of computer vision applications are addressed 
by the FPGA's powerful parallel processing and low latency performance. To further enhance 
the project, edge AI technology will be integrated, allowing the system to process and analyse
data directly on devices at the network's edge. This reduces the need for constant connectivity 
to centralized servers, speeds up reaction times, and increases system resilience and 
dependability in various field conditions.
# Literature Survey
# Paper-1
Title-Automated Leaf Disease Detection Using ZYNQ FPGA with CNN Acceleration (2023)

Methodology	
-Designed a CNN-based leaf disease detection system using the ZYNQ FPGA to accelerate the convolution operations for real-time analysis.
  
Significance
-Enhances the accuracy and speed of disease detection while keeping power consumption low, suitable for remote agricultural areas.
  
Research Gaps
- Focuses on leaf diseases only, and scalability for multi-crop environments or integration with IoT systems is not addressed.

Diseases
Cercospora leaf spot, black rot, mosaic virus

# Paper-2
Title-Rice plant disease detection(2014)

Methodology
- Color Space Features: RGB and HSV for feature extraction
- Classification: ANN with back-propagation algorithm

Significance
- Comprehensive approach using multiple color spaces and ANN back-propagation, enhancing the accuracy of rice disease detection.

Research Gaps
- Focused primarily on color-based features, potentially overlooking other significant features like shape and texture.
- No comparison with other classifiers like SVM or decision trees

# Paper-3
Title
