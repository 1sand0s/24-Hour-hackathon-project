#include<jni.h>
#include "jnitest.h"
#include<Windows.h>
#include<opencv/cv.h>
#include<opencv/cvaux.h>
#include<opencv/cxcore.h>
#include<opencv/highgui.h>
#include<conio.h>
#include<opencv/cvwimage.h>
#include<opencv2/imgproc/imgproc.hpp>
JNIEXPORT jint JNICALL Java_jnitest_direc(JNIEnv *env, jobject obj)
{
	

	CvCapture* c;
	IplImage* p;
	IplImage* p1;
	//printf("AGNA COMMAND LINE");
	int HH,SH,VH,HL,SL,VL;
	HL=92;
	HH=179;
	VL=121;
	VH=255;
	SL=42;
	SH=255;
	cvNamedWindow("original",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("processed",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("ori2",CV_WINDOW_AUTOSIZE);
	cvCreateTrackbar("HH","original",&HH,179);
	cvCreateTrackbar("SH","original",&SH,255);
	cvCreateTrackbar("VH","original",&VH,255);
	cvCreateTrackbar("HL","original",&HL,179);
	cvCreateTrackbar("SL","original",&SL,255);
	cvCreateTrackbar("VL","original",&VL,255);
	cvNamedWindow("hello2",CV_WINDOW_AUTOSIZE);
	c=cvCreateCameraCapture(CV_CAP_ANY);
	if(c==NULL)
	{
		printf("NO RECORDING DEVICES PRESENT");
		getch();
	
	}
    p=cvQueryFrame(c);
	p1=cvCreateImage(CvSize(cvGetSize(p)),IPL_DEPTH_8U,3);
	IplImage* p2;
	p2=cvCreateImage(CvSize(cvGetSize(p)),IPL_DEPTH_8U,1);
	IplImage* p3;
	p3=cvCreateImage(CvSize(cvGetSize(p)),IPL_DEPTH_8U,1);
		IplImage* p4;
	
	CvSeq* q;
	CvSeq* contours=0;
	float* pxy;
	CvMemStorage* sto;
	CvMemStorage* sto1;
	

	while(1)
	{
	  p=cvQueryFrame(c);
	  p4=cvCreateImage(CvSize(cvGetSize(p)),IPL_DEPTH_8U,3);
	  cvSmooth(p,p,CV_GAUSSIAN,9,9);
      cvCvtColor(p,p1,CV_BGR2HSV);
	  sto=cvCreateMemStorage(0);
	  sto1=cvCreateMemStorage(0);
	  cvInRangeS(p1,cvScalar(49,209,55),cvScalar(HH,SH,VH),p2);
	  q=cvHoughCircles(p2,sto,CV_HOUGH_GRADIENT,100,50,10,400);
	  for(int i=0;i<q->total;i++)
	  {
		  pxy=(float*)cvGetSeqElem(q,i);
		  cvCircle(p,cvPoint(cvRound(pxy[0]),cvRound(pxy[1])),10,CV_RGB(0,255,0),2);
		  cvCircle(p,cvPoint(cvRound(pxy[0]),cvRound(pxy[1])),8,CV_RGB(255,0,0),CV_FILLED);
	  }
	  cvReleaseMemStorage(&sto);
	  
	  cvCanny(p2,p3,200,255,3);
	
	  cvDilate(p3,p3,0,1);
	  cvFindContours(p3,sto1,&contours,sizeof(CvContour),CV_RETR_TREE,CV_CHAIN_APPROX_NONE,cvPoint(0,0));
	 
	  double u=0;
	  double great=0;
	  
	  for(CvSeq* cur=contours;cur!=NULL;cur=cur->h_next)
	  {
		  u=cvContourArea(cur);
		  if(u>great)
		  {
			  great=u;
		  }
		  CvSeq* dest=NULL;
		  CvSeq* dest2=NULL;
		  CvMemStorage* sto3=cvCreateMemStorage(0);
		  CvMemStorage* sto4=cvCreateMemStorage(0);
		  dest = cvConvexHull2(cur,sto3, CV_CLOCKWISE, 0);
		  dest2=cvConvexityDefects(cur,dest,sto4);
		  int t=dest2->total;
		  CvConvexityDefect* tr=(CvConvexityDefect*)malloc(sizeof(CvConvexityDefect)*t);
		  cvCvtSeqToArray(dest2,tr,CV_WHOLE_SEQ);
		  for(int y=0;y<t;y++)
		  {
			       cvLine(p4, *(tr[y].start), *(tr[y].depth_point), cvScalarAll(255),1, CV_AA, 0 );  
                    cvCircle(p4, *(tr[y].depth_point), 5, cvScalarAll(255), 2, 8,0);  
                    cvCircle(p4, *(tr[y].start), 5, cvScalarAll(255), 2, 8,0);  
                    cvLine(p4, *(tr[y].depth_point), *(tr[y].end), cvScalarAll(255),1, CV_AA, 0 );
					CvPoint* poi=tr[y].start;
					if(poi->x>570&&poi->x<670&&poi->y>190&&poi->y<290)
					{
						
						return 5;
						
					}
					else if(poi->x>70&&poi->x<170&&poi->y>190&&poi->y<290)
					{
						
						return 6;
						
					}
			        else if(poi->x>270&&poi->x<370&&poi->y>90&&poi->y<190)
					{
						
						return 7;
						
					}
					else if(poi->x>270&&poi->x<370&&poi->y>390&&poi->y<490)
					{
						
						return 8;
						
					}
					
		   cvReleaseMemStorage(&sto3);
		  sto3=cvCreateMemStorage(0);
		  dest=cvConvexHull2(cur,sto3,CV_CLOCKWISE,1);
		 
		 
		  cvDrawContours(p, dest, cvScalarAll(255), cvScalarAll(255), 0, 2, 8);
          cvReleaseMemStorage(&sto3);
		   cvReleaseMemStorage(&sto4);
		  }
	  }
	  
	/* printf("%f ",great);
	  if(great>2000 && great<3000)
	  {
	   cvDrawContours(p4,contours,CV_RGB(255,0,0),CV_RGB(0,255,0),10,1,CV_AA,cvPoint(0,0));
	   IplImage* pf;
	   
	    pf=cvQueryFrame(c);
	  
	   cvShowImage("ori2",pf);
	   cvSaveImage("C:/Users/Computer/Desktop/hi.jpg",pf);
	   cvReleaseImage(&pf);
	   break;
	  }
	 */
	 cvCircle(p,cvPoint(620,240),50,CV_RGB(0,100,250),2);
	  cvCircle(p,cvPoint(120,240),50,CV_RGB(250,100,0),2);
	  cvCircle(p,cvPoint(320,140),50,CV_RGB(0,250,100),2);
	  cvCircle(p,cvPoint(320,440),50,CV_RGB(100,250,0),2);
	  cvShowImage("original",p4);
	  cvShowImage("processed",p);
	  cvShowImage("hello2",p4);
	  char ch=cvWaitKey(30);
	  cvReleaseMemStorage(&sto1);
	  cvReleaseImage(&p4);
	  if(ch==27)break;
	}
	
	cvReleaseCapture(&c);
	cvReleaseImage(&p);
	cvReleaseImage(&p1);
	cvReleaseImage(&p2);
	cvReleaseImage(&p3);
	cvDestroyWindow("ori2");
	cvDestroyWindow("original");
	cvDestroyWindow("processed");
	cvDestroyWindow("hello2");
	return 0;
}