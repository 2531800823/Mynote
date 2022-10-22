# WebPack

## 使用

### 安装

```shell
pnpm add webpack webpack-cli -D
```

### 配置

```
// webpack.config.js
module.export={ // ... }
```

### 编译 启动

```shell
webpack --config ./webpack.config.js --env production
# 启动服务 devserver
webpack serve --config ./webpack.config.js --env development
```

### 小技巧

#### 智能提示

```js
// webpack.config.js 添加会有点智能提示
/** * @type {import('webpack').Configuration} */ // 提示
```



## 配置

### 相对路径 [content](https://webpack.docschina.org/configuration/entry-context/#context)

```js
context: path.resolve(__dirname, './'), // 生成的绝对路径
```



### 入口  [entry](https://webpack.docschina.org/concepts/entry-points/#single-entry-shorthand-syntax )

```js
// 单入口
entry: './path/to/my/entry/file.js',  
entry: {
    main: './path/to/my/entry/file.js',
  },
// 多入口
entry: ['./src/file_1.js', './src/file_2.js'],
entry: {
   	app: './src/app.js',
	adminApp: './src/adminApp.js',
},    
```



### 出口 [output](https://webpack.docschina.org/concepts/output/#usage)

```js
  output: {
    filename: 'bundle.js',  // 文件名
    path: path.resolve(__dirname, 'dist'), // 生成路径
    // publicPath: './', // 打包后的静态资源路径会加上
		clean: true,									// 每次打包后是否清除dist
		hashDigestLength: 5,							// hash值的长度
		assetModuleFilename: '[name][contenthash][ext] 	// 静态资源的文件名
	   libraryTarget: 'umd', // 打包出来的 支持的文件
    library: 'liushipeng', // 打包对象给 root(window) 来挂在这个小户型
    globalObject: 'this', // 设置全局的 root，在浏览器下是window node下是global
  },
```



### 模式 [mode](https://webpack.docschina.org/configuration/mode/)

```js
mode: 'development',  // production
    // 将环境变量换成 process.env.NODE_ENV=mode
```



### [devtool ](https://webpack.docschina.org/configuration/devtool/#devtool) 选择打包对应代码  [source map](http://blog.teamtreehouse.com/introduction-source-maps)

```js
// 最佳实践，建议 vue 使用 'source-map' ，react 使用：cheap-module-scurce-map, 生产直接关掉 false||不写
  devtool: 'source-map', // 生成 source-map 来查找文件错误位置
```



### 构建目标 [target](https://webpack.docschina.org/configuration/target/)

```js
// webpack 能够为多种环境或 target 构建编译。想要理解什么是 target 的详细信息， 请阅读 target 概念页面。
target:'node', // node 环境
```



### 外部扩展 [externals](https://webpack.docschina.org/configuration/externals/)

```js
  // 使用 CDN  需要在 html 页面加上 script ， 在生产环境下使用
  externals: {
    lodash: '_', // key 库名，value 暴露出来的对象
    dayjs: 'dayjs',
          jquery: 'jQuery',
  },
```



### 解析 [Resolve](https://webpack.docschina.org/configuration/resolve/#resolve)

```js
// 模块解析  使用的是 enhanced-resolve 模块，来配置的
  resolve: {
    extendsions: ['.js', '.json', '.wasm', 'jsx'], // 添加了，引入文件就不用其他几添加后缀了
    // 配置别名
    alias: {
      '@': path.resolve(__dirname, 'src/'),
    },
        modules: ['node_modules'], // 告诉 webpack 解析模块时应该搜索的目录
  },
```



### 优化 [Optimization](https://webpack.docschina.org/configuration/optimization/)

