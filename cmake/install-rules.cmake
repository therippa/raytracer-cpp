install(
    TARGETS raytracer-cpp_exe
    RUNTIME COMPONENT raytracer-cpp_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
