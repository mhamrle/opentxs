message("** PHP Wrapper")

set(OTX_WRAPPER_NAME "opentxs_php")

set(CMAKE_SWIG_FLAGS "")

find_package(SWIG 3.0.0 REQUIRED)
include(${SWIG_USE_FILE})

include_directories(
  ${SWIG_INCLUDE_DIRS}
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(PHP5)

include_directories(
  ${PHP5_INCLUDE_DIR}
  ${PHP5_MAIN_INCLUDE_DIR}
  ${PHP5_ZEND_INCLUDE_DIR}
  ${PHP5_TSRM_INCLUDE_DIR}
)

set_source_files_properties(OTX_.i PROPERTIES CPLUSPLUS ON)
swig_add_module(${OTX_WRAPPER_NAME} php OTX_.i)
swig_link_libraries(${OTX_WRAPPER_NAME} ${PHP_LIBRARIES})

set(MOD_NAME ${SWIG_MODULE_${OTX_WRAPPER_NAME}_REAL_NAME})

target_link_libraries(${MOD_NAME} ${OTX_LINK_LIBS})
set_target_properties(${MOD_NAME}
  PROPERTIES OUTPUT_NAME ${OTX_WRAPPER_NAME})
set_lib_property(${MOD_NAME})
install(TARGETS ${MOD_NAME}
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          COMPONENT php)
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/${OTX_WRAPPER_NAME}.php
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/
          COMPONENT php)
