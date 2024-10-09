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
Title- Automated Leaf Disease Detection Using ZYNQ FPGA with CNN Acceleration (2023)

Methodology	
- Designed a CNN-based leaf disease detection system using the ZYNQ FPGA to accelerate the convolution operations for real-time analysis.
  
Significance
- Enhances the accuracy and speed of disease detection while keeping power consumption low, suitable for remote agricultural areas.
  
Research Gaps
- Focuses on leaf diseases only, and scalability for multi-crop environments or integration with IoT systems is not addressed.

Diseases
- Cercospora leaf spot, black rot, mosaic virus

# Paper-2
Title- Real-Time Image Processing on FPGA for Crop Disease Detection (2022)

Methodology
- The system leverages the ZYNQ SoC to perform real-time image processing for disease detection in crops, employing OpenCV and hardware accelerators.

Significance
- Highlights the potential for real-time, large-scale deployment in agricultural fields due to the speed of hardware-accelerated image processing techniques on the FPGA.

Research Gaps
- Lacks the use of advanced AI models for better disease recognition and is not tested on diverse plant species and disease categories.

Diseases
- Anthracnose, fusarium wilt, leaf blight

# Paper-3
Title- Implementation of Plant Disease Detection Using Deep Learning on FPGA (2021)

Methodology
- Utilizes ZYNQ 7000 SoC to implement a CNN for plant disease detection. FPGA accelerates inference while the processing system handles control functions.

Significance
- Demonstrates the efficiency of FPGA-based systems in real-time plant disease detection, reducing latency compared to traditional processing platforms.

Research Gaps
- Limited to common plant diseases; broader datasets and more advanced neural networks could improve detection accuracy and generalization.

Diseases
- Leaf blight, powdery mildew, bacterial spot

# Paper-4
Title- Plant Disease Classification Using Edge AI on ZYNQ SoC (2020)

Methodology
- Deployed a machine learning model on ZYNQ SoC using edge AI techniques. The focus was on classifying diseases from plant leaf images.

Significance
- Provides a low-power, high-performance solution for real-time classification of plant diseases at the edge, minimizing the need for cloud computation.

Research Gaps
- Does not explore more complex plant diseases requiring multi-modal inputs (e.g., climate, soil data) to enhance decision-making
  
Diseases
- Late blight, early blight, leaf curl virus

# Paper-5
Title

Methodology

Significance

Research Gaps

Diseases
