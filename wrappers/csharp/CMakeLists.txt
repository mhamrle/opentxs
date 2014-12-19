## Work in progress
##
message("** Csharp Wrapper")
set(OTX_WRAPPER_NAME "Opentxs")

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(CSharp REQUIRED)
include( ${CSHARP_USE_FILE} )

include_directories(
  ${SWIG_INCLUDE_DIRS}
)


# Setup our csharp build area for the managed API assembly
set(CSHARP_SOURCE_DIRECTORY 
  ${CMAKE_CURRENT_BINARY_DIR}/otx_sharp 
  CACHE INTERNAL "")

set(CSHARP_BINARY_DIRECTORY 
  ${CSHARP_SOURCE_DIRECTORY}/bin 
  CACHE INTERNAL "")

file(MAKE_DIRECTORY ${CSHARP_SOURCE_DIRECTORY})  
file(MAKE_DIRECTORY ${CSHARP_BINARY_DIRECTORY})  
set(CMAKE_SWIG_OUTDIR ${CSHARP_SOURCE_DIRECTORY})


# Setup our csharp build parameters
set(CMAKE_SWIG_FLAGS "")
if(UNIX)
  set(CMAKE_SWIG_FLAGS 
    -dllimport \"lib${OTX_WRAPPER_NAME}.so\")
elseif(WIN32)
  message(FATAL ERROR "C# bindings for Windows are currently not supported." )
endif()

set(CMAKE_SWIG_FLAGS 
  -namespace \"OpenTransactions.OTAPI\" 
  ${CMAKE_SWIG_GLOBAL_FLAGS} 
  ${CMAKE_SWIG_FLAGS})

set(CMAKE_SWIG_FLAGS 
  -I${CMAKE_SOURCE_DIR} 
  ${CMAKE_SWIG_FLAGS})

set_source_files_properties(OTX_.i PROPERTIES CPLUSPLUS on)


# Native
swig_add_module(${OTX_WRAPPER_NAME} csharp OTX_.i)
swig_link_libraries(${OTX_WRAPPER_NAME} ${OTX_LINK_LIBS})

set(MOD_NAME ${SWIG_MODULE_${OTX_WRAPPER_NAME}_REAL_NAME})

target_link_libraries(${MOD_NAME} ${OTX_LINK_LIBS})
set_target_properties(${MOD_NAME}
                      PROPERTIES OUTPUT_NAME ${OTX_WRAPPER_NAME})


# Managed
set(MANAGED_ASSEMBLY libOtxSharp)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/AssemblyInfo.cs.in
  ${CSHARP_SOURCE_DIRECTORY}/AssemblyInfo.cs
  @ONLY
)

csharp_add_library( 
  ${MANAGED_ASSEMBLY}
  "" 
  ${CSHARP_SOURCE_DIRECTORY}/*.cs 
)

add_dependencies(${MANAGED_ASSEMBLY}
  ${MOD_NAME})
set_lib_property(${MOD_NAME})

# Install
install(TARGETS ${MOD_NAME} 
  DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT csharp)

install(FILES
  ${CSHARP_BINARY_DIRECTORY}/${MANAGED_ASSEMBLY}.dll
  DESTINATION share/libOtxSharp COMPONENT ManagedAssembly)
