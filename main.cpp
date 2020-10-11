#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/video.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/ml.hpp"
using namespace cv;
Point point;
Mat img;
void On_mouse(int event, int x, int y, int flags, void*);
int main() {
    img= imread("../taxi.jpg");
    namedWindow("win");
    Mat res;
    /*
     * 事先标定像素点
    Point2f src[] = {
            Point2d (606,386),
            Point2d (771,386),
            Point2d (764,333),
            Point2d (600,331),



    };
    Point2f dst[] = {
            Point2d (0,600),
            Point2d (1700,600),
            Point2d (1700,0)     ,
            Point2d (0,0),
    };
    Mat  M=getPerspectiveTransform(src,dst);
    warpPerspective(img,res,M,Size(1700,600));

    cvtColor(res,res,COLOR_BGR2GRAY);
    threshold(res,res,125,255,THRESH_BINARY);

    imshow("win",res);
    waitKey(0);
     */
    imshow("win", img);
    setMouseCallback("win", On_mouse, 0);

    waitKey(0);
    return 0;
On_mouse(int event, int x, int y, int flags, void*)
{
    /*if (event == EVENT_LBUTTONUP ||!( flags&EVENT_FLAG_LBUTTON))
    {
        previousPoint = Point(-1, -1);
    }*/
    if (event == EVENT_LBUTTONDOWN)
    {
        point = Point(x, y);
    }
    else if (event == EVENT_MOUSEMOVE && (flags&EVENT_FLAG_LBUTTON))
    {
        Point pt(x, y);
        line(img, previousPoint, pt, Scalar(0,0,255), 2, 5, 0);
        previousPoint = pt;
        imshow(WINDOW, srcImage);
    }
}