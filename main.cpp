#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
int main() 
{
VideoCapture cap("vedio.mp4", cv::CAP_MSMF); 
VideoWriter writer; 
writer.open("appsrc ! videoconvert ! videoscale ! video/x-raw,width=640,height=480
            ! x264enc speed-preset=veryfast tune=zerolatency bitrate=800 !
             rtspclientsink location=rtsp://localhost:3000/mystream ",
              0, 20, Size(640, 480), true);
Detector dec = Detector();
Mat img;
for (;;)
   {
      if (!cap.isOpened())
      {
     std::cout << "Video Capture Fail" << std::endl;
      break;
   }
     cap.read(img); 
     cv::blur(ing,img,Size(10,10));
     cv::resize(img, img, Size(640, 480));
     cv::imshow("raw", img);
     writer << img;
     cv::waitKey(25);
    }
}
