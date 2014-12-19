message("** Perl Wrapper")

set(OTX_WRAPPER_NAME "OpenTransactions")

set(CMAKE_SWIG_FLAGS "")

find_package(SWIG 3.0.0 REQUIRED)
include(${SWIG_USE_FILE})

include_directories(
  ${SWIG_INCLUDE_DIRS}
)

find_package(PerlLibs REQUIRED)

include_directories(
  ${PERL_INCLUDE_PATH}
)

set_source_files_properties(OTX_.i PROPERTIES CPLUSPLUS ON)
## Perl modules must not use lower case names, we will use OpenTransactions
swig_add_module(${OTX_WRAPPER_NAME} perl OTX_.i)
swig_link_libraries(${OTX_WRAPPER_NAME} ${PERL_LIBRARIES})

set(MOD_NAME ${SWIG_MODULE_${OTX_WRAPPER_NAME}_REAL_NAME})

target_link_libraries(${MOD_NAME} ${OTX_LINK_LIBS})
set_target_properties(${MOD_NAME}
  PROPERTIES OUTPUT_NAME ${OTX_WRAPPER_NAME})
set_lib_property(${MOD_NAME})
install(TARGETS ${MOD_NAME}
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
          COMPONENT perl)

