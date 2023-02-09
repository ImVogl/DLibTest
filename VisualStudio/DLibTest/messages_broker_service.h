#pragma once

#include <string>
#include <zmq.hpp>
#include <opencv2/core/mat.hpp>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

// ������ ������� ������ ���������.
class messages_broker_service
{
private:

	/// <summary>
	/// ��� ������ �������������.
	/// </summary>
	const std::string face_classify_service_ = "face_classify_service";

	/// <summary>
	/// ��� ������ ����������� ���.
	/// </summary>
	const std::string face_detection_service_ = "face_detection_service";

	/// <summary>
	/// ����� �������.
	/// </summary>
	zmq::socket_t server_socket_;

	/// <summary>
	/// ���������� �����.
	/// </summary>
	zmq::socket_t client_socket_;

	std::string face_classify_service_socket_;

public:

	/// <summary>
	/// �����������.
	/// </summary>
	/// <param name="server_port">����, �� ������� ����� �������� ������.</param>
	/// <param name="face_classify_service_socket">����� ������ ������������� �����������.</param>
	messages_broker_service(std::string server_port, std::string face_classify_service_socket)
	{
		face_classify_service_socket_ = face_classify_service_socket;
		zmq::context_t server_context{ 2 };
		server_socket_ = zmq::socket_t{ server_context, zmq::socket_type::rep };
		server_socket_.bind("tcp://*:" + server_port);

		zmq::context_t client_context{ 1 };
		client_socket_ = zmq::socket_t{ client_context, zmq::socket_type::req };
		client_socket_.connect("tcp://localhost:" + server_port);
	}

	/// <summary>
	/// ������ ������ ������� ZeroMQ.
	/// </summary>
	void start_server();

	/// <summary>
	/// �������� ��������� � ������������� ������������ ���.
	/// </summary>
	void send_faces(std::vector<cv::Mat> faces);
};
