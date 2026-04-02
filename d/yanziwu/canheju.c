//ROOM: /d/yanziwu/canheju.c

inherit ROOM;

void create()
{
	set("short", "參合居");
	set("long",@LONG
這是慕容世家首腦人物日常起居之地，佈置得華麗中不乏清雅，平
實中透着高貴。楠木方桌，大太師椅，以及牆上的字畫都透着一股非凡
之氣。
LONG  );
	set("exits", ([
		"west" : __DIR__"qiushuan",
		"east" : __DIR__"zuijing",
		"north": __DIR__"yimen",
		"south": __DIR__"shuwu",
	]));
	set("objects", ([
		CLASS_D("murong")+"/first" : 1,
	]));
	set("coor/x", 820);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}