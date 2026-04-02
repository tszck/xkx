// /kaifeng/tangjian.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "堂間");
	set("long", @LONG
一間四方的堂間，正中的供桌後還擺着尊殘缺的佛像，由於缺了半
個腦袋，加上半身被蜘蛛網罩住了，也看不出原來的模樣。一邊的柱子
旁打了個地鋪，靠牆擺着幾個水罐。
LONG);
	set("objects", ([
		__DIR__"npc/oldseng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"kongdi",
	]));

	setup();
	replace_program(ROOM);
}
