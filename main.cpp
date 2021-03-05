/*This code is made available under the Creative Commons Zero 1.0 License 
(https://creativecommons.org/publicdomain/zero/1.0)*/

/*
    Face Detector using OpenCV
    It can detect and draw rectangle around faces from image or webcam live video 
    Created By: sdam1n
*/

// OpenCV headers
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

// global variable declarations
Mat img;

vector<int> max_people;

// function for start menu
int start_menu()
{
    cout << "***MENU***" << endl;
    cout << "Detect face from:" << endl;
    cout << "1. Image" << endl;
    cout << "2. Webcam" << endl;
    cout << "Enter 1 or 2 to select:"<< endl;
    int choice;
    cin >> choice;
    return choice;

}

// function for processing image or live video from webcam
void processing(Mat img)
{
    Mat img_gray;

    CascadeClassifier facecascade;
    facecascade.load("resources/haarcascade_frontalface_default.xml"); // pre trained model

    if(facecascade.empty()) cout << "face cascade xml is not loaded" << endl;
        
    cvtColor(img,img_gray,COLOR_BGR2GRAY);

    vector<Rect> faces;

    facecascade.detectMultiScale(img_gray,faces,1.1,10);  /*increase or decrease 3rd/4th value to detect more or less people*/
        

    for(int i=0;i<faces.size();i++)
    {
        rectangle(img,faces[i].tl(),faces[i].br(),Scalar(0,0,255),3);
    }

    max_people.push_back(faces.size());    // for maximum number of people detected at once
    imshow("image", img);    
}

// function for maximum number of people detected at once
void max_people_count(vector<int> max_people)
{
    cout << *max_element(max_people.begin(), max_people.end()) << endl;
}


//  main function
int main()
{
    
    while(true)
    {
        int choice;
        choice = start_menu();

    
        if(choice==1)   // for image
        {
            string path = "resources/group1.jpg";
            img = imread(path);
            processing(img);
            waitKey(0);

            break;

        }
        else if(choice==2)  // for live video from webcam
        {
            VideoCapture cap(0);
            while(true)
            {   
                cap.read(img);
                processing(img);
                int key = waitKey(1);
                if(key==27) break;   // for exiting
            }
            break;
        }
        else 
        {
            cout << "Enter 1 or 2" << endl;

        }
       
    }

    max_people_count(max_people);   // maximum number of people at once
    
}

