# Jest 安装配置

## 安装

```shell
 # 安装依赖
 npm i -D jest
 #使用 ts 
 npm i @types/jest -D
 npm i @babel/preset-typescript -D
# 安装 Jest 后，用 jest-cli 初始化 jest 配置文件
npx jest --init
```

![image-20220730215547937](C:\Users\liu\AppData\Roaming\Typora\typora-user-images\image-20220730215547937.png)

![image-20220730230149581](C:\Users\liu\AppData\Roaming\Typora\typora-user-images\image-20220730230149581.png)

#### 生成 **jest.config.js** 配置文件

```js
// jest.config.js
  // 配置 浏览器的 API
  testEnvironment: "jest-environment-jsdom-global",
  // 注意，这里 ts-jest 一定要和 jest 的大版本一致！ 比如 27 对 27，或者 26 对 26，否则会有兼容问题！
  // 配置 module 引入方式
  preset: "ts-jest",
  // 自动清除 Mock
  clearMocks: true,
  // 使用的引擎
  coverageProvider: "v8",
  // 需要在所有测试环境中可用的一组全局变量
  globals: {
    "ts-jest": {
      // 指定ts config文件
      tsconfig: "./tsconfig.json",
      // 使用esm而非commonjs 使用 import
      useESM: true,
    },
  },
  // 模块使用的N个文件扩展名数组
  moduleFileExtensions: [
    "js",
    "mjs",
    "cjs",
    "jsx",
    "ts",
    "tsx",
    "json",
    "node",
  ],
  // 项目别名
  moduleDirectories: ["node_modules", "src"],
  moduleNameMapper: {
    "@/(.*)": "<rootDir>/src/$1",
  },
      
      
// tsconfig.json
"compilerOptions": {
    "types": ["node", "jest"],
    "baseUrl": "./",
    "paths": {
      "utils/*": ["src/utils/*"]，
      "@/*": ["src/*"],
    }
  }
```

### 安装 jest-cli 

```
npm i jest-cli
```

#### 自动执行测试

package.json 中 增加 `--watchAll`后缀

```shell
jest --watch # 默认执行 jest -o 监视有改动的测试
jest --watchAll # 监视所有测试
```

```json
// package.json
"scripts": {
    "test": "set NODE_OPTIONS=--experimental-vm-modules && jest  --watch",
    "testAll": "set NODE_OPTIONS=--experimental-vm-modules && jest  --watchAll"
  },
```



### 测试环境

#### 对浏览器 存储 localStorage的操作 的测试

##### 添加utils文件

```ts
// src/utils/storage.ts , 我们只对 localStorage 进行封装，一共有 set 和 get 两个函数
const KEY_NAME = "my-app-";

const set = (key: string, value: string) => {
  localStorage.setItem(KEY_NAME + key, value);
};

const get = (key: string) => {
  return localStorage.getItem(KEY_NAME + key);
};

const storage = {
  get,
  set,
};

export default storage;
```

##### 测试文件  Error  --  node 环境下没有 localStorage ，下面 mock 一个

```ts
import storage from "@/utils/index";

describe("storage", () => {
  it("可以缓存值", () => {
    storage.set("newKey", "hello");
    expect(localStorage.getItem("my-app-newKey")).toEqual("hello");
  });

  it("可以设置值", () => {
    localStorage.setItem("my-app-newKey", "hello");
    expect(storage.get("newKey")).toEqual("hello");
  });
});
```

安装 浏览器 API

```shell
# 安装
npm install -D jest-environment-jsdom-global jest-environment-jsdom
```

配置文件

```ts
"jest": {
   testEnvironment: "jest-environment-jsdom-global",
}
```



#### 添加 react 测试 

```shell
pnpm add @testing-library/react -D
```



实例

```tsx
// src/component/Head.tsx
export default () => (
  <div>
    Head Component
  </div>
)

// src/component/Head.spec.tsx
import { render } from '@testing-library/react';
import Head from './Head';

it('test Head Component', () => {
  // 获取渲染结果，将本次渲染结果与快照进行对比测试
  const { asFragment } = render(<Head />);
  // 会将组件 UI 与快照进行对比（第一次的话会创建快照），如果不一致则会报错
  expect(asFragment()).toMatchSnapshot();
});
```