```js
optimization: {
    // 摇树优化， Tree shaking
    // 给每个函数都标记一个用没用、生产环境下默认 true
    // 只摇树，标记出那些函数没有被使用，然后通过下面 terser 配置给删除掉
    usedExports: true,
    // 对有副作用的文件做标记，导入了没有使用的文件
    // 可以在 package.json 配置 sideEffects: false 所有文件都没，true 都有。['./a/xx/xx.js',"**.css"] // 指定有副作用文件
    // 也可以在  loader 配置添加  css 都是 sideEffects： true
    sideEffects: true,

    // 作用域提升
    concatenateModules: true, // 生产环境下 自动开启

    // id 按照什么算法生成 natured 自然数，named 使用包目录(开发环境默认)，deterministic(生产) 针对相同文件生成
    chunkIds: 'deterministic',
    // 对runtime 运行时的代码做一个抽离，两个文件都 import 引入了模块  true 和 multiple一样打包多个, single打包成一个
    runtimeChunk: true,

    // 对代码进行压缩相关操作 terser-webpack-plugin , 对代码做丑化。terser
    minimize: true,
    minimizer: [
      new TerserPlugin({
        parallel: true, // 使用多个进程并发
        extractComments: false, // 把所有注释单独抽离成一个文件
        terserOptions: {
          // 更多的 terser 这个插件的配置，可以在这里使用
          // https://github.com/webpack-contrib/terser-webpack-plugin#terseroptions
        },
      }),
    ],
    // 避免重复依赖
    splitChunks: {
      // 只有异步的时候才会做分离 async 异步，initial 同步，all 全部
      chunks: 'all',
      minSize: 20000, // 最小的包大小 默认20000-> 20kb 超过就分离
      maxSize: 20000, // 将大于 maxSize 拆分为不小于 minSize 的包
      minChunks: 1, // 最少被引入几次 拆分
      // 缓存
      cacheGroup: {
        // 把第三方包缓存
        vendor: {
          test: /[\\/]node_modules[\\/]/, // 匹配 node_modules
          filename: '[id]_vendor.js', // 生成 js 文件名
          priority: -10, // 优先级 是的高按照谁的来
        },
        // 打包本地 js
        bar: {
          test: /bar_/, // 匹配文件以 bar_ 开头的js，打包成 下面的文件
          filename: '[id]_bar.js',
          priority: -10, // 优先级 是的高按照谁的来
        },
        // 配置打包
        default: {
          minChunks: 2, // 如果 一个文件 被引入两次，就打包到 common.js 里面
          filename: 'common.js',
          priority: -30, // 优先级 是的高按照谁的来
        },
      },
    },
  },

```



### 服务器 [DevServer](https://webpack.docschina.org/configuration/dev-server/)

```js
  // 给 webpack-dev-server 配置 生产环境下
  devServer: {
    hot: true, // 开启 HRM 热更新
    // publicPath: 'abc/', // 指定本地服务所在的文件夹，查看网页 要去 端口+ abc/ , 要和上面output的对应
    host: '0.0.0.0',
    port: 8888,
    open: true, // 开启服务自动打开浏览器
    compress: true, // 启动 gz  ip 压缩
    // 代理服务器
    proxy: {
      '/api': {
        target: 'http://localhost:8080',
        pathRewrite: { '^/api': '' },
        changeOrigin: true,
        // 默认不接受在 HTTPS 上运行且证书无效的后端服务器
        secure: false, // 不进行验证
      },
    },
    historyApiFallback: true, // 返回 404 返回index页面，配置了就可以使用 history路由模式了。可以有对象配置，对应跳转
  },
```



### 性能提示 [Performance](https://webpack.docschina.org/configuration/performance/)

```js
  performance: {
    // 入口起点的最大体积，这个参数代表入口加载时候最大体积，将其改为了1M，
    maxEntrypointSize: 1000000,
    // 此选项根据单个资源体积，控制 webpack 何时生成性能提示，自己将其改成了1M
    maxAssetSize: 1000000,
    // 属性允许 webpack 控制用于计算性能提示的文件，通过覆盖原有属性，将其改成只对js文件进行性能测试。
    assetFilter: function (assetFilename) {
      return assetFilename.endsWith(".js");
    },
  },
```



### 模块(解析文件) [Module](https://webpack.docschina.org/configuration/module/)

