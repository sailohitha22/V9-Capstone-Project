### High-Level Test Plan

| Test ID  | Description                                                    | Exp I/P                                        | Exp O/P                                       | Actual O/P         | Type of Test  |
|----------|----------------------------------------------------------------|------------------------------------------------|------------------------------------------------|--------------------|---------------|
| HLT-001  | Test real-time disease detection under varying light conditions | Leaf images with different lighting conditions | Accurate disease detection                     | ---- | Functional    |
| HLT-002  | Measure system processing time for real-time disease detection  | High-resolution leaf images                    | Process within 1 second per image              | ----     | Performance   |
| HLT-003  | Validate detection across multiple crops (tomato, eggplant, etc.) | Leaf images of various crops                   | Disease identified in selected crop            | ----         | Functional    |

### Low-Level Test Plan

| Test ID  | Description                                                   | Exp I/P                                    | Exp O/P                                      | Actual O/P         | Type of Test  |
|----------|---------------------------------------------------------------|--------------------------------------------|-----------------------------------------------|--------------------|---------------|
| LLT-001  | Test image segmentation using Otsu’s method                   | Sample leaf images                         | Binary mask showing diseased area             | Similar to expected | Functional    |
| LLT-002  | Test image segmentation using K-means clustering              | Sample leaf images                         | Segmented clusters of healthy/diseased areas  | As expected         | Functional    |
| LLT-003  | Validate accuracy of edge detection algorithms (Otsu, Canny)  | Leaf image                                 | Clear edge detection between healthy/diseased regions | As expected        | Functional    |
