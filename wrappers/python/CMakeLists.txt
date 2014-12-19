message("** Python Wrapper")

set(OTX_WRAPPER_NAME "opentxs-python")

set(CMAKE_SWIG_FLAGS "")

find_package(SWIG 3.0.0 REQUIRED)
include(${SWIG_USE_FILE})

include_directories(
  ${SWIG_INCLUDE_DIRS}
)

find_package(PythonLibs)
include_directories(
  ${PYTHON_INCLUDE_PATH}
)

set_source_files_properties(OTX_.i PROPERTIES CPLUSPLUS ON)
swig_add_module(${OTX_WRAPPER_NAME} python OTX_.i)
swig_link_libraries(${OTX_WRAPPER_NAME} ${PYTHON_LIBRARIES})

set(MOD_NAME ${SWIG_MODULE_${OTX_WRAPPER_NAME}_REAL_NAME})

target_link_libraries(${MOD_NAME} ${OTX_LINK_LIBS})
set_target_properties(${MOD_NAME}
                      PROPERTIES OUTPUT_NAME _opentxs)
set_lib_property(${MOD_NAME})
string(REGEX REPLACE "\\.[0-9]+$" "" PYTHON_VERSION "${PYTHONLIBS_VERSION_STRING}")
install(TARGETS ${MOD_NAME}
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/python${PYTHON_VERSION}/site-packages
        COMPONENT python)
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/opentxs.py
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/python${PYTHON_VERSION}/site-packages
        COMPONENT python)

