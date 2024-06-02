# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/frontend_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/frontend_autogen.dir/ParseCache.txt"
  "frontend_autogen"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldModel_autogen.dir/AutogenUsed.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldModel_autogen.dir/ParseCache.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldModelplugin_autogen.dir/AutogenUsed.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldModelplugin_autogen.dir/ParseCache.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldModelplugin_init_autogen.dir/AutogenUsed.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldModelplugin_init_autogen.dir/ParseCache.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfield_autogen.dir/AutogenUsed.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfield_autogen.dir/ParseCache.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldplugin_autogen.dir/AutogenUsed.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldplugin_autogen.dir/ParseCache.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldplugin_init_autogen.dir/AutogenUsed.txt"
  "modules/ValidationTextfield/CMakeFiles/ValidationTextfieldplugin_init_autogen.dir/ParseCache.txt"
  "modules/ValidationTextfield/ValidationTextfieldModel_autogen"
  "modules/ValidationTextfield/ValidationTextfieldModelplugin_autogen"
  "modules/ValidationTextfield/ValidationTextfieldModelplugin_init_autogen"
  "modules/ValidationTextfield/ValidationTextfield_autogen"
  "modules/ValidationTextfield/ValidationTextfieldplugin_autogen"
  "modules/ValidationTextfield/ValidationTextfieldplugin_init_autogen"
  "tests/integration/CMakeFiles/tst_integration_autogen.dir/AutogenUsed.txt"
  "tests/integration/CMakeFiles/tst_integration_autogen.dir/ParseCache.txt"
  "tests/integration/tst_integration_autogen"
  "tests/unit/CMakeFiles/tst_unit_autogen.dir/AutogenUsed.txt"
  "tests/unit/CMakeFiles/tst_unit_autogen.dir/ParseCache.txt"
  "tests/unit/tst_unit_autogen"
  )
endif()
