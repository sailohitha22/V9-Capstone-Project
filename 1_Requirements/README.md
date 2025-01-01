# High-Level Requirements (HLR):

 - Early Disease Detection:
  The system must detect plant diseases at an early stage by analyzing subtle symptoms in leaf patterns, color, and texture before visible signs appear.
- Real-time Image Processing:
  It must leverage the parallel processing capabilities of the Xilinx ZYNQ SoC FPGA to analyze high-resolution images in real time and provide immediate feedback to farmers. 
- Environmental Adaptability:
  The system should maintain accuracy across different environmental conditions (lighting, weather) and crop types.  
- Scalability:
The system needs to be scalable to monitor various crops and diseases, supporting both small farms and large-scale agricultural operations.
- Comparative Analysis:
Conduct comparative studies with traditional and AI-based methods to evaluate improvements in accuracy, processing speed, and resource 
efficiency. 

# Low-Level Requirements (LLR):

- Algorithm Development: The project developed image segmentation and edge detection algorithms using MATLAB, such as Otsu’s method and K-means clustering.
- System Integration: After successful validation, the algorithms were ported to the ZYNQ 7000 SoC for optimized real-time processing.
- Camera and Sensor Integration: High-resolution cameras and sensors were incorporated to capture detailed crop images.
# Non-Functional Requirements (NFR):

- Performance: The system must process images in under 1 second to ensure real-time disease detection.
- Power Efficiency: The FPGA technology must enable the system to operate in resource-constrained environments such as agricultural fields where power may be limited.
- User-Friendliness: The system should be easy to use by farmers without advanced technical expertise.
  Environmental Impact: It should promote sustainable farming by reducing the need for chemical pesticides.
