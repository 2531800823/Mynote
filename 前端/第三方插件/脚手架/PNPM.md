# PNPM workspace工作流管理monorepo

```js
// 安装
npm i pnpm -g
// 配置 包路径
pnpm config set store-dir /path/to/.pnpm-store
```

## 基本使用

```js
// 初始化
pnpm init
// 安装 
pnpm add 
// 删除
pnpm remove
// 运行
pnpm run ... 
// or
pnpm ...
```

## 通过 vite 创建项目

```js
pnpm create vite <profileName> 
// 实例
pnpm create vite my-vue-app -- --template vue
```

## 删除不需要的包

```js
pnpm prune
// 参数
// --prod 删除在 devDependencies 中列出的软件包。
// --no-optional 删除在 optionalDependencies 中列出的软件包。
// 删除本地 store 里的包
pnpm store prune
```

## 执行脚本命令，和lerna 一样

```js
pnpm exec jest
// 参数
// --recursive, -r 递归 例如：
pnpm -r exec rm -rf node_modules
// --filter  过滤包 

```

## 开启 workspace , monorepo

```yaml
// pnpm-workspace.yaml
packages:
  # all packages in direct subdirs of packages/
  - 'packages/**'
  - 'apps/**'

```

### 安装依赖

```js
// 安装根目录的开发依赖
pnpm add -Dw axios
```

### 查看依赖

```js
pnpm list 
// 查看全局依赖
pnpm list -g
// 检查过期依赖
pnpm outdated
```

## 发布依赖包

```js
// 推送单个包
pnpm publish
// 推送多个
pnpm -r publish

// 差一个 更新 version 的 真是项目装一下

// 给子包下的 package.json 添加，代表所有包都是公有
 {
  "publishConfig": {
    "access": "public"
  },
 }
// or 加上 --access
 pnpm -r publish --access
```



## 管理 node 版本 可以实现 nvm 功能

```js
// 本地安装 node 版本
pnpm env use <node版本>
// 全局安装
pnpm env use --global <node版本>
```



## 查看包路径

```js
pnpm store path
// 设置  D:\nodejs\.pnpm-store
pnpm config set store-dir /path/to/.pnpm-store
```



## 配置

```js
// package.json
{
// 指定使用的node版本和pnpm版本
 "engines": {
        "node": ">=10",
        "pnpm": ">=3"
    },
    // 对于本地依赖项设置为 true，则包将被硬链接到模块目录，而不是进行符号链接。
   "dependenciesMeta": {
    "@liusp-cli/core": {
      "injected": true
    }
  }
}
```

### 独立项目配置

```
// .npmrc
....
```

