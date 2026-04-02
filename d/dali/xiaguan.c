//Room: /d/dali/xiaguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","下關城");
	set("long",@LONG
下關城，又名龍尾城，為閣羅鳳所築，唐代已極繁榮。城區縈抱
蒼山南麓數裏，洱水繞城南而過，端的風景如畫。此去南邊不遠即是
大理城，東面有太和城，另有道路通向西北。此附近居民以烏夷、臺
夷為主，也有少量擺夷。
LONG);
	set("objects", ([
	   __DIR__"npc/tshangfan": 1,
	   __DIR__"npc/wshangfan": 1,
	]));
	set("outdoors", "dalin");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"cangshan",
	    "northwest"  : __DIR__"cangshanzhong",
	    "south"      : __DIR__"ershuiqiao",
	]));
	set("coor/x", -41000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}