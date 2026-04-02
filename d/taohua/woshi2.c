// Room: /d/taohua/woshi2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "清音居");
	set("long", @LONG
這間佈置得很整齊的臥室是桃花島主黃藥師的居所。屋子正中放着
一座古琴，樣式很是古老。東邊的書架上密密層層的線裝古籍，一塵不
染。朝南窗外露着兩枝桃花，給屋子添了幾許韻味。窗下小竹几上擺着
一副棋局，黑白分明。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"neishi2",
	]));
	set("coor/x", 9010);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}