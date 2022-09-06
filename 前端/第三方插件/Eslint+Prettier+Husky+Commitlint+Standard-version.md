# 项目模板配置

## 代码检查工具

### Eslint

- 项目安装

- ```shell
  pnpm add eslint -d
  npx eslint --init # 初始化  根据需求配置就行
  ```

  ![image-20220724214215783](./public/image-20220724214215783.png)

![image-20220724214327711](./public/image-20220724214327711.png)

![image-20220724214437148](./public/image-20220724214437148.png)

### prettier

- 安装

- ```shell
  pnpm add  prettier eslint-config-prettier eslint-plugin-prettier -D
  ```

- 在.eslintrc 中,extend 中添加 "prettier" 解决 eslint 和 prettier 的冲突

  - 因为 eslint-config-prettier 新版本更新之后,只需要写一个 "prettierr" 即可,无需多言指令

- 创建 .prettierrc

- ```json
  // 自己配置
  {
    "semi": false,
    "tabWidth": 2,
    "trailingComma": "none",
    "singleQuote": true,
    "arrowParens": "avoid"
  }
  ```

  ```json
  // 配置文件
  {
    "printWidth": 200, //行宽
    "semi": true, //分号
    "singleQuote": true, // 使用单引号
    "useTabs": false, //使用 tab 缩进
    "tabWidth": 2, //缩进
    "trailingComma": "es5", //后置逗号，多行对象、数组在最后一行增加逗号
    "arrowParens": "avoid", //箭头函数只有一个参数的时候可以忽略括号
    "bracketSpacing": true, //括号内部不要出现空格
    "proseWrap": "preserve", //换行方式 默认值。因为使用了一些折行敏感型的渲染器（如GitHub comment）而按照markdown文本样式进行折行
    "parser": "babylon", //格式化的解析器，默认是babylon
    "endOfLine": "auto", // 结尾是 \n \r \n\r auto
    "jsxSingleQuote": false, // 在jsx中使用单引号代替双引号
    "jsxBracketSameLine": false, //在jsx中把'>' 是否单独放一行
    "stylelintIntegration": false, //不让prettier使用stylelint的代码格式进行校验
    "eslintIntegration": false, //不让prettier使用eslint的代码格式进行校验
    "tslintIntegration": false, // 不让prettier使用tslint的代码格式进行校验
    "disableLanguages": ["vue"], // 不格式化vue文件，vue文件的格式化单独设置
    "htmlWhitespaceSensitivity": "ignore",
    "ignorePath": ".prettierignore", // 不使用prettier格式化的文件填写在项目的.prettierignore文件中
    "requireConfig": false // Require a 'prettierconfig' to format prettier
  }
  ```

## git 规范

#### 工具

- **husky**
  - 操作 git 钩子的工具
- **lint-staged**
  - 本地暂存代码检查工具
- **commitlint**
  - commit 信息校验工具
- **commitizen**
  - 辅助 commit 信息 ,就像这样,通过选择输入,规范提交信息

##### 安装

###### 初始化 **husky**, 会在根目录创建 **.husky** 文件夹

```shell
npm i lint-staged husky -D
npm set-script prepare "husky install" # 在package.json中添加脚本
npm run prepare # 初始化husky,将 git hooks 钩子交由,husky执行
```

- **pre-commit** 执行 **npx lint-staged** 指令

```shell
npx husky add .husky/pre-commit "npx lint-staged"
```

- 根目录创建 **.lintstagedrc.json** 文件控制检查和操作方式

```json
{
  "*.{js,jsx,ts,tsx}": ["prettier --write .", "eslint  --fix"],
  "*.md": ["prettier --write"]
}
```

###### 安装提交信息依赖

- **@commitlint/config-conventional** 这是一个规范配置,标识采用什么规范来执行消息校验, 这个默认是**_Angular_**的提交规范

```
npm i commitlint @commitlint/config-conventional -D
npx husky add .husky/commit-msg 'npx --no-install commitlint --edit "$1"'
```

| **类型** | **描述**                                               |
| -------- | ------------------------------------------------------ |
| build    | 编译相关的修改，例如发布版本、对项目构建或者依赖的改动 |
| chore    | 其他修改, 比如改变构建流程、或者增加依赖库、工具等     |
| ci       | 持续集成修改                                           |
| docs     | 文档修改                                               |
| feat     | 新特性、新功能                                         |
| fix      | 修改 bug                                               |
| perf     | 优化相关，比如提升性能、体验                           |
| refactor | 代码重构                                               |
| revert   | 回滚到上一个版本                                       |
| style    | 代码格式修改, 注意不是 css 修改                        |
| test     | 测试用例修改                                           |

