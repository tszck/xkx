//Room: /d/dali/chahua10.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花苑");
	set("long",@LONG
大理茶花冠絕天下，鎮南王府的茶花自然更非凡品。這裏是府中
的茶花苑，天下名品畢聚於此，你對着滿苑茶花，心花怒放，看了一
本，喜歡一本，實在不知道哪本茶花更好些。
LONG);
	set("outdoors", "daliwang");
	set("objects", ([
	   __DIR__"obj/chahua2": 1,
	   __DIR__"obj/chahua3": 1,
	   __DIR__"obj/chahua6": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"chahua7",
	]));
	set("coor/x", -38940);
	set("coor/y", -69970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}