#项目概述：
开发一款数字化CD声学仿真平台，实现登录、用户管理、角色管理、审批流程、数据管理、任务管理等功能。
通过在系统管理工作台界面中具备命令行调用仿真软件的功能，数据采用database文件夹进行管理。

# CD声学仿真平台项目规范

## 项目路径
项目根目录: D:\XMH_PROJECT\QT\CDSimulation

## 数据库位置
sqlite3数据库: D:\XMH_PROJECT\QT\CDSimulation\build\cursor\src\database\database.db
超级管理员: admin 密码: admin
数据文件夹: exe同级目录下的database文件夹

## 项目基本信息
- 项目名称: CDSimulation
- 开发环境: 
  - Qt 6.7.3
  - C++
  - CMake
  - MinGW
  - SQLite3
  - UI文件

## 项目结构
project/
├── src/
│ ├── main.cpp
│ ├── core/
│ │ ├── user.h/cpp # 用户类
│ │ ├── role.h/cpp # 角色类
│ │ ├── database.h/cpp # 数据库管理
│ │ └── filemanager.h/cpp # 文件管理
│ ├── models/
│ │ ├── usermodel.h/cpp # 用户数据模型
│ │ ├── taskmodel.h/cpp # 任务数据模型
│ │ └── datamodel.h/cpp # 数据管理模型
│ ├── views/
│ │ ├── login.ui/h/cpp # 登录界面
│ │ ├── workbench.ui/h/cpp # 工作台界面
│ │ ├── config_dialog.ui/h/cpp # 配置界面
│ │ └── system/
│ │ ├── systemmanager.ui/h/cpp # 系统管理主界面
│ │ ├── usermanager.ui/h/cpp # 用户管理
│ │ ├── rolemanager.ui/h/cpp # 角色管理
│ │ ├── approvalflow.ui/h/cpp # 审批流程
│ │ ├── datamanager.ui/h/cpp # 数据管理
│ │ └── taskmanager.ui/h/cpp # 任务管理
│ └── utils/
│ ├── config.h/cpp # 配置管理
│ └── logger.h/cpp # 日志管理
├── database/
│ ├── basicdata/ # 基础数据文件夹
│ └── cddata/ # 舱段数据文件夹
├── resources/
│ └── images/ # 图片资源
├── tests/ # 测试文件夹
├── CMakeLists.txt
└── README.md

## 界面规范

### 1. 登录界面 (login.ui)
- 组件：
  - 角色选择单选按钮组（管理员/工程师）
  - 账号输入框
  - 密码输入框
  - 登录按钮
  - 注册按钮
  - 配置按钮