- **commit-msg** 钩子执行 消息校验

- 这里也可以采用自己写的方法,来校验内容, 看下 vue@next 的消息提交

###### 安装辅助提交依赖

- 安装指令和命令行的展示信息

```shell
npm i commitizen cz-conventional-changelog -D
```

- 编写**commit**指令

```shell
 # package.json 中添加 commit 指令, 执行 `git-cz` 指令
 npm set-script commit "git-cz"
 npm i commitizen  cz-conventional-changelog -D
```

- 在 package.json 中配置

```json
"scripts": {
// ...
}
"config": {
  "commitizen": {
    "path": "cz-conventional-changelog"
  }
}
```

###### 自定义提交规范

- 变更 **commitlint.config.js** 这里采用自己定义的规范,将会覆盖上面那个,所以上面那个可以不用安装

```shell
npm i -D commitlint-config-cz  cz-customizable
```

- 根目录下创建 commitlint.config.js

```json
module.exports = {
    // 采用 cz 自定义的提交规范, > .cz-config.js
    extends: ['cz'],
    rules: {
        // 自定义规则
    }
}
```

- 增加 .cz-config.js

```js
module.exports = {
  types: [
    {value: 'feat', name: '✨ feat: 新功能'},
    {value: 'fix', name: '🐛 fix: 修复bug'},
    {value: 'init', name: '🎉 init: 初始化'},
    {value: 'docs', name: '✏️ docs: 文档变更'},
    {value: 'style', name: '💄 style: 代码的样式美化'},
    {value: 'refactor', name: '♻️ refactor: 重构'},
    {value: 'perf', name: '⚡ perf: 性能优化'},
    {value: 'test', name: '✅ test: 测试'},
    {value: 'revert', name: '⏪ revert: 回退'},
    {value: 'build', name: '📦‍ build: 打包'},
    {value: 'chore', name: '🚀 chore: 构建/工程依赖/工具'},
    {value: 'ci', name: '👷 ci: CI related changes'}
  ],
  messages: {
    type: '请选择提交类型(必填)',
    customScope: '请输入文件修改范围(可选)',
    subject: '请简要描述提交(必填)',
    body: '请输入详细描述(可选)',
    breaking: '列出任何BREAKING CHANGES(可选)',
    footer: '请输入要关闭的issue(可选)',
    confirmCommit: '确定提交此说明吗？'
  },
  allowCustomScopes: true,
  allowBreakingChanges: ['feat', 'fix'], // 当提交类型为feat、fix时才有破坏性修改选项
  subjectLimit: 72
};
```

- package.json 中,将原来 commit 配置,变更为自定义配置

```json
"config": {
    "commitizen": {
      "path": "node_modules/cz-customizable"
    }
  },
```

##### CHANGELOG 自动生成

- 开始用 standard-version 来实现吧！先来下载~

```shell
npm i -D standard-version
```

- package.json 添加

```json
{
  "scripts": {
    "release": "standard-version"
  }
}
```

- 根目录下 新建 **.versionrc.js**

```js
module.exports = {
  types: [
    {type: 'feat', section: '✨ Features | 新功能'},
    {type: 'fix', section: '🐛 Bug Fixes | Bug 修复'},
    {type: 'init', section: '🎉 Init | 初始化'},
    {type: 'docs', section: '✏️ Documentation | 文档'},
    {type: 'style', section: '💄 Styles | 风格'},
    {type: 'refactor', section: '♻️ Code Refactoring | 代码重构'},
    {type: 'perf', section: '⚡ Performance Improvements | 性能优化'},
    {type: 'test', section: '✅ Tests | 测试'},
    {type: 'revert', section: '⏪ Revert | 回退'},
    {type: 'build', section: '📦‍ Build System | 打包构建'},
    {type: 'chore', section: '🚀 Chore | 构建/工程依赖/工具'},
    {type: 'ci', section: '👷 Continuous Integration | CI 配置'}
  ]
};
```

- 配置之后，我的 CHANGELOG 就长这个样子啦！

  ![image-20220725230438881](./public/image-20220725230438881.png)
