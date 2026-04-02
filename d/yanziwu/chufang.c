//Room /d/yanziwu/chufang.c
inherit ROOM;
void create()
{
	set("short","廚房");
	set("long",@LONG
這是間寬敞的廚房，廚師們在展示各自的烹飪絕活。整個房間瀰漫
着令人垂涎欲滴的菜香。
LONG );
	set("exits",([
		"north" : __DIR__"xiaoting",
	]));
	set("objects",([
		__DIR__"npc/nanpu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1510);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}