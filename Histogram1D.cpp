#pragma once
#include "Histogram1D.hpp"
#include "use_opencv.h"


Histogram1D::Histogram1D() { // 1���� ������׷��� ���� ���� �غ�
	histSize[0] = 256;
	hranges[0] = 0.0;
	hranges[1] = 255.0;
	ranges[0] = hranges;
	channels[0] = 0; // �⺻������ ä���� 0���� ����
}

// ������ ��� ������ �׷��̷��� ������ ������׷��� ����� ���� ���� �޼ҵ带 ����� ����
cv::MatND Histogram1D::getHistogram(const cv::Mat &image) {
	// 1����(1D) ������׷� ���.
	cv::MatND hist;
	cv::calcHist(&image, // ������׷� ��� 
		1,   // ���� ������ ������׷���
		channels, // ��� ä��               
		cv::Mat(), // ����ũ ������� ����     
		hist,  // ��� ������׷�         
		1,   // 1����(1D) ������׷�           
		histSize, // �󵵼�                  
		ranges  // ȭ�Ұ� ����             
	);
	return hist;
}
