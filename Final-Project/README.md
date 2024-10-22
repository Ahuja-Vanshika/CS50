# **Virtual Calculator Using Python, OpenCV, and Hand Detection**

Welcome to the *Virtual Calculator* project! This project showcases a calculator that uses hand detection through a webcam to simulate button clicks and perform basic arithmetic operations. It leverages **Python**, **OpenCV**, and **cvzone's HandTrackingModule** for real-time hand tracking and gesture recognition.

## **Project Overview**

*This project aims to create a virtual calculator where users can perform calculations using hand gestures detected by a webcam. The calculator interface is displayed on the screen, and users can "click" the buttons by bringing their fingers close together.*

## **Libraries Used**

*This project utilizes several essential Python libraries to bring the virtual hand-tracking calculator to life:*

-  *OpenCV: A powerful computer vision library used here to capture live video from the webcam and process the image data in real time. OpenCV is also responsible for rendering the graphical elements of the calculator, such as the buttons and display.*

-   *cvzone: A computer vision library that simplifies complex OpenCV operations. Specifically, it helps with hand tracking by utilizing pre-built modules like the HandDetector, which efficiently detects and tracks hand movements.*

-   *Mediapipe: This is a framework by Google that enables real-time hand tracking and detection. It is embedded within cvzone and is used to detect hand landmarks, making it possible to interact with the calculator using gestures.*

## **Features**

- *Real-time hand detection using a webcam.*
- *Gesture-based interaction to simulate button clicks.*
- *Supports basic arithmetic operations: addition, subtraction, multiplication, division, and more.*
- *Error handling for invalid calculations.*

## **Key Code Snippet**

*The following code snippet highlights the logic for determining which button is clicked based on hand gestures:*
for i, button in enumerate(buttonList):
    row = i // 5  # Determine row index
    col = i % 5   # Determine column index
    value = buttonListValues[row][col]

    if button.checkClick(x, y) and delay_count == 0:
        if value == '=':
            try:
                calculation = str(eval(calculation))
            except:
                calculation = 'Error'
        elif value == 'C':
            calculation = ''
        else:
            calculation += value
        delay_count = 1

*This code snippet is crucial as it handles the logic for detecting button presses and performing calculations.*

## **Video Demonstration**

*Watch the short video to see the project in action:*

Project Video Link - https://youtu.be/HLp2mFihFws

## **Contributing**

*Contributions are welcome! If you have any suggestions or improvements, feel free to submit a pull request or open an issue.*

## **License**

**MIT License**

Copyright (c) 2024

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*

