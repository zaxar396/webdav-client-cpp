#include <webdav/client.hpp>

int main() {

    std::map<std::string, std::string> options =
            {
                    { "webdav_hostname", "https://webdav.yandex.ru" },
                    { "webdav_login", "{webdav_login}" },
                    { "webdav_password", "{webdav_password}" }
            };

    std::unique_ptr<WebDAV::Client> client(WebDAV::Client::Init(options));
    bool is_connected = client->check();

    auto remote_resources = {
            "existing_file.dat",
            "not_existing_file.dat",
            "existing_directory",
            "existing_directory/",
            "not_existing_directory",
            "not_existing_directory/"
    };

    for (auto remote_resource : remote_resources) {
        bool is_clean = client->clean(remote_resource);
        std::cout << "Resource: " << remote_resource << " is " << is_clean ? "" : "not " << "clean" << std::endl;
    }
}

/// Resource: existing_file.dat is clean
/// Resource: not_existing_file.dat is clean
/// Resource: existing_file.dat is clean
/// Resource: existing_directory is clean
/// Resource: existing_directory/ is clean
/// Resource: not_existing_directory is clean
/// Resource: not_existing_directory/ is clean
