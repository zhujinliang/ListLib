all :
	cc -c LinkList.c                   #生成.o文件   
	ar cr libmyLinkList.a LinkList.o   #生成静态库文件libmyLinkList.a
clean :
	rm LinkList.o
	rm libmyLinkList.a
