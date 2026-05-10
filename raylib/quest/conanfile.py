from conan import ConanFile
from conan.tools.cmake import cmake_layout

class QuestRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("raylib/5.5")
        self.requires("spdlog/1.16.0")
        self.requires("nlohmann_json/3.12.0")
        self.requires("gaia-ecs/0.9.2")

    def layout(self):
        cmake_layout(self)
