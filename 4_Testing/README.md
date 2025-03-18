### High-Level Test Plan

| Test ID  | Description                                                    | Exp I/P                                        | Exp O/P                                       | Actual O/P         | Type of Test  |
|----------|----------------------------------------------------------------|------------------------------------------------|------------------------------------------------|--------------------|---------------|
| HLT-001  | Test real-time edge detection under varying light conditions | Leaf images with different lighting conditions | Accurate edge detection                     | Similar to expected | Functional    |
| HLT-002  | Measure system processing time for real-time disease detection  | High-resolution leaf images                    | Process within 1 second per image              |  As expected     | Performance   |
| HLT-003  | Validate detection across multiple crops (tomato, eggplant, etc.) | Leaf images of various crops                   | Disease identified in selected crop            |  As expected      | Functional    |

### Low-Level Test Plan

| Test ID  | Description                                                   | Exp I/P                                    | Exp O/P                                      | Actual O/P         | Type of Test  |
|----------|---------------------------------------------------------------|--------------------------------------------|-----------------------------------------------|--------------------|---------------|
| LLT-001  | Test image segmentation using Otsu’s method                   | Sample leaf images                         | Binary mask showing diseased area             | Similar to expected | Functional    |
| LLT-002  | Test image segmentation using K-means clustering              | Sample leaf images                         | Segmented clusters of healthy/diseased areas  | As expected         | Functional    |
| LLT-003  | Validate accuracy of edge detection algorithms (Otsu, Canny)  | Leaf image                                 | Clear edge detection between healthy/diseased regions | As expected        | Functional    |

---
# Data Generation Using Zynq 7000 - Verilog Modules

This project uses the Zynq 7000 board for data generation. Two key Verilog modules, `mux` and `dataGen`, are responsible for generating and managing data signals. Below is an explanation of their functionality.

---
## 1. `mux` Module

The `mux` module selects between input data (`i_data`) and black (`0x000000`) based on the control signal (`i_control`). If `i_control = 1`, it outputs the input data; if `i_control = 0`, it outputs black. It is useful for controlling data flow in image processing.

---
## 2. `dataGen` Module

The `dataGen` module generates RGB pixel data for a video frame. It creates a pattern where each line is divided into three colored sections: blue, green, and red.

### Features:
- **Frame Configuration**:
  - A line consists of 1920 pixels (`lineSize`).
  - A frame consists of 1080 lines (`frameSize`).

- **Color Output**:
  - The first 640 pixels in a line are blue (`0x0000FF`).
  - The next 640 pixels are green (`0x00FF00`).
  - The remaining pixels are red (`0xFF0000`).

- **Control Signals**:
  - `o_sof`: Indicates the start of a frame.
  - `o_eol`: Indicates the end of a line.
  - `o_data_valid`: Signals when valid data is available.

### Workflow:
1. **IDLE State**:
   - Initialization occurs, and `o_sof` is set to indicate the start of the frame.
2. **SEND_DATA State**:
   - RGB data is output pixel by pixel, incrementing the `linePixelCounter`.
   - At the end of the line, `o_eol` is raised.
3. **END_LINE State**:
   - The line counter resets, and the next line begins.
   - Once the entire frame is processed, the module returns to the IDLE state.

### Visual Explanation:
```text
Line Structure:
- 0 to 639 pixels → Blue
- 640 to 1279 pixels → Green
- 1280 to 1919 pixels → Red
