//tianweitang.c
inherit ROOM;

void create()
{
	set("short", "天市堂");
	set("long", @LONG
你一進入明教的天市堂，頓時感到一股肅殺之氣。教眾出入都十分小
心，惟恐驚動了坐在油木桌後的堂主李天垣。見你進來李天垣抬眼看了看
你，一張很柔和的臉卻立馬讓你心驚肉跳。
LONG );
	set("exits", ([
		"west"  : __DIR__"tianweitang",
	]));
	set("objects",([
		__DIR__"npc/litianyuan":1,
		__DIR__"npc/yinwulu":1,
	]));
	set("coor/x", -52020);
	set("coor/y", 1040);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}