```js
  module: {
  resolveLoader: {
    modules: ['node_modules', './my-loader'], // 配置查找 loader 的文件夹
  },
    rules: [
      {
        test: /\.vue$/,
        use: [
          {
            loader: "vue-loader",
          },
        ],
        enforce: "pre", // 可以让 loader 放在最前面执行，忽略从右到左的顺序
      },
      {
        test: /\.ts/,
        // use: [{ loader: 'ts-loader' }],
        exclude: /node_modules/,
        use: [{ loader: "babel-loader" }, { loader: "eslint-loader" }],
      },
      {
        test: /\.js$/,
        // test: /\.jsx?$/, // react 的时候用
        exclude: /node_modules/,
        use: [
          {
            loader: "babel-loader", // 去 babel.config.js
            options: {
              // presets: ['@babel/preset-env'], //  .browserslistrc  来生成
              //  这种方式也行
              // presets: [
              //   [
              //     '@babel/preset-env',
              //     {
              //       targets: {
              //         // The % refers to the global coverage of users from browserslist
              //         browsers: ['>0.25%', 'not ie 11', 'not op_mini all'],
              //       },
              //     }
              //   ],
              // ],
              // plugins: [
              //   '@babel/plugin-transform-arrow-functions',
              //   '@babel/plugin-transform-block-scoping',
              // ],
            },
          },
          { loader: "eslint-loader" },
        ],
      },
      {
        test: /\.css$/,
        // loader: 'css-loader',
        sideEffects: true,
        use: [
          // 顺序从后往前
          {
            loader: "style-loader",
          },
          {
            // loader: miniCssExtractPlugin.loader, // 开启他就替代 style-loader
            // loader: 生产环境 ？ miniCssExtractPlugin.loader ： style-loader
          },
          {
            loader: "css-loader",
            options: {
              importLoaders: 1, // 碰到引入 重新从后一个开始 解析
              url: true,
            }, // 参数
          },
          {
              //  postcss的插件 css兼容性处理 在postcss.config.js 处理
            loader: "postcss-loader",  
          },
        ],
      },
      {
        test: /\.less$/,
        rules: [
          {
            loader: "style-loader",
          },
          {
            loader: "css-loader",

            options: { importLoaders: 2 }, // 参数
          },
          {
            loader: "less-loader",
          },
          {
            loader: "postcss-loader",
          },
        ],
      },
      {
        test: /\.(png|jpe?g|gif|svg)$/i,
        type: "asset",
        parser: {
          dataUrlCondition: {
            maxSize: 50 * 1024, // 4kb // 超过这个 转成 asset/inline type
          },
        },
        generator: {
          filename: "img/[name].[hash:6][ext]", // 文件很大，就放到 img 下 , 转成 asset/resource type
        },
        // dependency: { not: ['url'] },

        // use: [
        //   {
        //     loader: 'url-loader',
        //     options: {
        //       limit: 9000,
        //       esModule: false,
        //     },
        //   },
        // ],
      },
    ],
  },
```



### 插件 [Plugins](https://webpack.docschina.org/configuration/plugins/)

```js
// 打包前删除 dist 目标文件夹
const { CleanWebpackPlugin } = require("clean-webpack-plugin");

// 创建 html 模板
const HtmlWebpackPlugin = require("html-webpack-plugin");

// 用来添加全局变量的， process.env
const { DefinePlugin } = require("webpack");

// 复制 public 的文件到 dist 目标文件夹
const CopyWebpackPlugin = require("copy-webpack-plugin");
const { webpack } = require("webpack");

// 把css打包到一个单独的文件, 需要再 rule 也配置一下
const miniCssExtractPlugin = require("mini-css-extract-plugin");

// css 摇树优化
const { PurgeCSSPlugin } = require("purgecss-webpack-plugin");
const glob = require("glob");

// 生产下 开启 gizp
const CompressionPlugin = require("compression-webpack-plugin"); 

plugins: [
    new CleanWebpackPlugin(),
    new HtmlWebpackPlugin({
      title: "hello world",
      // template: './index.html', // 根据这个生成
      inject: true, // 打包的 js css 给注入进去，默认 true,
      cache: true, // 当文件没有发生改变就不重新打包
      minify: {
        removeComments: false, // 是否删除注释
        removeRedundantAttributes: true, // 是否移除多余属性
        removeEmptyAttributes: true, // 是否移除 空属性
        collapseWhitespace: false, // 是否删除空格
        minifyCSS: true, //是否对 css 进行压缩 在html文件中的 js 和 css
        minifyJS: true, // 是否对 js 进行压缩, 还有详细配置 丑化
      },
    }),
    new DefinePlugin({
      BASE_URL: '"./"', // 因为取值是  BASE_URL = ./  所以加上 ”“
    }),
    new CopyWebpackPlugin({
      // 匹配的文件
      patterns: [
        {
          from: "public", // 从这文件夹，到 dist
          to: "dist",
          // 配置
          globOptions: {
            //忽略的文件
            ignore: [],
          },
        },
      ],
    }),
    // 当代码中找不到某一个变量可以自动引入。 不建议使用
    new webpack.ProvidePlugin({
      axios: "axios", // key 变量名， value 库名
    }),
    new miniCssExtractPlugin({
      filename: "css/[name].[hash:4].css",
    }),
    new PurgeCSSPlugin({
      //检查那个文件夹下 的所有文件
      paths: glob.sync(`${path.resolve(__dirname, "src")}/**/*`, {
        nodir: true,
      }),
      safelist: function () {
        return {
          standard: ["body", "html"], // 那些标签是安全的，不要删除的
        };
      },
    }),
    new CompressionPlugin({
      threshold: 0, // 当文件小于 多少进行压缩
      test: /\.(css|js)$/, // 只有 css 和 js 时开始压缩
      minRatio: 0.8, // 压缩比例达到 多少的时候进行压缩， 默认 0.8
      algorithm: "gzip", // 压缩算法
    }),
  ],
```

