#ifndef FILE_SERVICE
#define FILE_SERVICE

#include <filesystem>
#include "face_recognition_metric.h"

namespace fs = std::experimental::filesystem;

// ���������� ������.
class FileService
{
public:

	/// <summary>
	/// �������� ��������� ���� �����������.
	/// </summary>
	/// <param name="source_path">����� � ��������������� �������.</param>
	/// <param name="extension">���������� ������� ������.</param>
	/// <returns><see cref="DataStorageViewModel"/> � ������������������� ������.</returns>
	std::vector<fs::path> get_all_images(fs::path source_path, std::string extension);

	/// <summary>
	/// ��������� ���������� � .CSV ����.
	/// </summary>
	/// <param name="results">��������� <see cref="FaceRecognitionMetric"/>.</param>
	/// <param name="output_dir_path">���� �� �������� ����������.</param>
	void save_results_csv(std::vector<FaceRecognitionMetric> results, const fs::path& output_dir_path);
};

#endif
