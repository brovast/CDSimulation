set(PROJECT_SOURCES
    main.cpp
    core/database.cpp
    core/user.cpp
    views/login.cpp
    utils/config.cpp
    views/register.cpp
    views/config_dialog.cpp
    views/system/systemmanager.cpp
    views/workbench.cpp
    views/system/user_edit_dialog.cpp
    views/system/usermanager.cpp
    views/system/approvalmanager.cpp
    views/system/rolemanager.cpp
    views/system/structure_hierarchy_dialog.cpp
)

set(PROJECT_HEADERS
    core/database.h
    core/user.h
    views/login.h
    utils/config.h
    views/register.h
    views/config_dialog.h
    views/system/systemmanager.h
    views/workbench.h
    views/system/user_edit_dialog.h
    views/system/usermanager.h
    views/system/approvalmanager.h
    views/system/structure_hierarchy_dialog.h
)

# 添加UI文件
set(PROJECT_UI
    views/login.ui
    views/register.ui
    views/config_dialog.ui
    views/system/systemmanager.ui
    views/workbench.ui
    views/system/user_edit_dialog.ui
    views/system/usermanager.ui
    views/system/approvalmanager.ui
    views/system/structure_hierarchy_dialog.ui
)

# 添加分析模块源文件
set(ANALYSIS_SOURCES
    views/analysis/dry_modal_analysis_module.cpp
    views/analysis/wet_modal_analysis_module.cpp
    views/analysis/static_analysis_module.cpp
    views/analysis/vibration_analysis_module.cpp
    views/analysis/acoustic_analysis_module.cpp
)

# 添加分析模块头文件
set(ANALYSIS_HEADERS
    views/analysis/dry_modal_analysis_module.h
    views/analysis/wet_modal_analysis_module.h
    views/analysis/static_analysis_module.h
    views/analysis/vibration_analysis_module.h
    views/analysis/acoustic_analysis_module.h
)

# 添加分析模块UI文件
set(ANALYSIS_UI
    views/analysis/dry_modal_analysis_module.ui
    views/analysis/wet_modal_analysis_module.ui
    views/analysis/static_analysis_module.ui
    views/analysis/vibration_analysis_module.ui
    views/analysis/acoustic_analysis_module.ui
)

# 将ANALYSIS_UI添加到PROJECT_UI中
set(PROJECT_UI
    ${PROJECT_UI}
    ${ANALYSIS_UI}
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    ${ANALYSIS_SOURCES}
    ${ANALYSIS_HEADERS}
    ${PROJECT_UI}
    ${ANALYSIS_UI}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/views
    ${CMAKE_CURRENT_SOURCE_DIR}/views/system
    ${CMAKE_CURRENT_SOURCE_DIR}/views/analysis
) 