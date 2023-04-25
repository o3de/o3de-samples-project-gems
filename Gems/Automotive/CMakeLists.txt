
# Query the gem name from the gem.json file if possible
# otherwise fallback to using Automotive
o3de_find_ancestor_gem_root(gem_root_path gem_name "${CMAKE_CURRENT_SOURCE_DIR}")
if (NOT gem_name)
    set(gem_name "Automotive")
endif()

# This indicates to the Builders applications(AssetProcessor, AssetBuilder, AssetBundler)
# that the gem should be added to the "cmake_dependencies.<project>.assetbuilder.setreg"
# which is generated when cmake configure occurs.
# Also tooling applications such as the Editor needs the CMake alias
# to see the gem as active
if(PAL_TRAIT_BUILD_HOST_TOOLS)
    ly_create_alias(NAME ${gem_name}.Builders NAMESPACE Gem)
    ly_create_alias(NAME ${gem_name}.Tool NAMESPACE Gem)
endif()
