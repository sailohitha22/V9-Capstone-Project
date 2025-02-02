# Plant Disease Detection System

## Purpose
This project utilizes Convolutional Neural Networks (CNN) to classify plant diseases in images. It automatically detects and categorizes plant diseases such as **Powdery Mildew**, **Rust**, and **Healthy** based on images of plant leaves. This tool can be used in agricultural fields to identify plant diseases early, helping in better crop management and disease prevention.

## How It Works

### 1. Dataset Preparation:
- The images are categorized into three classes:
  - **Healthy**: Plants without any disease.
  - **Powdery**: Plants affected by Powdery Mildew.
  - **Rust**: Plants affected by Rust disease.
- These categorized images are used for **training**, **validation**, and **testing** the CNN model.

### 2. Model Training:
- The model is built using **TensorFlow** and **Keras** libraries.
- Various **convolutional layers** and **pooling layers** are applied to extract features from the images.
- The CNN model learns to classify images into one of the three categories: **Healthy**, **Powdery**, or **Rust**.

### 3. Prediction:
- After training, the model can predict the disease type for new plant leaf images.
- This allows for **real-time plant disease detection**, assisting in faster decision-making in agriculture.

## Expected Output
The model will output the predicted class of the plant leaf image—whether it is **healthy** or affected by **Powdery Mildew** or **Rust**.