### 2. 系统管理界面 (systemmanager.ui)
- 标签页组件：
  - 数据管理标签(QTabWidget: tabWidgetDataManage)
    ├── 基础数据库标签(QWidget: tabBasicData)
    │   - 组件构成：
    │     ├── 树列表（显示basicdata目录）(QTreeView: treeViewBasicData)
    │     ├── 图片预览框(QLabel: labelImagePreview)
    │     └── 文本预览框(QTextEdit: textEditContentPreview)
    │   - 功能描述：
    │     - 树列表显示basicdata中所有层级和文件
    │     - 选中某层级时：
    │       - 图片框显示该层级下的图片文件
    │       - 文本框显示该层级下的txt文件内容
    │
    ├── 舱段数据库标签（待实现）(QWidget: tabCompartmentData)
    │   - 组件构成：
    │     ├── 源数据树列表（显示basicdata目录）(QTreeView: treeViewCDBasicData)
    │     ├── 目标数据树列表（显示cddata目录）(QTreeView: treeViewCDData)
    │     │   └── 数据结构：
    │     │       ├── 型号A/              # 用户自定义型号名称
    │     │       │   ├── 舱段壳体/      # 默认结构类型
    │     │       │   ├── 减震/
    │     │       │   ├── 吊支架/
    │     │       │   ├── 基座/
    │     │       │   ├── 法兰/
    │     │       │   ├── 筏架/
    │     │       │   ├── 管路/
    │     │       │   ├── 设备/
    │     │       │   ├── 阀门/
    │     │       │   ├── 其它结构/
    │     │       │   └── [自定义结构]/  # 用户可新增
    │     │       └── [其他型号]/        # 用户可新增
    │     ├── 图片预览框(QLabel: labelCDImagePreview)
    │     ├── 文本预览框(QTextEdit: textEditCDContentPreview)
    │     └── 操作按钮组
    │         ├── 新建型号按钮(QPushButton: btnNewModel)
    │         ├── 添加结构类型按钮(QPushButton: btnAddStructureType)
    │         ├── 数据复制按钮(QPushButton: btnCopyData)
    │         └── 删除按钮(QPushButton: btnDelete)
    │   - 功能描述：
    │     - 左侧树列表显示basicdata完整层级
    │     - 右侧树列表显示cddata的型号-结构类型层级
    │     - 选中任一层级时：
    │       - 图片框显示该层级下的图片文件
    │       - 文本框显示该层级下的txt文件内容
    │     - 型号管理：
    │       - 新建型号（自定义名称）
    │       - 自动创建默认结构类型文件夹
    │       - 支持型号的维护管理
    │     - 结构类型管理：
    │       - 默认创建基本结构类型
    │       - 支持新增自定义结构类型
    │       - 结构类型的维护管理
    │     - 数据操作：
    │       - 将basicdata中选中的文件夹
    │       - 复制到cddata对应型号的结构类型中
    │
    ├── 水下仿真数据库标签（预留）(QWidget: tabUnderwaterSimulation)
    ├── 材料库标签（预留）(QWidget: tabMaterialLibrary)
    └── 载荷库标签（预留）(QWidget: tabLoadLibrary)
  - 任务管理标签（待实现）(QWidget: tabTaskManage)
    ├── 任务列表区域(QWidget: widgetTaskList)
    │   - 组件构成：
    │     ├── 任务表格(QTableWidget: tableTaskList)
    │     │   ├── 任务ID
    │     │   ├── 任务名称
    │     │   ├── 任务类型（多个类型用逗号分隔）
    │     │   ├── 任务状态
    │     │   ├── 指派人员
    │     │   ├── 创建时间
    │     │   └── 操作按钮
    │     └── 任务筛选器
    │         ├── 状态筛选(QComboBox: comboBoxStatusFilter)
    │         ├── 类型筛选(QComboBox: comboBoxTypeFilter)
    │         └── 搜索框(QLineEdit: lineEditSearch)
    │
    ├── 任务定义区域
    │   - 基本信息
    │     ├── 任务名称输入框(QLineEdit: lineEditTaskName)
    │     └── 任务描述文本框(QTextEdit: textEditTaskDescription)
    │   
    │   - 舱段模型选择
    │     ├── 型号选择组合框(QComboBox: comboBoxModelSelect)
    │     │   - 自动加载cddata目录下的型号文件夹
    │     │   - 下拉显示所有可用型号
    │     │   - 当型号变化时更新显示路径
    │     └── 选中路径显示(QLineEdit: lineEditModelPath)
    │   
    │   - 任务类型选择
    │     ├── 分组框（QGroupBox: groupBoxTaskType)用于分类显示
    │     │   ├── 模态分析组(QGroupBox: groupBoxModalAnalysis)
    │     │   │   ├── 干模态分析（QCheckBox: checkBoxDryModalAnalysis)
    │     │   │   └── 湿模态分析（QCheckBox: checkBoxWetModalAnalysis)
    │     │   │
    │     │   ├── 静力学分析组(QGroupBox: groupBoxStaticAnalysis)
    │     │   │   ├── 壳体强度分析（QCheckBox: checkBoxShellStrengthAnalysis)
    │     │   │   └── 阀架强度分析（QCheckBox: checkBoxValveFrameStrengthAnalysis)
    │     │   │
    │     │   ├── 振动分析组(QGroupBox: groupBoxVibrationAnalysis)
    │     │   │   ├── 单舷激励分析（QCheckBox: checkBoxSingleSideExcitationAnalysis)
    │     │   │   └── 双舷激励分析（QCheckBox: checkBoxDoubleSideExcitationAnalysis)
    │     │   │
    │     │   └── 源频特性分析组(QGroupBox: groupBoxSourceFrequencyAnalysis)
    │     │       └── [预留5项分析类型]（QCheckBox: checkBoxSourceFrequencyAnalysis)
    │     │
    │     └── 分析参数设置区域(QStackedWidget: stackedWidgetAnalysisParam)
    │         - 根据选择的分析类型动态显示对应参数设置界面
    │   
    │   - 任务指派
    │     ├── 人员选择组合框(QComboBox: comboBoxUserSelect)
    │     │   - 从数据库加载有效用户列表
    │     │   - 可根据角色筛选显示
    │     │   - 显示格式：用户名（角色）
    │     └── 指派说明输入框(QLineEdit: lineEditTaskDescription)
    │
    └── 操作按钮组
        ├── 任务发布按钮(QPushButton: btnTaskPublish)
        │   - 验证必填信息
        │   - 创建任务记录
        │   - 复制选中的舱段数据到用户工作目录
        │   - 创建任务-分析类型关联记录
        └── 删除任务按钮(QPushButton: btnTaskDelete)
            - 仅允许删除已完成或已取消的任务
            - 删除相关数据和记录
    - 功能描述：
      - 任务列表管理：
        - 显示所有任务基本信息
        - 支持按状态、类型筛选
        - 支持按名称搜索
        - 任务状态实时更新
      
      - 任务定义功能：
        - 创建新任务
        - 选择舱段模型数据
        - 支持多个分析类型的选择和参数设置
        - 分配任务处理人员
      
      - 数据处理：
        - 自动创建任务工作目录
        - 复制选中的舱段数据到用户工作目录
        - 任务执行结果管理
      
      - 任务操作：
        - 发布新任务
        - 修改任务状态
        - 删除已完成任务
    - 数据结构：
      -- 任务表
      CREATE TABLE tasks (
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          name TEXT NOT NULL,                    -- 任务名称
          description TEXT,                      -- 任务描述
          model_path TEXT,                       -- 舱段模型路径
          assigned_to INTEGER,                   -- 指派人员ID
          status INTEGER DEFAULT 0,              -- 0:待处理 1:进行中 2:已完成 3:已取消
          created_by INTEGER,                    -- 创建人ID
          create_time DATETIME,                  -- 创建时间
          update_time DATETIME,                  -- 更新时间
          FOREIGN KEY(assigned_to) REFERENCES users(id),
          FOREIGN KEY(created_by) REFERENCES users(id)
      );

      -- 分析类型表
      CREATE TABLE analysis_types (
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          category TEXT NOT NULL,                -- 分析类别（模态分析/静力学分析/振动分析/源频特性分析）
          name TEXT NOT NULL,                    -- 具体类型名称
          description TEXT,                      -- 类型描述
          parameters_template TEXT,              -- 参数模板（JSON格式）
          enabled INTEGER DEFAULT 1              -- 是否启用
      );

      -- 任务-分析类型关联表
      CREATE TABLE task_analysis_types (
          id INTEGER PRIMARY KEY AUTOINCREMENT,
          task_id INTEGER,                       -- 关联任务ID
          analysis_type_id INTEGER,              -- 关联分析类型ID
          execution_order INTEGER,               -- 执行顺序
          parameters TEXT,                       -- 具体参数（JSON格式）
          status INTEGER DEFAULT 0,              -- 0:未开始 1:进行中 2:已完成 3:失败
          start_time DATETIME,                   -- 开始时间
          end_time DATETIME,                     -- 结束时间
          result_path TEXT,                      -- 结果文件路径
          FOREIGN KEY(task_id) REFERENCES tasks(id),
          FOREIGN KEY(analysis_type_id) REFERENCES analysis_types(id)
      );

    - 文件系统结构：
      tasks/                                     -- 任务根目录
      ├── {task_id}/                            -- 任务工作目录
      │   ├── model/                            -- 模型文件目录（从cddata复制）
      │   ├── analysis/                         -- 分析工作目录
      │   │   ├── modal/                        -- 模态分析
      │   │   ├── static/                       -- 静力学分析
      │   │   ├── vibration/                    -- 振动分析
      │   │   └── frequency/                    -- 源频特性分析
      │   └── results/                          -- 结果文件目录
      └── templates/                            -- 分析参数模板目录

    - 业务流程：
      1. 创建任务流程
         - 填写基本信息
         - 选择舱段模型
         - 选择分析类型
         - 设置分析参数
         - 指派处理人员
         - 发布任务
         - 系统自动创建工作目录并复制数据

      2. 任务执行流程
         - 处理人员接收任务
         - 按设定顺序执行分析
         - 更新分析状态
         - 保存分析结果
         - 完成任务

      3. 任务管理流程
         - 查看任务列表
         - 跟踪任务状态
         - 管理任务结果
         - 删除已完成任务

    - 注意事项：
      1. 数据安全
         - 任务数据定期备份
         - 重要结果文件保护
         - 用户权限控制

      2. 性能优化
         - 大文件复制采用异步操作
         - 任务列表分页显示
         - 定期清理临时文件

      3. 用户体验
         - 操作过程进度提示
         - 错误信息友好提示
         - 常用操作快捷方式


  - 系统管理标签
    - 用户管理子页面
    - 注册审批流程子页面
    - 角色管理子页面

