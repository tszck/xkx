//Room: /d/foshan/beidimiao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","北帝廟");
	set("long",@LONG
北帝廟坐北朝南。院子中一個大水塘，塘中石龜石蛇，昂然盤
踞。大殿神像石板上血跡殷然。北帝神像立於大殿正中。
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"street1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1600);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
