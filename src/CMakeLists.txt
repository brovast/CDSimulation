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
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    ${PROJECT_UI}
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
) 