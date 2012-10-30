ICTCLAS Nodejs module
=====================

中文分词ICTCLAS包的nodejs封装

Installation
-----------

1.下载ICTCLAS包(http://www.ictclas.org)，解压到代码目录，比如叫ICTCLAS

2.修改binding.gyp文件的libraries，指向ICTCLAS/API/libICTCLAS50.so所在的绝对路径

3.修改binding.gyp文件的include_dirs，指向ICTCLAS/API/ICTCLAS50.h的所在相对路径

4.拷贝ICTCLAS目录内的API/Configure.xml和user.lic到代码目录

5.修改Configure.xml的DataPath，指向API/Data的所在相对目录

6.运行

	node-gyp configure build

注意,python版本必须是2.6+(系统自带的往往都是2.4的)，可使用如下命令指向正确python的路径

	PYTHON=/usr/local/python/bin/python node-gyp configure build

7.测试

	node test.js 明天给宝宝买蛋糕

