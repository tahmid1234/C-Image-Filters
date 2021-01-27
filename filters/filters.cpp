
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/highgui.hpp>
#include <list> 
using namespace std;

void getNegetive(cv::Mat src){
        cv:: Mat negetive=255-src;
         cv::imshow("Negetive",negetive);


}
void getSmoothImageUsingMeanFilter(cv::Mat src){
         //cout << "M = " << endl << " "  << src.at<int>(src.rows-1,src.cols-1) << endl << endl;
        int i,j,k,l,x,y,factor=3;
      
          double element[9]; 
       
        cv::Mat smooth;
        src.copyTo(smooth);//= cv::Mat::zeros(src.rows, src.cols, CV_64F);
        for(i=1;i<src.rows-1;i++){
           
            for(j=1;j<src.cols-1;j++){
                int flag=0;
                for (k=0;k<factor;k++){
                    for(l=0;l<factor;l++){
                        x=i+k-1;
                        y=j+l-1;
                        element[flag++]=(int)src.at<uchar>(x,y);
                       

                    }
                }
                 //cout<< element<<" "<< endl;
                sort(element,element+flag);
               //cout << "M = " << endl<<element[4] << " "  <<(int) src.at<uchar>(x,y)<< endl << endl;
                //cout<< element<<" "<< endl;
                
              
                 smooth.at<uchar>(i,j)=element[4];
            }
        }
       // cout << "M = " << endl << " "  << smooth << endl << endl;
        cv::imshow("Smooth",smooth);


}

int main()
{
    cv:: Mat image;
    image= cv::imread("./1. Splash.png",cv:: IMREAD_GRAYSCALE);
    //image=255-image;
    //getNegetive(image);
   
    int i,j;
    cv::Mat s= cv::Mat::ones(5, 5, CV_64F);
    s.at<double_t>(1,1)=5;
    s.at<double_t>(1,2)=6;
    s.at<double_t>(1,3)=7;
    s.at<double_t>(2,1)=8;
    s.at<double_t>(2,2)=9;
    s.at<double_t>(3,1)=2;
    s.at<double_t>(3,2)=3;
    s.at<double_t>(3,3)=1;
    s.at<double_t>(1,1)=5;

    uint8_t * data=image.data;
    image.data[1,2];
     cout << "M = " << endl << " "  << (int)image.at<uchar>(image.rows-1,image.cols-1) << endl << endl;
        
    getSmoothImageUsingMeanFilter(image);
    cv::imshow("Test",image);
    cv::waitKey(0);
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}