#### webpack-bundle-analyzer 分析 webpack 打包占用大小，可视化生成的！

#### webpack-merge 合并 webpack 配置



### 魔法注释

1. '[name].js' // 这个 name 可以使用魔法注释动态生成，魔法注释：/* webpackChunkName: "liu" */

2. 也可以在 添加一个 魔法注释：/* webpackPrefetch:true */  等到其他文件加载完，就回加载他，到代码执行的时候点击就会走 缓存

3. 在父级加载的时候并行一起加载 /* webpackPreload:true */

4. 例：import(/* webpackChunkName: "liu" */ /* webpackPrefetch:true */ "./index");

   

### 自定义 plugin

##### 使用

```js
  // webpack.config.js
const LiuPlugin = require('./my-plugins/liu-plugin');
 {
   plugins: [
      new LiuPlugin({
        name: 'liu',
        age: 19,
      }),
    ],
 }
```

##### 创建

```js
// my-plugins/liu-plugin.js

const { resolve } = require('path');

class AutoUploadPlugin {
  constructor(options) {
    this.options = options;
  }
  // 创建 apply 声明周期会调用这个函数
  apply(compiler) {
    // 来订阅一个函数，等待合适的时机触发
    compiler.hooks.afterEmit.tapAsync(
      'AutoUploadPlugin',
      (compilation, callback) => {
        console.log('输出 dit 目录之后执行');
        console.log('传入的参数', this.options);

        // 执行完操作 调用 回调
        callback();
      }
    );

    //  可以注册多个 hook 来操作
    compiler.hooks.emit.tapAsync('My-plugin', (compilation, callback) => {
      console.log('输出 dit 目录之前执行');
      console.log('传入的参数', this.options);

      // compilation 实例能够访问所有的模块和它们的依赖。
      compilation.hooks.assetPath.tap('My-plugin', (path, options) => {
        console.log(path, options, '调用以决定 dist 的路径');
        const pathName = resolve(__dirname, '../dist2');
        return pathName;
      });

      callback();
    });
  }
}

module.exports = AutoUploadPlugin;
```





### 自定义 loader

##### 使用

```js
 // webpack.config.js
{
  context: path.resolve(__dirname, '.'),
  // ...
    module: {
    rules: [
      {
        test: /.js$/i,
        // 相对路径，相对于 context
        // use: './my-loader/liu-loader.js',
        use: [
          {
            loader: 'liu-loader', // 可以简写成这样，要在下面配置 resolveLoader
            options: {
              name: 'liu',
              age: '23',
            },
          },
        ],
      },
    ],
  },
  resolveLoader: {
    modules: ['node_modules', './my-loader'], // 配置查找 loader 的文件夹
  },
}
```

##### 同步 laoder

```js
// ./my-loader/liu-loader.js

// content:内容，
module.exports = function (content, sourcemap, meta) {
  // 打印所有js 文件内容，+ 自定义loader
  console.log(content, '自定义loader');

  // 返回一个 js 格式的字符串 ： 使用 heml-loader
  // 例： const inner = "`"+ str+ "`";const content = `var code=${inner};export default code;` return content
  return content;  
  // or this.callback(null/* (错误) */,content,sourcemap,meta)
};
```

##### 异步loader

```js
// 异步  loader
module.exports = function (content, sourcemap, meta) {
  // 打印所有js 文件内容，+ 自定义loader
  console.log(content, '自定义loader');

  // 获取传入参数
  console.log(this.getOptions(), '传入参数');
  
  // 实现异步
  const callback = this.async();

  setTimeout(() => {
    callback(null /* (错误) */, content, sourcemap, meta);
  }, 2000);
};
```

##### 校验options  https://github.com/webpack/schema-utils

```js
const { validate } = require('schema-utils');  
const schema = require('./liu-loader-schema.json');

// content:内容，
module.exports = function (content, sourcemap, meta) {
  // 打印所有js 文件内容，+ 自定义loader
  console.log(content, '自定义loader');
  // 获取传入参数
  const options = this.getOptions();

  // 校验
  validate(schema, options, {
    name: 'liu loader',
    baseDataPath: 'options',
  });
  
  return content;
  // or this.callback(null/* (错误) */,content,sourcemap,meta)
};


// ./liu-loader-schema.json
{
  "type": "object",
  "properties": {
    "name": {
      "type": "string",
      "desctiption": "请输入你的名字"
    },
    "age": {
      "type": "number",
      "desctiption": "请输入你的年龄"
    }
  }
}
```

