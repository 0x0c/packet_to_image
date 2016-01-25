#include <click/config.h>
#include "imager.hh"
#include <clicknet/ip.h>
#include <clicknet/ether.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
CLICK_DECLS

Imager::Imager()
{
}

Imager::~Imager()
{
}

void Imager::push(int, Packet *p)
{
	cv::Mat image = cv::Mat::zeros(cv::Size(40, 40), CV_8UC3);

	int len = p->length() & 0x7ff;
	const unsigned char *data = p->data();
	for (int i = 0; i < len; i++, data++) {
		image.data[i] = *data;
	}
	cv::Mat packet_img;
	cv::resize(image, packet_img, cv::Size(), 10, 10);

	cv::imshow("scaled", packet_img);
	cv::waitKey(15);

	output(0).push(p);
}

CLICK_ENDDECLS
EXPORT_ELEMENT(Imager)
