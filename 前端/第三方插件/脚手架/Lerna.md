# Lerna

## 安装

```shell
npm i lerna -D

// 初始化： 
npx lerna init
```

## 创建包

```
npx lerna create core
```

## 添加依赖

```shell
// 给所有项目添加
npx lerna add axios  
```

#### 给指定安装

```shell
npx lerna add axios packages/@liusp-cli/core
// or 
npx lerna add axios  --scope=@liusp-cli/core
```

## 给所有的包 都执行一个命令

```shell
npx lerna exec --  //要执行的命令

// 实例： 
npx lerna exec -- rm -rf node_modules/   

// 所有包下 执行了  
rm -rf node_modules/   
```

#### 给指定包 执行命令

```shell
npx lerna exec --scope=@liusp-cli/core  rm -rf node_modules/   
```

##  给所有包 装依赖 并 链接 lerna link

```
npx lerna bootstrap
```

## 手动创建本地包的关联

```shell
lerna add @liusp-cli/core --scope @liusp-cli/utils
```

## 执行所有包下的命令

```shell
// 执行的是 package.json 里 scripts 下的
npx lerna run  dev 
// 指定包下的命令
npx lerna run --scope=@liusp-cli/core  dev
```

## 清空依赖 删除所有项目的 node_modules(除去 根目录)

```
npx lerna clean
```

## 自动更新版本

```
npx lerna version
```

## 发布

```
lerna publish
```

## 列出所有的 package 下的 包

```
lerna list
```

## 检查上次发布到现在更改的包

```
lerna changed
```

## 查看 lerna 的运行环境信息

```
lerna info
```



## 配置信息

```js
// lerna.json
{
    // 指定包所在的目录，可以支持多个目录
    packages:[
        "packages/*"
    ],
    // 允许指定命令使用的client， 默认是 npm
    npmClient:'yarn',
    // 使用 yarn workspaces 管理 Monorepo
    useWorkspaces:true,
    
    "command": {
    "bootstrap": {
       // 指定默认传给 lerna bootstrap 命令的参数
      "npmClientArgs": [
        "--no-package-lock"
      ]
    },
    "publish": {
      "npmClient": "npm",
       // 指定那些目录或者文件的变更不用触发 package 版本的变更
      "ignoreChanges": [
        "**/*.md",
        "**/test/**"
      ],
      "message": "chore(release): publish",
      "registry": "https://registry.npmjs.org",
      "conventionalCommits": true,
       // 把包设置成公开的，不开 npm 不让发布
       "access": "public",
    }
  }
}
```



# 错误记录

> lerna ERR! E402 You must sign up for private packages

```js
// 给子包下的 package.json 添加，代表所有包都是公有
 {
  "publishConfig": {
    "access": "public"
  },
 }
```

> 使用 yarn 运行项目

```js
 yarn workspace @lerna-publish/core run dev
 // @lerna-publish/core 不是包的路径名， 要执行包下package.json里面的name
```

