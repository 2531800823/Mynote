# NPM



### 镜像源

> ```
> https://registry.npmjs.org/
> ```

### 设置命令启动

```shell
npm set-script prepare "husky install"     # 在package.json中添加脚本
```

### 删除 node_modules 

```json
"scripts": {
    "clear": "rimraf node_modules"
  },
```

### shamefully-hoist

默认情况下，pnpm 创建一个半严格的 node_modules，这意味着依赖项可以访问未声明的依赖项，但 node_modules 之外的模块不行。 通过这种布局，生态系统中的大多数的包都可以正常工作。 但是，如果某些工具仅在提升的依赖项位于根目录的 node_modules 时才有效，您可以将其设置为 true 来为您提升它们。

```shell
pnpm config set shamefully-hoist true
```



### version

```shell
npm version patch # 小版本号+1  -> 0.0.1
npm version preminor # 中版本号+1 -> 0.1.0
npm version premajor # 大版本号+1 -> 1.0.0
...
npm version patch -m '描述信息'
```



## 远程操作

### 登录

npm login 

### 发布

npm publish



### 发布包插件  np模块





## 配置

```js
{
  "config": {
    "port": "8080"
  },
  // 生产
  "dependencies": {
    "package-1": "^3.1.4"
  },
      // devDependencies 开发依赖，
      // peerDependencies 使用本模板要装的包
      // optionalDependencies 可选的依赖项可以与包一起使用，但不是必需的
      
}
```





