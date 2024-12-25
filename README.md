# CD声学仿真平台项目规范

## 项目基本信息
- 项目名称: CDSimulation
- 开发环境: Qt 6.7.3, C++, CMake, MinGW, SQLite3
- 项目路径: D:\XMH_PROJECT\QT\CDSimulation
- 数据库: D:\XMH_PROJECT\QT\CDSimulation\build\cursor\database.db
- 默认账户: admin/admin
- 终端：powershell
- 平台支持：windows、linux

## 命名规范
- 类名: PascalCase (首字母大写驼峰式)
- 文件名: snake_case (小写下划线式)
- 变量名: camelCase (首字母小写驼峰式)
- UI文件: snake_case (小写下划线式)
- 类成员变量前缀: m_
- 指针变量前缀: p_

## 代码风格
- 缩进: 4空格
- 大括号: 换行
- 注释: 中文
- 编码: UTF-8

## 数据库规范
### 用户表(users)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- username: TEXT NOT NULL UNIQUE
- password: TEXT NOT NULL
- role_id: INTEGER
- status: INTEGER DEFAULT 0 (0:待审批 1:已审批 2:拒绝)

### 角色表(roles)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- name: TEXT NOT NULL
- permissions: TEXT

### 审批表(approvals)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- user_id: INTEGER
- approver_id: INTEGER
- status: INTEGER
- create_time: DATETIME
- approve_time: DATETIME

### 任务表(tasks)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- name: TEXT NOT NULL
- description: TEXT
- model_path: TEXT
- assigned_to: INTEGER
- status: INTEGER DEFAULT 0
- created_by: INTEGER
- create_time: DATETIME
- update_time: DATETIME

## 文件结构规范
database/
├── basicdata/     # 基础数据
├── materialdata/  # 材料数据
├── loaddata/      # 载荷数据
└── cddata/        # 舱段数据
    └── {型号}/
        ├── 舱段壳体/
        ├── 减震/
        ├── 吊支架/
        ├── 基座/
        ├── 法兰/
        ├── 筏架/
        ├── 管路/
        ├── 设备/
        ├── 阀门/
        └── 其它结构/

## 文件系统结构
tasks/                                     -- 任务根目录
└── username+taskname/                     -- 任务工作目录
    ├── model/                            -- 模型文件目录（从cddata复制）
    ├── drymodal/                         -- 干模态分析
    │   └── results/                      -- 干模态分析结果目录
    ├── wetmodal/                         -- 湿模态分析
    │   └── results/                      -- 湿模态分析结果目录
    ├── static/                           -- 静力学分析
    │   └── results/                      -- 静力学分析结果目录
    ├── vibration/                        -- 振动分析
    │   └── results/                      -- 振动分析结果目录
    └── acoustics/                        -- 声学分析
        └── results/                      -- 声学分析结果目录

## 权限规范
### 管理员权限
- 访问所有界面
- 用户管理
- 注册审批
- 角色管理
- 数据管理

### 工程师权限
- 访问工作台
- 查看相关数据

## UI组件命名规范
### 登录界面(login.ui)
- 角色选择: radioGroupRole
- 账号输入: lineEditUsername
- 密码输入: lineEditPassword
- 登录按钮: btnLogin
- 注册按钮: btnRegister
- 配置按钮: btnConfig

### 系统管理界面(systemmanager.ui)
- 数据管理标签: tabWidgetDataManage
- 任务管理标签: tabTaskManage
- 系统管理标签: tabSystemManage

### 配置界面(config_dialog.ui)
- 软件路径输入: lineEditSoftwarePath
- 浏览按钮: btnBrowse
- 保存按钮: btnSave
- 关闭按钮: btnClose

### 工作台界面(workbench.ui)
#### 任务接收标签页
- 任务列表表格: tableTaskList
- 状态筛选下拉框: comboBoxStatus
- 搜索框: lineEditSearch
- 接收任务按钮: btnAcceptTask
- 完成任务按钮: btnCompleteTask

#### 分析执行标签页
- 分析模块选择器: tabAnalysisModules
- 参数表格: tableParams
- 命令输出窗口: textEditOutput
- 进度条: progressBarAnalysis
- 控制按钮组:
  - 开始分析: btnStartAnalysis
  - 停止分析: btnStopAnalysis
  - 清除输出: btnClearOutput

## 业务流程
### 1. 创建任务流程
- 填写基本信息
- 选择舱段模型
- 选择分析类型
- 设置分析参数
- 指派处理人员
- 发布任务
- 系统自动创建工作目录并复制数据

### 2. 任务执行流程
- 处理人员接收任务
- 按设定顺序执行分析
- 更新分析状态
- 保存分析结果
- 完成任务

### 3. 任务管理流程
- 查看任务列表
- 跟踪任务状态
- 管理任务结果
- 删除已完成任务

## 注意事项
### 1. 数据安全
- 任务数据定期备份
- 重要结果文件保护
- 用户权限控制

### 2. 性能优化
- 大文件复制采用异步操作
- 任务列表分页显示
- 定期清理临时文件

### 3. 用户体验
- 操作过程进度提示
- 错误信息友好提示
- 常用操作快捷方式
## 三、项目结构
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
│ ├── basicdata/ # 基础数据
│ ├── materialdata/ # 材料数据
│ ├── loaddata/ # 载荷数据
│ └── cddata/ # 舱段数据
├── resources/
│ └── images/ # 图片资源
├── tests/ # 测试文件夹
├── CMakeLists.txt
└── README.md

