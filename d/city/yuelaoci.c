// Room: /yangzhou/yuelaoci.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","月老祠");
	set("long",@LONG
小小的祠廟，香火稀少，坐落在揚州城的北面的角落上。少有人員
來往。偶然有些年輕男女匆匆的進入，喜憂參半的離開。進得廟中，中
間供着和藹可親的月老。月老面前一張供桌，兩塊跪石，簡簡單單的陳
設。
LONG );
	set("exits", ([
		"southwest"  : __DIR__"tianningxiang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 50);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}