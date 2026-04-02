// Room: /d/taohua/neishi2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "掃葉廊");
	set("long", @LONG
黃島主臥室外的掃葉廊由青竹搭就，房裏收拾得十分清雅。靠北窗
子透進一些些桃花的香味，以及一點點海水的清新腥味。窗下一張大竹
桌上放着幾本翻着一半的書，上面盡是一些奇怪的符號，你看不懂。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"woshi2",
		"west"  : __DIR__"chufang",
		"south" : __DIR__"neishi1",
	]));
	set("outdoors","taohua");
	set("coor/x", 9000);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}