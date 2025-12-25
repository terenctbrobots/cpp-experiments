from conan import ConanFile

class MinquestRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
         self.requires("sdl/3.2.20")
         self.requires("imgui/1.92.5")
