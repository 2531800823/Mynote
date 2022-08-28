# NPM



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



@emotion/react , umi , Ant Design Mobile , react, ts，postcss-px-to-viewport ， Swiper
