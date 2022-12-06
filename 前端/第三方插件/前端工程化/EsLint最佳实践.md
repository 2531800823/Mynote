# EsLint最佳实践

## 直接使用 umijs 配置好的 @umijs/fabric

> .eslintrc.js 文件配置

```js
module.exports = {
  extends: [require.resolve('@umijs/fabric/dist/eslint')],
  parserOptions: {
    tsconfigRootDir: __dirname,
    project: './tsconfig.json',
    createDefaultProgram: true,
  },
  rules: {
    indent: 'off',
    '@typescript-eslint/prefer-interface': 0,
    '@typescript-eslint/no-explicit-any': 0,
    '@typescript-eslint/array-type': ['error', { default: 'array-simple' }],
    'no-return-assign': 0,
    semi: ['error', 'always'],
    'no-confusing-arrow': 0,
    'no-console': 0,
    'max-len': ['error', { code: 120, ignoreComments: true, ignoreStrings: true }],
    'space-before-function-paren': [
      'error',
      { anonymous: 'never', named: 'never', asyncArrow: 'always' },
    ],
    'no-underscore-dangle': 0,
    'no-plusplus': 0,
    'react-hooks/rules-of-hooks': 'error',
    'react-hooks/exhaustive-deps': 'off',
    'no-restricted-syntax': 'off',
    'no-plusplus': 'off',
    'no-shadow': 'off',
    'no-underscore-dangle': 'off',
    '@typescript-eslint/ban-ts-ignore': 'off',
    '@typescript-eslint/no-object-literal-type-assertion': 'off',
    'consistent-return': 'off',
    'no-nested-ternary': 'off',
    'default-case': 'off',
    'no-case-declarations': 'off',
    'no-param-reassign': 'off',
    'no-useless-escape': 'off',
    'no-lonely-if': 'off',
    'no-undef': 'off',
    'jsx-a11y/accessible-emoji': 'off',
    'react/no-access-state-in-setstate': 'off',
    'react/react-in-jsx-scope': 'off',
    'react/jsx-boolean-value': ['error'],
    'react/jsx-closing-bracket-location': [2],
    'react/jsx-one-expression-per-line': 0,
    'react/prop-types': 0,
    'react/forbid-prop-types': 0,
    'react/jsx-indent': 0,
    'react/jsx-wrap-multilines': [
      'error',
      {
        declaration: false,
        assignment: false,
      },
    ],
    'react/jsx-filename-extension': 0,
    'react/state-in-constructor': 0,
    'react/jsx-props-no-spreading': 0,
    'react/destructuring-assignment': 0,
    'react/require-default-props': 0,
    'react/sort-comp': 0,
    'react/display-name': 0,
    'react/static-property-placement': 0,
    'react/jsx-no-bind': 0,
    'react/no-find-dom-node': 0,
    'react/no-unused-prop-types': 0,
    'react/default-props-match-prop-types': 0,
    'react-hooks/rules-of-hooks': 2,
    'react/function-component-definition': 0,
    'react/no-unused-class-component-methods': 0,
    'jsx-a11y/no-static-element-interactions': 0,
    'jsx-a11y/anchor-has-content': 0,
    'jsx-a11y/click-events-have-key-events': 0,
    'jsx-a11y/anchor-is-valid': 0,
    'jsx-a11y/no-noninteractive-element-interactions': 0,
    'jsx-a11y/label-has-for': 0,
    'react/no-access-state-in-setstate': 0,
    'react/no-multi-comp': 0,
    'react/no-array-index-key': 0,
    'jsx-a11y/href-no-hash': 0,
    'jsx-a11y/control-has-associated-label': 0,
    'react/jsx-no-constructed-context-values': 0,
    'react/no-unstable-nested-components': 0,
  },
};

```

### 添加 package.json 执行命令

```shell
"scripts": {
    "release": "standard-version",
    "lint": "pnpm lint:script && pnpm stylelint",
    "lint:script": "eslint src --ext .js,.jsx,.ts,.tsx --fix",
    "stylelint": "stylelint src/**/*.{css,less,scss} --fix"
  },
```



### 在 vs code 配置 保存格式化工具

```json
{
  "editor.formatOnSave": true,
  "prettier.enable": true,
  "editor.codeActionsOnSave": {
    "source.fixAll.eslint": true,
    "source.fixAll.stylelint": true
  },
  "eslint.validate": ["javascript", "javascriptreact", "vue", "typescript", "typescriptreact"],
  "stylelint.validate": ["css", "less", "postcss", "scss"],
  "editor.defaultFormatter": "dbaeumer.vscode-eslint"
}

```

### 安装 vs code 插件 eslint，stylelint

## 使用 git hooks 来操作 提交检查

### 安装 husky 

```shell
pnpm add husky -D
```

> 在 package.json 添加脚本 prepare

```json
{
  "scripts": {
    "prepare": "husky install", // 每次在 pnpm i 的时候回自动执行这个命令
  },
}
```

### 添加 hooks

```shell
npx husky install && npx husky add .husky/pre-commit "npx lint-staged"   #先初始化 添加 git hooks ，在提交前执行 npm test
```

## lint-staged 用来操作 git 暂存区，解决上面执行 全局的代码

### 安装 lint-staged

```shell
pnpm add lint-staged -D
```

> .lintstagedrc 添加 执行文件

```josn
{
  "src/**/*": "pnpm lint"
}
 //对暂存区 src 目录下 执行 pnpm lint 
```

```shell
npx husky add .husky/commit-msg "npx  commitlint --edit "${1}""  # 添加 hooks ，在提交的时候校验msg信息
```

## pnpm add commitlint -D 来约束 git 提交 msg 校验

> .commitlintrc.json 创建一个配置文件 @commitlint/config-conventional 安装来自定义修改

```json
///.commitlintrc
{
  "extends":["@commitlint/config-conventional"]
}
```

## standard-version 来控制版本管理和 changelog 生成

> 添加 package 脚本 

```json
  "scripts": {
    "release": "standard-version"
  }
```

> .versionrc.js  添加配置文件  不想用可以不添加

```js
module.exports = {
  header: "CHANGELOG ", // title

  types: [
    { type: 'feat', section: '✨Features | 新功能' },
    { type: 'fix', section: '🐛 Bug Fixes | Bug 修复' },
    { type: 'init', section: '🎉 Init | 初始化' },
    { type: 'docs', section: '✏️ Documentation | 文档' },
    { type: 'style', section: '💄 Styles | 风格' },
    { type: 'refactor', section: '♻️ Code Refactoring | 代码重构' },
    { type: 'perf', section: '⚡ Performance Improvements | 性能优化' },
    { type: 'test', section: '✅ Tests | 测试' },
    { type: 'revert', section: '⏪ Revert | 回退' },
    { type: 'build', section: '📦‍ Build System | 打包构建' },
    { type: 'chore', section: '🚀 Chore | 构建/工程依赖/配置' },
    { type: 'ci', section: '👷 Continuous Integration | CI 部署' }
  ]
}
```

## 格式化 css stylelint 继续使用 umi 模块

### 安装 stylelint-config-recess-order 对 css 来进行排序

> . stylelintrc.js 创建

```js
module.exports = {
  extends: [require.resolve('@umijs/fabric/dist/stylelint'), 'stylelint-config-recess-order'],
  rules: {
    // your rules
  },
  // "overrides": [
  //   {
  //     "files": ["**/*.less"],
  //     "customSyntax": "postcss-less"
  //   },
  //   {
  //     "files": ["**/*.scss"],
  //     "customSyntax": "postcss-scss"
  //   }
  // ]
};

```



### 
