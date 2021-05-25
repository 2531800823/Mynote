# Linux面试

**查看指定文件/指定大小	du [. 全部]【指定文件名】【-a+h 明细+详情】**

**查看Linux CPU内存**

1. top	可以 选中那个（PID） shirt+M 排序
2. cat  /proc/cpuinfo
3. 可以安装  dstat 命令

**查看内存信息**

1. cat  /proc/meminfo
2. free 
   1.  -k  以Kb显示  
   2. -M  M显示
   3. -g G 显示
   4. -h  完整内存信息

**查看系统版本**

1. uname
   1. -r  版本号
   2. -a 详细信息
2. cat /etc/redhat-release   centOS下用  查看是centOS几

**查看网络相关的链接信息**

1. netstat
   1. -anp
      1. a 所有选项
      2. n拒绝显示别名 尽可能转换成 数字
      3. p 吧程序名 显示出来
2. 可以用 | 查询 端口是否别占用
   1. netstat -anp | grep 22

**文件打印去重**

1. uniq
   1. uniq 文件名
      1. -c 可以显示在文件中出现了几次
      2. -u 显示只出现1行的







### **文件权限**  -u 文件所有者 -g同组 -o其他用户

​	**查看文件的默认创建权限掩码**

1. umask
   1. -S 查看具体文件对应信息

**修改文件权限**

1. chomd 
   1. chomd g+r 文件名  给文件所属组+权限
   2. chomd g-r 文件名 是减权限
   3. chomd 777 文件  直接用进制修改

**修改文件所有者在root下** 

1. chown  
   1. chown 用户 文件
2. chgrp  修改文件所属组
   1. chgrp 用户组 文件

  

​	



​			

