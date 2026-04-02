// /kaifeng/daoxiang2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "稻香居二樓");
	set("long", @LONG
老大一個大廳內相互間用屏風隔成十多個小間。穿戴厲索的小二端
着菜來往奔走，如果你分量夠的話，還可以撈到個窗邊的位置。邊喝酒
邊看看下面的繁華街景，人生一樂。
LONG);
	set("objects", ([
		__DIR__"npc/gaoyanei" : 1,
		__DIR__"npc/luyuhou" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"daoxiang1",
	]));

	setup();
	replace_program(ROOM);
}
