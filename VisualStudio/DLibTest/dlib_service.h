#ifndef DLIB_SERVICE
#define DLIB_SERVICE

#define DLIB_JPEG_SUPPORT

#include "face_recognition_metric.h"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include "dlib/opencv.h"

using namespace dlib;
namespace fs = std::experimental::filesystem;

// ���������� ������ ��������� ����������� � ������� ���������� DLib.
class DLibService
{
private:

	/// <summary>
	/// ��������, ������������, ��� ����� ������� ���������� �����������.
	/// </summary>
	bool collect_faces_;

	/// <summary>
	/// ��������� ����������� �����������.
	/// </summary>
	std::vector<cv::Mat> collected_faces_;

	/// <summary>
	/// ���������� ����������� �� �������� �������.
	/// </summary>
	/// <param name="path">���� �� ��������������� �����������.</param>
	/// <param name="sub_image_borders">�������, ������� ��������� ��������.</param>
	/// <returns>���������� �������.</returns>
	void store_sub_image(const fs::path& path, rectangle sub_image_borders);

public:

	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="collect_faces">��������, ������������, ��� ����� ������� ���������� �����������.</param>
	explicit DLibService(const bool collect_faces)
	{
		collect_faces_ = collect_faces;
		collected_faces_ = std::vector<cv::Mat>();
	};

	/// <summary>
	/// ����������� ��� � ���������� ����������� ����� ���������.
	/// </summary>
	/// <param name="detector"><see cref="frontal_face_detector"/>.</param>
	/// <param name="path">���� �� ��������������� �����.</param>
	/// <returns><see cref="FaceRecognitionMetric"/>.</returns>
	FaceRecognitionMetric recognize_faces(frontal_face_detector& detector, const fs::path& path);

	/// <summary>
	/// ����������� ��� � ������� ����������� �� �����.
	/// </summary>
	/// <param name="detector"><see cref="frontal_face_detector"/>.</param>
	/// <param name="win"><see cref="image_window"/>.</param>
	/// <param name="path">���� �� ��������������� �����.</param>
	void recognize_faces(frontal_face_detector& detector, image_window& win, const fs::path& path);

	/// <summary>
	/// ����������� ��� � ������� ����������� �� �����.
	/// </summary>
	/// <param name="detector"><see cref="frontal_face_detector"/>.</param>
	/// <param name="win"><see cref="image_window"/>.</param>
	/// <param name="image">�����������.</param>
	void recognize_faces(frontal_face_detector& detector, image_window& win, array2d<unsigned char> image);
};

#endif