## 四、开发规范
### 1. 命名规范
- 类名: PascalCase (首字母大写驼峰式)
- 文件名: snake_case (小写下划线式)
- 变量名: camelCase (首字母小写驼峰式)
- UI文件: snake_case (小写下划线式)
- 类成员变量前缀: m_
- 指针变量前缀: p_

### 2. 代码风格
- 缩进: 4空格
- 大括号: 换行
- 注释: 中文
- 编码: UTF-8

### 3. 版本控制
- 工具: Git
- 分支管理:
  - main: 主分支
  - develop: 开发分支
  - feature/*: 功能分支
  - bugfix/*: 修复分支

## 五、数据管理
### 1. 数据库结构
#### 用户表(users)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- username: TEXT NOT NULL UNIQUE
- password: TEXT NOT NULL
- role_id: INTEGER
- status: INTEGER DEFAULT 0 (0:待审批 1:已审批 2:拒绝)

#### 角色表(roles)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- name: TEXT NOT NULL
- permissions: TEXT

#### 审批表(approvals)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- user_id: INTEGER
- approver_id: INTEGER
- status: INTEGER
- create_time: DATETIME
- approve_time: DATETIME

#### 任务表(tasks)
- id: INTEGER PRIMARY KEY AUTOINCREMENT
- name: TEXT NOT NULL
- description: TEXT
- model_path: TEXT
- assigned_to: INTEGER
- status: INTEGER DEFAULT 0
- created_by: INTEGER
- create_time: DATETIME
- update_time: DATETIME

### 2. 文件系统结构
#### 数据目录
database/
├── basicdata/ # 基础数据
├── materialdata/ # 材料数据
├── loaddata/ # 载荷数据
└── cddata/ # 舱段数据
└── {型号}/
├── 舱段壳体/
├── 减震/
├── 吊支架/
├── 基座/
├── 法兰/
├── 筏架/
├── 管路/
├── 设备/
├── 阀门/
└── 其它结构/
#### 任务目录
tasks/ -- 任务根目录
└── username+taskname/ -- 任务工作目录
├── model/ -- 模型文件目录（从cddata复制）
├── drymodal/ -- 干模态分析
│ └── results/ -- 干模态分析结果目录
├── wetmodal/ -- 湿模态分析
│ └── results/ -- 湿模态分析结果目录
├── static/ -- 静力学分析
│ └── results/ -- 静力学分析结果目录
├── vibration/ -- 振动分析
│ └── results/ -- 振动分析结果目录
└── acoustics/ -- 声学分析
└── results/ -- 声学分析结果目录

## 六、界面设计
### 1. 登录界面(login.ui)
- 组件命名：
  - 角色选择: radioGroupRole
  - 账号输入: lineEditUsername
  - 密码输入: lineEditPassword
  - 登录按钮: btnLogin
  - 注册按钮: btnRegister
  - 配置按钮: btnConfig

### 2. 系统管理界面(systemmanager.ui)
#### 数据管理标签页
- 基础数据库标签
  - 树列表：显示basicdata目录
  - 图片预览框
  - 文本预览框
- 舱段数据库标签
  - 源数据树列表
  - 目标数据树列表
  - 图片预览框
  - 文本预览框
  - 操作按钮组

#### 任务管理标签页
- 任务列表区域
- 任务定义区域
- 操作按钮组

### 3. 工作台界面(workbench.ui)
#### 任务接收标签页
- 任务列表表格: tableTaskList
- 状态筛选下拉框: comboBoxStatus
- 搜索框: lineEditSearch
- 接收任务按钮: btnAcceptTask
- 完成任务按钮: btnCompleteTask

#### 分析执行标签页
- 分析模块选择器: tabAnalysisModules
  - 模态分析模块
  - 静力学分析模块
  - 振动分析模块
  - 声学分析模块
  - 水下仿真模块
- 参数表格: tableParams
- 命令输出窗口: textEditOutput
- 进度条: progressBarAnalysis
- 控制按钮组

### 4. 配置界面(config_dialog.ui)
- 软件路径输入: lineEditSoftwarePath
- 浏览按钮: btnBrowse
- 保存按钮: btnSave
- 关闭按钮: btnClose

## 七、权限管理
### 1. 管理员权限
- 访问所有界面
- 用户管理
- 注册审批
- 角色管理
- 数据管理

### 2. 工程师权限
- 访问工作台
- 查看相关数据

## 八、业务流程
### 1. 创建任务流程
- 填写基本信息
- 选择舱段模型
- 选择分析类型
- 设置分析参数
- 指派处理人员
- 发布任务
- 系统自动创建工作目录并复制数据

### 2. 任务执行流程
- 处理人员接收任务
- 按设定顺序执行分析
- 更新分析状态
- 保存分析结果
- 完成任务

### 3. 任务管理流程
- 查看任务列表
- 跟踪任务状态
- 管理任务结果
- 删除已完成任务

## 九、部署要求
- 操作系统: Windows/Linux
- 最小内存: 8GB
- 存储空间: 根据数据量确定
- 依赖软件: Qt运行环境

## 十、注意事项
### 1. 数据安全
- 任务数据定期备份
- 重要结果文件保护
- 用户权限控制

### 2. 性能优化
- 大文件复制采用异步操作
- 任务列表分页显示
- 定期清理临时文件

### 3. 用户体验
- 操作过程进度提示
- 错误信息友好提示
- 常用操作快捷方式
