#ifndef DLIB_SERVICE
#define DLIB_SERVICE

#define DLIB_JPEG_SUPPORT

#include "face_recognition_metric.h"
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>

using namespace dlib;
namespace fs = std::experimental::filesystem;

// ���������� ������ ��������� ����������� � ������� ���������� DLib.
class DLibService
{
public:
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
