#include <iostream>
#include "libserilalptz.h"
#include "httplib.h"
#include <jsoncpp/json/json.h>

#define MAX_SPEED   0x3F

libserilalptz libserilalptz;

void querry_Pan_Position(){
    std::cout << "querryPanPosition" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.querryPanPosition();
    char datares[7];
    bool start = false;
    int count = 0;
    for(unsigned int i = 0; i < 50; i++)
    {
        try
        {
            // Read a single byte of data from the serial ports.
            char c = libserilalptz.readByte(10);
            if(c == 0xFF){
                start = true;
            }
            if(start)
            {
                datares[count] = c;
                std::cout << "byte " << count << ": ";
                std::cout << std::hex << (int)datares[count] << std::endl;
                count++;
                if(count == 7)
                {
                    break;
                }
            }
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void querry_Tilt_Position(){
    std::cout << "querryTiltPosition" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.querryTiltPosition();
    char datares[7];
    bool start = false;
    int count = 0;
    for(unsigned int i = 0; i < 50; i++)
    {
        try
        {
            // Read a single byte of data from the serial ports.
            char c = libserilalptz.readByte(10);
            if(c == 0xFF){
                start = true;
            }
            if(start)
            {
                datares[count] = c;
                std::cout << "byte " << count << ": ";
                std::cout << std::hex << (int)datares[count] << std::endl;
                count++;
                if(count == 7)
                {
                    break;
                }
            }
        }
        catch (const ReadTimeout&)
        {
            // std::cerr << "The ReadByte() call has timed out." << std::endl;
        }
    }
}

void stop_All(){
    std::cout << "stopAll" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.stopAll();
}
void pan_Left(char speed){
    std::cout << "panLeft" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.panLeft(speed);
}

void pan_Right(char speed){
    std::cout << "panRight" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.panRight(speed);
}

void tilt_Up(char speed){
    std::cout << "tiltUp" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.tiltUp(speed);
}

void tile_Down(char speed){
    std::cout << "tiltDown" << std::endl;
    // libserilalptz libserilalptz;
    libserilalptz.tiltDown(speed);
}


int main()
{
    // HTTP
	httplib::Server svr;
	svr.Get("/ptz/v1.0/querryPanPosition", [](const httplib::Request &, httplib::Response &res) {
		res.set_content("querryPanPosition", "text/plain");
        querry_Pan_Position();
	});
    svr.Get("/ptz/v1.0/querryTiltPosition", [](const httplib::Request &, httplib::Response &res) {
		res.set_content("querryTiltPosition", "text/plain");
        querry_Tilt_Position();
	});
    svr.Get("/ptz/v1.0/stopAll", [](const httplib::Request &, httplib::Response &res) {
		res.set_content("stopAll", "text/plain");
        stop_All();
	});


    svr.Post("/ptz/v1.0/panLeft",
        [&](const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader) {
            if (req.is_multipart_form_data()) {
            // NOTE: `content_reader` is blocking until every form data field is read
            httplib::MultipartFormDataItems files;
            content_reader(
                [&](const httplib::MultipartFormData &file) {
                files.push_back(file);
                return true;
                },
                [&](const char *data, size_t data_length) {
                files.back().content.append(data, data_length);
                return true;
                });
            } else {
                std::string body;
                content_reader([&](const char *data, size_t data_length) {
                    body.append(data, data_length);
                    std::cout << body << std::endl;
                    Json::Value root_dataResponse;
                    Json::Reader reader;
                    reader.parse(body, root_dataResponse);
                    char speed = (char)root_dataResponse["speed"].asInt();
                    std::cout << std::hex << (int)speed << std::endl;
                    pan_Left(speed);
                    return true;
                });
            }
        });
    svr.Post("/ptz/v1.0/panRight",
        [&](const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader) {
            if (req.is_multipart_form_data()) {
            // NOTE: `content_reader` is blocking until every form data field is read
            httplib::MultipartFormDataItems files;
            content_reader(
                [&](const httplib::MultipartFormData &file) {
                files.push_back(file);
                return true;
                },
                [&](const char *data, size_t data_length) {
                files.back().content.append(data, data_length);
                return true;
                });
            } else {
                std::string body;
                content_reader([&](const char *data, size_t data_length) {
                    body.append(data, data_length);
                    std::cout << body << std::endl;
                    Json::Value root_dataResponse;
                    Json::Reader reader;
                    reader.parse(body, root_dataResponse);
                    char speed = (char)root_dataResponse["speed"].asFloat();
                    pan_Right(speed);
                    return true;
                });
            }
        });
    svr.Post("/ptz/v1.0/tiltUp",
        [&](const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader) {
            if (req.is_multipart_form_data()) {
            // NOTE: `content_reader` is blocking until every form data field is read
            httplib::MultipartFormDataItems files;
            content_reader(
                [&](const httplib::MultipartFormData &file) {
                files.push_back(file);
                return true;
                },
                [&](const char *data, size_t data_length) {
                files.back().content.append(data, data_length);
                return true;
                });
            } else {
                std::string body;
                content_reader([&](const char *data, size_t data_length) {
                    body.append(data, data_length);
                    std::cout << body << std::endl;
                    Json::Value root_dataResponse;
                    Json::Reader reader;
                    reader.parse(body, root_dataResponse);
                    char speed = (char)root_dataResponse["speed"].asFloat();
                    tilt_Up(speed);
                    return true;
                });
            }
        });
    svr.Post("/ptz/v1.0/tiltDown",
        [&](const httplib::Request &req, httplib::Response &res, const httplib::ContentReader &content_reader) {
            if (req.is_multipart_form_data()) {
            // NOTE: `content_reader` is blocking until every form data field is read
            httplib::MultipartFormDataItems files;
            content_reader(
                [&](const httplib::MultipartFormData &file) {
                files.push_back(file);
                return true;
                },
                [&](const char *data, size_t data_length) {
                files.back().content.append(data, data_length);
                return true;
                });
            } else {
                std::string body;
                content_reader([&](const char *data, size_t data_length) {
                    body.append(data, data_length);
                    std::cout << body << std::endl;
                    Json::Value root_dataResponse;
                    Json::Reader reader;
                    reader.parse(body, root_dataResponse);
                    char speed = (char)root_dataResponse["speed"].asFloat();
                    tile_Down(speed);
                    return true;
                });
            }
        });

	std::cout << "start http server" << std::endl;
	svr.listen("0.0.0.0", 8080);

}

// rsync -a -e "ssh -p 1222" /home/ngoc/Documents/gsoap/libserialptz nano@tigerpuma.ddns.net:~/ngocnv_ws
// rsync -a -e "ssh -p 1222" /home/ubuntu/Documents/gsoap/libserialptz nano@tigerpuma.ddns.net:~/ngocnv_ws