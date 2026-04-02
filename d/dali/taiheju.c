//Room: /d/dali/taiheju.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","太和居");
	set("long",@LONG
這是大理城內最大的酒樓，樓下賣些大理的小喫，過往行人
常常買來作路菜。樓上是雅座。
LONG);
	set("objects", ([
	   __DIR__"npc/xiaoer2": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "west"  : __DIR__"center",
	    "up"    : __DIR__"taiheju2",
	]));
	set("coor/x", -39990);
	set("coor/y", -71020);
	set("coor/z", 0);
	setup();
}