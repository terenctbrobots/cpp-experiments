from conan import ConanFile
from conan.tools.cmake import cmake_layout

class MinquestRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("sdl/3.2.20")
        self.requires("sdl_image/3.2.4")
        self.requires("imgui/1.92.5")
        self.requires("spdlog/1.16.0")

    def layout(self):
        cmake_layout(self)
