//ROOM: /d/yanziwu/tingxiang.c

inherit ROOM;

void create()
{
	set("short", "聽香水榭");
	set("long",@LONG
綠柳杏花叢中有八九間茅房，四周竹籬掩映，錯落有致，這就是慕
容公子的婢女阿朱的住所了。
LONG );
	set("exits", ([
		"west" : __DIR__"biheqiao",
//		"south" : __DIR__"shuiyun",
	]));
	set("outdoors", "yanziwu");
	set("objects", ([
		__DIR__"obj/hualu1" : 1,
		__DIR__"obj/hualu2" : 1,
		__DIR__"obj/hualu3" : 1,
	]));
	set("coor/x", 860);
	set("coor/y", -1530);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