### 3. 工作台界面 (workbench.ui)
- 预留界面框架

### 4. 配置界面 (config_dialog.ui)
- 组件：
  - 动态配置项组
    - 软件名称标签
    - 软件路径输入框
    - 路径浏览按钮
    - 命令行调用参数输入框
  - 功能按钮组
    - 添加配置项按钮
    - 保存按钮
    - 关闭按钮

## 数据管理规范
基于SQLite3数据库管理用于管理用户、审批、角色，数据库文件位于database/文件夹下，用于管理所有的文件数据。

### 数据库结构
-- 用户表
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    password TEXT NOT NULL,
    role_id INTEGER,
    status INTEGER DEFAULT 0 -- 0:待审批 1:已审批 2:拒绝
);

-- 角色表
CREATE TABLE roles (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    permissions TEXT
);

-- 审批流程表
CREATE TABLE approvals (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER,
    approver_id INTEGER,
    status INTEGER,
    create_time DATETIME,
    approve_time DATETIME
);

### 配置文件结构
- config/
  - software_config.ini    # 软件配置文件
  
### 文件系统结构
- database/
  - basicdata/     # 基础数据
  - cddata/        # 舱段数据

## 业务逻辑规范
### 配置管理
1. 配置界面流程
   - 启动时加载现有配置
   - 支持动态添加配置项
   - 配置项验证
   - 配置保存与更新

2. 配置文件管理
   - JSON格式存储配置
   - 配置文件的读写操作
   - 配置有效性验证

### 用户管理
1. 注册流程
   - 用户提交注册信息
   - 存入数据库，状态为待审批
   - 管理员审批并分配角色
   - 更新用户状态

2. 登录流程
   - 验证用户名密码
   - 检查用户状态和角色
   - 根据角色权限跳转相应界面

### 数据管理
1. 基础数据管理
   - 树形显示basicdata目录结构
   - 预览选中项的图片和文本

2. 舱段数据管理
   - 双树形显示basicdata和cddata
   - 支持数据复制操作

3. 预留界面框架，功能待定

## 权限控制
- 管理员权限：
  - 访问所有界面
  - 管理用户
  - 审批注册
  - 管理角色
  - 管理数据

- 工程师权限：
  - 仅访问工作台界面
  - 查看相关数据

## 文件命名规范
- 类名：首字母大写驼峰式
- 文件名：小写下划线式
- 变量名：首字母小写驼峰式
- UI文件：小写下划线式

## 代码风格
- 使用4空格缩进
- 大括号换行
- 类成员变量前缀使用m_
- 指针变量前缀使用p_