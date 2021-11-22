#ifndef __RESOURCE_MANAGER_HPP__
#define __RESOURCE_MANAGER_HPP__

#include <cassert>
#include <cstdint>
#include <string>
#include <unordered_map>

class Font;
class Texture;

class ResourceManager {
public:
    static ResourceManager* GetInstance();

    void Release();

    const Font&    LoadFont   (const std::string& name);
    const Texture& LoadTexture(const std::string& name); 

private:
    ResourceManager();
    ~ResourceManager();

    ResourceManager(const ResourceManager& other) = delete;
    ResourceManager& operator=(const ResourceManager& other) = delete;

    static ResourceManager* singleton;

private:
    std::unordered_map<std::string, Font*>    loaded_fonts_;
    std::string                               fonts_directory_;

    std::unordered_map<std::string, Texture*> loaded_textures_;
    std::string                               textures_directory_;
};

#endif // __RESOURCE_MANAGER_HPP__