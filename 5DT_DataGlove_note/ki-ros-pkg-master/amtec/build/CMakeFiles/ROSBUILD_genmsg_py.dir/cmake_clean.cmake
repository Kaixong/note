FILE(REMOVE_RECURSE
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/amtec/msg/__init__.py"
  "../src/amtec/msg/_FastrakPose.py"
  "../src/amtec/msg/_AmtecState.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
