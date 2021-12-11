# GitHub 密码换成 token

### 生成自己的 token

1. #### 在`个人设置页面`，找到`Setting`

2. ![image-20210816234252720](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20210816234252720.png)

3. #### 选择开发者设置`Developer setting`

4. ![image-20210816234555578](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20210816234555578.png)

5. 选择个人访问令牌`Personal access tokens`，然后选中生成令牌`Generate new token`

6. ![image-20210816234646717](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20210816234646717.png)![image-20210816234700947](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20210816234700947.png)

7. 然后生成一个新的令牌，并保存下来

8. 用令牌登录

9. > ```shell
   > git remote set-url origin https://<your_token>@github.com/<USERNAME>/<REPO>.git
   > ```
   >
   > - `<your_token>`：换成你自己得到的`token`
   > - `<USERNAME>`：是你自己`github`的`用户名`
   > - `<REPO>`：是你的`仓库名称`

10. ```shell
    #实例
    git remote set-url origin  https://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@github.com/2531800823/BigEvent.git
    ```

11. 用小乌龟 把 url ： https://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@github.com/2531800823/BigEvent.git

12. 令牌到期就更新一下 重来

13. > 最近一次的令牌
    >
    > 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   
    >
    > 

## 生成 ssh key

1. ```shell
   ssh-keygen -t rsa -b 4096 -C "2531800823@qq.com"
   ```

2. > 找到路径下的文件   id_rsa   id_esa.pub
   >
   > C:\Users\86183\.ssh   

3. > 复制id_rsa.puh 内容
   >
   > 登录GitHub，头像   Settings -》 SSH and GPG Keys  -》 New SSH key
   >
   > 粘贴进去

4. 检查是否配置成功

5. ```shell
    ssh -T git@github.com  #检查是否成功
   ```

   